
char cmd[48];
char *clipboard;
long clipboard_size;
void copy_selected_str(void)
{
	unsigned long int end_off;
	struct file_pos pos;
	int c;
	if(select_pos.off<current_pos.off)
	{
		end_off=current_pos.off;
		memcpy(&pos,&select_pos,sizeof(pos));
	}
	else
	{
		end_off=select_pos.off;
		memcpy(&pos,&current_pos,sizeof(pos));
	}
	free(clipboard);
	clipboard_size=0;
	clipboard=malloc(end_off-pos.off);
	if(clipboard==NULL)
	{
		return;
	}
	while(pos.off<=end_off)
	{
		c=file_getc(&pos);
		if(c==-1)
		{
			break;
		}
		clipboard[clipboard_size]=c;
		++clipboard_size;
		if(!file_pos_move_right(&pos))
		{
			break;
		}
	}
}
void del_selected_str(void)
{
	unsigned long int size,x;
	struct file_pos pos;
	int c1;
	if(select_pos.off<current_pos.off)
	{
		size=current_pos.off-select_pos.off+1;
		cursor_right();
		current_x_refine();
	}
	else
	{
		size=select_pos.off-current_pos.off+1;
		x=size;
		while(x)
		{
			cursor_right();
			current_x_refine();
			--x;
		}
	}
	while(size)
	{
		memcpy(&pos,&current_pos,sizeof(pos));
		if(file_pos_move_left(&pos))
		{
			c1=file_getc(&pos);
			op_push(c1|0x100,pos.off);
		}
		delc();
		current_x_refine();
		--size;
	}
}
char *find_buf;
int if_str_match(char *str)
{
	struct file_pos pos;
	int c;
	memcpy(&pos,&current_pos,sizeof(pos));
	while(*str)
	{
		c=file_getc(&pos);
		if(c==-1)
		{
			return 0;
		}
		if(c!=*(unsigned char *)str)
		{
			return 0;
		}
		if(!file_pos_move_right(&pos))
		{
			return 0;
		}
		++str;
	}
	return 1;
}
void search_forward(char *str)
{
	struct file_pos old_pos,old_view_pos;
	int old_end;
	int x;
	x=current_x;
	if(*str==0)
	{
		return;
	}
	memcpy(&old_pos,&current_pos,sizeof(current_pos));
	memcpy(&old_view_pos,&view_pos,sizeof(view_pos));
	old_end=current_pos_end;
	while(cursor_right())
	{
		current_x_refine();
		if(if_str_match(str))
		{
			return;
		}
	}
	memcpy(&current_pos,&old_pos,sizeof(current_pos));
	memcpy(&view_pos,&old_view_pos,sizeof(view_pos));
	current_pos_end=old_end;
	current_x=x;
}
void search_backward(char *str)
{
	struct file_pos old_pos,old_view_pos;
	int old_end;
	int x;
	x=current_x;
	if(*str==0)
	{
		return;
	}
	memcpy(&old_pos,&current_pos,sizeof(current_pos));
	memcpy(&old_view_pos,&view_pos,sizeof(view_pos));
	old_end=current_pos_end;
	while(cursor_left())
	{
		current_x_refine();
		if(if_str_match(str))
		{
			return;
		}
	}
	memcpy(&current_pos,&old_pos,sizeof(current_pos));
	memcpy(&view_pos,&old_view_pos,sizeof(view_pos));
	current_pos_end=old_end;
	current_x=x;
}
char search_buf[64];
void issue_command(void)
{
	long int line;
	line=0;
	if(cmd[0]=='g')
	{
		if(cmd[1]>='0'&&cmd[1]<='9')
		{
			sinputi(cmd+1,&line);
			view_pos.block=file_head;
			view_pos.off=0;
			view_pos.pos=0;
			current_pos.block=file_head;
			current_pos.off=0;
			current_pos.pos=0;
			current_x=0;
			current_pos_end=0;
			while(line>1)
			{
				cursor_down();
				--line;
			}
		}
		else if(cmd[1]=='e')
		{
			current_x=0;
			current_pos_end=0;
			while(cursor_down());
		}
	}
	else if(cmd[0]=='f')
	{
		if(cmd[1])
		{
			strcpy(search_buf,cmd+1);
			search_forward(search_buf);
		}
	}
	else if(cmd[0]=='F')
	{
		if(cmd[1])
		{
			strcpy(search_buf,cmd+1);
			search_backward(search_buf);
		}
	}
}
