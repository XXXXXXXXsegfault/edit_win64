int paint;
int mode,prev_mode;
int if_selected(unsigned long off)
{
	unsigned long off1,off2;
	off1=select_pos.off;
	off2=current_pos.off;
	if(off1>off2)
	{
		if(off>=off2&&off<=off1)
		{
			return 1;
		}
	}
	else
	{
		if(off>=off1&&off<=off2)
		{
			return 1;
		}
	}
	return 0;
}
void p_text(void)
{
	struct file_pos pos;
	int x,y,x1,y1;
	int c;
	if(CW>0&&CH>0)
	{
		memcpy(&pos,&view_pos,sizeof(pos));
		y=0;
		x=0;
		while(y<CH)
		{
			c=file_getc(&pos);
			if(c==-1)
			{
				break;
			}
			x1=(x-current_x)*8;
			y1=y*16;
			if(mode==2&&if_selected(pos.off))
			{
				rect(pbuf,WINW,WINH,x1,y1,8,16,0x0060ff);
			}
			if(pos.off==current_pos.off&&!current_pos_end)
			{
				rect(pbuf,WINW,WINH,x1,y1,8,14,0xffa000);
			}
			if(c=='\t')
			{
				if(x>=current_x&&x<current_x+CW)
				{
					rect(pbuf,WINW,WINH,x1,y1,7,16,0xc0c0c0);
				}
				++x;
			}
			else if(c=='\n')
			{
				x=0;
				++y;
			}
			else if(c<32||c>126)
			{
				if(x>=current_x&&x<current_x+CW)
				{
					p_char('\?',x1,y1,0x40ff,pbuf,WINW,WINH);
				}
				++x;
			}
			else
			{
				if(x>=current_x&&x<current_x+CW)
				{
					p_char(c,x1,y1,0x0,pbuf,WINW,WINH);
				}
				++x;
			}
			if(pos.off==current_pos.off&&!current_pos_end)
			{
				rect(pbuf,WINW,WINH,x1,y1+14,8,2,0x4040);
			}
			if(!file_pos_move_right(&pos))
			{
				break;
			}
		}
		x1=(x-current_x)*8;
		y1=y*16;
		if(pos.off==current_pos.off&&current_pos_end)
		{
			rect(pbuf,WINW,WINH,x1,y1,8,14,0xffa000);
			rect(pbuf,WINW,WINH,x1,y1+14,8,2,0x4040);
		}
	}
	rect(pbuf,WINW,WINH,0,WINH-16,WINW,16,0xb0b0b0);
	if(mode==1)
	{
		p_str("Insert",6,0,WINH-16,0x0,pbuf,WINW,WINH);
	}
	else if(mode==2)
	{
		p_str("Select",6,0,WINH-16,0x0,pbuf,WINW,WINH);
	}
	else if(mode==3)
	{
		p_char('>',0,WINH-16,0xc0,pbuf,WINW,WINH);
		p_str(cmd,strlen(cmd),8,WINH-16,0x0,pbuf,WINW,WINH);
	}
}
void paint_all(void)
{
	if(pbuf==NULL)
	{
		return;
	}
	rect(pbuf,WINW,WINH,0,0,WINW,WINH,0xe0e0e0);
	p_text();
	SetBitmapBits(bmp,WINW*WINH*4,pbuf);
	BitBlt(dc,0,0,WINW,WINH,memdc,0,0,SRCCOPY);
}

