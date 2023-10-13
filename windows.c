asm ".entry"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "call @__init"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
int __getmainargs(int *argc,char ***argv);
asm "@__getmainargs"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "pushq $0"
asm "mov 16(%rbp),%rcx"
asm "mov 24(%rbp),%rdx"
asm "xor %r8d,%r8d"
asm "mov $1,%r9d"
asm "push %r8"
asm "lea 8(%rsp),%r8"
asm "push %r8"
asm "push %r9"
asm "lea 16(%rsp),%r8"
asm "push %r8"
asm "push %rdx"
asm "push %rcx"
asm ".dllcall \"msvcrt.dll\" \"__getmainargs\""
asm "add $48,%rsp"
asm "add $256,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
int _main(int argc,char **argv,void *hInstance);
asm "@_main"
asm "jmp @main"
void exit(int code);
asm "@exit"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "sub $24,%rsp"
asm "push %rcx"
asm ".dllcall \"msvcrt.dll\" \"exit\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
int __init(void)
{
	int argc;
	char **argv;
	if(__getmainargs(&argc,&argv))
	{
		return -1;
	}
	exit(_main(argc,argv,(void *)0x400000));
}
int MessageBoxA(void *hwnd,char *msg,char *title,int style);
asm "@MessageBoxA"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "mov 24(%rbp),%rdx"
asm "mov 32(%rbp),%r8"
asm "mov 40(%rbp),%r9"
asm "push %r9"
asm "push %r8"
asm "push %rdx"
asm "push %rcx"
asm ".dllcall \"user32.dll\" \"MessageBoxA\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
long clock(void);
asm "@clock"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "sub $32,%rsp"
asm ".dllcall \"msvcrt.dll\" \"clock\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
int RegisterClassExA(void *wc);
asm "@RegisterClassExA"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "sub $32,%rsp"
asm ".dllcall \"user32.dll\" \"RegisterClassExA\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
void *LoadIconA(void *hInstance,char *name);
asm "@LoadIconA"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "mov 24(%rbp),%rdx"
asm "sub $32,%rsp"
asm ".dllcall \"user32.dll\" \"LoadIconA\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
void *LoadCursorA(void *hInstance,char *name);
asm "@LoadCursorA"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "mov 24(%rbp),%rdx"
asm "sub $32,%rsp"
asm ".dllcall \"user32.dll\" \"LoadCursorA\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
void *CreateWindowExA(unsigned int exstyle,char *classname,char *windowname,unsigned int style,
		int x,int y,int w,int h,void *parent,void *menu,void *hInstance,void *param);
