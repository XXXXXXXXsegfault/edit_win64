#include "windows.c"
#include "windef.c"
#include "mem.c"
#include "iformat.c"
#include "rect.c"
#include "font.c"
int CW,CH,WINW,WINH;
unsigned int *pbuf;
char *file_name;
int current_x;
void *dc,*memdc,*bmp;
void *hwnd_main;

char *get_clipboard(void)
{
	void *clipboard;
	char *clipboard_data,*ret;
	int i;
	char c;
	if(!OpenClipboard(hwnd_main))
	{
		return NULL;
	}
	clipboard=GetClipboardData(1);
	if(clipboard==NULL)
	{
		CloseClipboard();
		return NULL;
	}
	clipboard_data=GlobalLock(clipboard);
	ret=malloc(strlen(clipboard_data+1));
	if(ret==NULL)
	{
		GlobalUnlock(clipboard);
		CloseClipboard();
		return NULL;
	}
	i=0;
	while(c=*clipboard_data)
	{
		if(c>=32&&c<=126||c=='\n'||c=='\t')
		{
			ret[i]=c;
			++i;
		}
		++clipboard_data;
	}
	ret[i]=0;
	GlobalUnlock(clipboard);
	CloseClipboard();
	return ret;
}
void set_clipboard(char *str)
{
	char *hm,*new_str;
	char c;
	if(!OpenClipboard(hwnd_main))
	{
		return;
	}
	EmptyClipboard();
	hm=GlobalAlloc(0x2,strlen(str)*2+2);
	if(hm==NULL)
	{
		CloseClipboard();
		return;
	}
	new_str=GlobalLock(hm);
	while(c=*str)
	{
		if(c>=32&&c<=126||c=='\t')
		{
			*new_str=c;
			++new_str;
		}
		else if(c=='\n')
		{
			new_str[0]='\r';
			new_str[1]='\n';
			new_str+=2;
		}
		++str;
	}
	*new_str=0;
	GlobalUnlock(hm);
	SetClipboardData(1,hm);
	CloseClipboard();
}

#include "file.c"
#include "undo.c"
#include "cmd.c"
#include "main_window.c"
int main(int argc,char **argv,void *hInstance)
{
	int ret;
	char title[280];
	int i;
	SetProcessDPIAware();
	if(argc<2)
	{
		MessageBoxA(NULL,"You need to drag a file onto \"edit.exe\".","Message",0);
		return 1;
	}
	
	CW=100;
	CH=35;
	WINW=CW*8;
	WINH=CH*16+16;
	file_name=argv[1];
	strcpy(title,"Edit - ");
	i=strlen(file_name);
	while(i&&file_name[i-1]!='\\'&&file_name[i-1]!='/')
	{
		--i;
	}
	if(strlen(file_name+i)>255)
	{
		MessageBoxA(NULL,"\"edit.exe\": Cannot open file.","Message",0);
	}
	strcat(title,file_name+i);
	pbuf=malloc(WINW*WINH*4);
	if(pbuf==NULL)
	{
		return 1;
	}
	if(ret=file_load())
	{
		if(ret==2)
		{
			MessageBoxA(NULL,"\"edit.exe\": The file is too large.","Message",0);
		}
		else
		{
			MessageBoxA(NULL,"\"edit.exe\": Cannot open file.","Message",0);
		}
		return 1;
	}
	static struct wndclassex wc;
	void *hwnd;
	struct msg msg;
	wc.hInstance=hInstance;
	wc.cbSize=sizeof(wc);
	wc.lpszClassName="EDIT";
	wc.lpfnWndProc=_WndProc;
	wc.hbrBackground=(void *)8;
	wc.hCursor=LoadCursorA(NULL,IDC_ARROW);
	wc.hIcon=LoadIconA(NULL,IDI_APPLICATION);
	if(!RegisterClassExA(&wc))
	{
		return 0;
	}
	hwnd=CreateWindowExA(WS_EX_WINDOWEDGE,"EDIT",title,WS_VISIBLE|WS_SYSMENU|WS_CAPTION|WS_THICKFRAME,0,0,WINW+16,WINH+46,NULL,NULL,hInstance,NULL);
	if(hwnd==NULL)
	{
		return 0;
	}
	dc=GetDC(hwnd);
	memdc=CreateCompatibleDC(dc);
	bmp=CreateCompatibleBitmap(dc,WINW,WINH);
	SelectObject(memdc,bmp);
	hwnd_main=hwnd;
	while(GetMessageA(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}
	return 1;
}