int _WndProc(void *); // NOTE: SCC uses a different calling convention
asm "@_WndProc"
asm "push %r9"
asm "push %r8"
asm "push %rdx"
asm "push %rcx"
asm "call @WndProc"
asm "add $32,%rsp"
asm "ret"
int WndProc(void *hwnd,unsigned int Message,unsigned long wParam,unsigned long lParam)
{
	if(Message==WM_DESTROY)
	{
		exit(0);
	}
	if(Message==WM_ERASEBKGND)
	{
		int rect[4];
		dc=GetDC(hwnd);
		DeleteObject(bmp);
		bmp=NULL;
		DeleteDC(memdc);
		memdc=NULL;
		free(pbuf);
		memset(rect,0,sizeof(rect));
		GetWindowRect(hwnd,rect);
		WINW=rect[2]-rect[0]-16;
		WINH=rect[3]-rect[1]-39;
		CW=WINW/8;
		CH=(WINH-16)/16;
		pbuf=malloc(WINW*WINH*4);
		if(pbuf!=NULL)
		{
			memdc=CreateCompatibleDC(dc);
			bmp=CreateCompatibleBitmap(dc,WINW,WINH);
			SelectObject(memdc,bmp);
			paint_all();
		}
		return 0;
	}
	else if(Message==WM_PAINT)
	{
		struct paintstruct ps;
		BeginPaint(hwnd,&ps);
		paint_all();
		EndPaint(hwnd,&ps);
	}
	else if(Message==WM_CHAR)
	{
		if(wParam>=32&&wParam<=126||wParam==10||wParam==9||wParam==13)
		{
			if(mode==0)
			{
				if(wParam=='W')
				{
					save_file();
				}
				else if(wParam=='I')
				{
					mode=1;
					paint_all();
				}
				else if(wParam=='S')
				{
					memcpy(&select_pos,&current_pos,sizeof(current_pos));
					mode=2;
					paint_all();
				}
				else if(wParam=='>')
				{
					cmd[0]=0;
					mode=3;
					prev_mode=0;
					paint_all();
				}
				else if(wParam=='P')
				{
					char *clipboard;
					int x,clipboard_size;
					clipboard=get_clipboard();
					if(clipboard!=NULL)
					{
						clipboard_size=strlen(clipboard);
						x=0;
						while(x<clipboard_size)
						{
							if(current_pos_end)
							{
								op_push(clipboard[x],current_pos.off+1);
								addc_end(clipboard[x]);
								current_pos_end=0;
								cursor_right();
							}
							else
							{
								op_push(clipboard[x],current_pos.off);
								addc(clipboard[x]);
							}
							current_x_refine();
							++x;
						}
						free(clipboard);
					}
					paint_all();
				}
				else if(wParam=='U')
				{
					undo();
					paint_all();
				}
				else if(wParam=='R')
				{
					redo();
					paint_all();
				}
				else if(wParam=='f')
				{
					if(search_buf[0])
					{
						search_forward(search_buf);
						paint_all();
					}
				}
				else if(wParam=='F')
				{
					if(search_buf[0])
					{
						search_backward(search_buf);
						paint_all();
					}
				}
			}
			else if(mode==1)
			{
				if(wParam==13)
				{
					c_insert(10);
				}
				else
				{
					c_insert(wParam);
				}
				paint_all();
			}
			else if(mode==2)
			{
				if(wParam=='C')
				{
					copy_selected_str();
					mode=0;
					paint_all();
				}
				else if(wParam=='D')
				{
					copy_selected_str();
					del_selected_str();
					mode=0;
					paint_all();
				}
				else if(wParam=='>')
				{
					cmd[0]=0;
					mode=3;
					prev_mode=2;
					paint_all();
				}
				else if(wParam=='f')
				{
					if(search_buf[0])
					{
						search_forward(search_buf);
						paint_all();
					}
				}
				else if(wParam=='F')
				{
					if(search_buf[0])
					{
						search_backward(search_buf);
						paint_all();
					}
				}
			}
			else if(mode==3)
			{
				if(wParam=='\r')
				{
					issue_command();
					current_x_refine();
					mode=prev_mode;
					cmd[0]=0;
					paint_all();
				}
				else
				{
					int l;
					l=strlen(cmd);
					if(l<47)
					{
						cmd[l]=wParam;
						cmd[l+1]=0;
					}
				}
				paint_all();
			}
		}
	}
	else if(Message==WM_KEYDOWN)
	{
		if(wParam==37)
		{
			cursor_left();
			current_x_refine();
			paint_all();
		}
		else if(wParam==39)
		{
			cursor_right();
			current_x_refine();
			paint_all();
		}
		else if(wParam==38)
		{
			cursor_up();
			current_x_refine();
			paint_all();
		}
		else if(wParam==40)
		{
			cursor_down();
			current_x_refine();
			paint_all();
		}
		else if(wParam==27) // ESC
		{
			mode=0;
			paint_all();
		}
		else if(wParam==8) // BACKSPACE
		{
			if(mode==1)
			{
				c_delete();
				paint_all();
			}
			else if(mode==3)
			{
				int l;
				l=strlen(cmd);
				if(l)
				{
					cmd[l-1]=0;
				}
				paint_all();
			}
		}
	}
	return DefWindowProcA(hwnd,Message,wParam,lParam);
}
