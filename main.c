#include "windows.c"
#include "windef.c"
#include "mem.c"
#include "iformat.c"
#include "rect.c"
#include "font.c"
#define CW 100
#define CH 35
#define WINW (CW*8)
#define WINH (CH*16+16)
unsigned int *pbuf;
char *file_name;
int current_x;
void *dc,*memdc,*bmp;

#include "file.c"
#include "undo.c"
#include "cmd.c"
#include "main_window.c"
int main(int argc,char **argv,void *hInstance)
{
	if(argc<2)
	{
		MessageBoxA(NULL,"You need to drag a file onto \"edit.exe\".","Message",0);
		return 1;
	}
	file_name=argv[1];
	pbuf=malloc(WINW*WINH*4);
	if(pbuf==NULL)
	{
		return 1;
	}
	if(file_load())
	{
		MessageBoxA(NULL,"\"edit.exe\": Cannot open file.","Message",0);
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
	hwnd=CreateWindowExA(WS_EX_WINDOWEDGE,"EDIT","Edit",WS_VISIBLE|WS_SYSMENU|WS_CAPTION,0,0,WINW+6,WINH+29,NULL,NULL,hInstance,NULL);
	if(hwnd==NULL)
	{
		return 0;
	}
	dc=GetDC(hwnd);
	memdc=CreateCompatibleDC(dc);
	bmp=CreateCompatibleBitmap(dc,WINW,WINH);
	SelectObject(memdc,bmp);
	while(GetMessageA(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}
	return 1;
}