asm "@CreateWindowExA"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "mov 24(%rbp),%rdx"
asm "mov 32(%rbp),%r8"
asm "mov 40(%rbp),%r9"
asm "pushq 104(%rbp)"
asm "pushq 96(%rbp)"
asm "pushq 88(%rbp)"
asm "pushq 80(%rbp)"
asm "pushq 72(%rbp)"
asm "pushq 64(%rbp)"
asm "pushq 56(%rbp)"
asm "pushq 48(%rbp)"
asm "sub $32,%rsp"
asm ".dllcall \"user32.dll\" \"CreateWindowExA\""
asm "add $96,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
int GetMessageA(void *msg,void *hwnd,unsigned int filtermin,unsigned int filtermax);
asm "@GetMessageA"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "mov 24(%rbp),%rdx"
asm "mov 32(%rbp),%r8"
asm "mov 40(%rbp),%r9"
asm "sub $32,%rsp"
asm ".dllcall \"user32.dll\" \"GetMessageA\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
int TranslateMessage(void *msg);
asm "@TranslateMessage"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "sub $32,%rsp"
asm ".dllcall \"user32.dll\" \"TranslateMessage\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
int DispatchMessageA(void *msg);
asm "@DispatchMessageA"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "sub $32,%rsp"
asm ".dllcall \"user32.dll\" \"DispatchMessageA\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
int DefWindowProcA(void *hwnd,unsigned int message,unsigned int wparam,unsigned int lparam);
asm "@DefWindowProcA"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "mov 24(%rbp),%rdx"
asm "mov 32(%rbp),%r8"
asm "mov 40(%rbp),%r9"
asm "sub $32,%rsp"
asm ".dllcall \"user32.dll\" \"DefWindowProcA\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
void *GetDC(void *hwnd);
asm "@GetDC"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "sub $32,%rsp"
asm ".dllcall \"user32.dll\" \"GetDC\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
void *CreateCompatibleDC(void *dc);
asm "@CreateCompatibleDC"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "sub $32,%rsp"
asm ".dllcall \"gdi32.dll\" \"CreateCompatibleDC\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
void *CreateCompatibleBitmap(void *dc,int cx,int cy);
asm "@CreateCompatibleBitmap"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "mov 24(%rbp),%rdx"
asm "mov 32(%rbp),%r8"
asm "sub $32,%rsp"
asm ".dllcall \"gdi32.dll\" \"CreateCompatibleBitmap\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
void *SelectObject(void *dc,void *obj);
asm "@SelectObject"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "mov 24(%rbp),%rdx"
asm "sub $32,%rsp"
asm ".dllcall \"gdi32.dll\" \"SelectObject\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
void *BitBlt(void *dc,int x,int y,int cx,int cy,void *src,int x0,int y0,int mode);
asm "@BitBlt"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "mov 24(%rbp),%rdx"
asm "mov 32(%rbp),%r8"
asm "mov 40(%rbp),%r9"
asm "sub $8,%rsp"
asm "pushq 80(%rbp)"
asm "pushq 72(%rbp)"
asm "pushq 64(%rbp)"
asm "pushq 56(%rbp)"
asm "pushq 48(%rbp)"
asm "sub $32,%rsp"
asm ".dllcall \"gdi32.dll\" \"BitBlt\""
asm "add $80,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
void *BeginPaint(void *hwnd,void *ps);
asm "@BeginPaint"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "mov 24(%rbp),%rdx"
asm "sub $32,%rsp"
asm ".dllcall \"user32.dll\" \"BeginPaint\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
int EndPaint(void *hwnd,void *ps);
asm "@EndPaint"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "mov 24(%rbp),%rdx"
asm "sub $32,%rsp"
asm ".dllcall \"user32.dll\" \"EndPaint\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
long SetBitmapBits(void *bmp,int cb,void *ptr);
asm "@SetBitmapBits"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "mov 24(%rbp),%rdx"
asm "mov 32(%rbp),%r8"
asm "sub $32,%rsp"
asm ".dllcall \"gdi32.dll\" \"SetBitmapBits\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
void Sleep(int msec);
asm "@Sleep"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "sub $32,%rsp"
asm ".dllcall \"kernel32.dll\" \"Sleep\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
int ReleaseMutex(void *mutex);
asm "@ReleaseMutex"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "sub $32,%rsp"
asm ".dllcall \"kernel32.dll\" \"ReleaseMutex\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
void *malloc(unsigned long size);
asm "@malloc"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "sub $24,%rsp"
asm "push %rcx"
asm ".dllcall \"msvcrt.dll\" \"malloc\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
void free(void *ptr);
asm "@free"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "sub $24,%rsp"
asm "push %rcx"
asm ".dllcall \"msvcrt.dll\" \"free\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
void *fopen(char *name,char *mode);
asm "@fopen"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "mov 24(%rbp),%rdx"
asm "sub $16,%rsp"
asm "push %rdx"
asm "push %rcx"
asm ".dllcall \"msvcrt.dll\" \"fopen\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
int fclose(void *fp);
asm "@fclose"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "sub $24,%rsp"
asm "push %rcx"
asm ".dllcall \"msvcrt.dll\" \"fclose\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
int fread(void *buf,int size,int count,void *fp);
asm "@fread"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "mov 24(%rbp),%rdx"
asm "mov 32(%rbp),%r8"
asm "mov 40(%rbp),%r9"
asm "push %r9"
asm "push %r8"
asm "push %rdx"
asm "push %rcx"
asm ".dllcall \"msvcrt.dll\" \"fread\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
int fwrite(void *buf,int size,int count,void *fp);
asm "@fwrite"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "mov 24(%rbp),%rdx"
asm "mov 32(%rbp),%r8"
asm "mov 40(%rbp),%r9"
asm "push %r9"
asm "push %r8"
asm "push %rdx"
asm "push %rcx"
asm ".dllcall \"msvcrt.dll\" \"fwrite\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
long OpenClipboard(void *handle);
asm "@OpenClipboard"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "sub $32,%rsp"
asm ".dllcall \"user32.dll\" \"OpenClipboard\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
long CloseClipboard(void);
asm "@CloseClipboard"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "sub $32,%rsp"
asm ".dllcall \"user32.dll\" \"CloseClipboard\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
long EmptyClipboard(void);
asm "@EmptyClipboard"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "sub $32,%rsp"
asm ".dllcall \"user32.dll\" \"EmptyClipboard\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
void *SetClipboardData(unsigned int format,void *hmem);
asm "@SetClipboardData"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "mov 24(%rbp),%rdx"
asm "sub $32,%rsp"
asm ".dllcall \"user32.dll\" \"SetClipboardData\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
void *GetClipboardData(unsigned int format);
asm "@GetClipboardData"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "sub $32,%rsp"
asm ".dllcall \"user32.dll\" \"GetClipboardData\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
void *GlobalAlloc(unsigned int flags,unsigned long size);
asm "@GlobalAlloc"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "mov 24(%rbp),%rdx"
asm "sub $32,%rsp"
asm ".dllcall \"kernel32.dll\" \"GlobalAlloc\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
void *GlobalLock(void *handle);
asm "@GlobalLock"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "sub $32,%rsp"
asm ".dllcall \"kernel32.dll\" \"GlobalLock\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
long GlobalUnlock(void *handle);
asm "@GlobalUnlock"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "sub $32,%rsp"
asm ".dllcall \"kernel32.dll\" \"GlobalUnlock\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
long GetWindowRect(void *hwnd,void *ret);
asm "@GetWindowRect"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "mov 24(%rbp),%rdx"
asm "sub $32,%rsp"
asm ".dllcall \"user32.dll\" \"GetWindowRect\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
long DeleteObject(void *obj);
asm "@DeleteObject"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "sub $32,%rsp"
asm ".dllcall \"gdi32.dll\" \"DeleteObject\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"
long DeleteDC(void *dc);
asm "@DeleteDC"
asm "push %rbp"
asm "mov %rsp,%rbp"
asm "and $0xf0,%spl"
asm "push %r8"
asm "push %r9"
asm "push %r10"
asm "push %r11"
asm "mov 16(%rbp),%rcx"
asm "sub $32,%rsp"
asm ".dllcall \"gdi32.dll\" \"DeleteDC\""
asm "add $32,%rsp"
asm "pop %r11"
asm "pop %r10"
asm "pop %r9"
asm "pop %r8"
asm "mov %rbp,%rsp"
asm "pop %rbp"
asm "ret"