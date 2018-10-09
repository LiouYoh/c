#include <windows.h>

#define TC_BLACK 	0
#define TC_RED		1
#define TC_GREEN	2
#define TC_YELLOW	3
#define TC_BLUE     4
#define TC_MAGENTA	5
#define TC_CYAN		6
#define	TC_WHITE	7

#define TC_NONE     NULL
#define TC_BG_INTENSIFY BACKGROUND_INTENSITY
#define TC_FG_INTENSIFY FOREGROUND_INTENSITY
#define TC_FGBG_INTENSIFY (FOREGROUND_INTENSITY | BACKGROUND_INTENSITY)

void clrscr(void);
void textcolor(int attr, int fg, int bg);
void gotoxy(int xpos, int ypos);
void showCursor(int);
