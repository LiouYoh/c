#include <windows.h>

WORD colorFG[]={
            0,
            FOREGROUND_RED,
            FOREGROUND_GREEN,
            FOREGROUND_RED | FOREGROUND_GREEN,
            FOREGROUND_BLUE,
            FOREGROUND_RED | FOREGROUND_BLUE,
            FOREGROUND_GREEN | FOREGROUND_BLUE,
            FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
        };
        
WORD colorBG[]={
            0,
            BACKGROUND_RED,
            BACKGROUND_GREEN,
            BACKGROUND_RED | BACKGROUND_GREEN,
            BACKGROUND_BLUE,
            BACKGROUND_RED | BACKGROUND_BLUE,
            BACKGROUND_GREEN | BACKGROUND_BLUE,
            BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE
        };           


void textcolor(int attr, int fg, int bg)
{
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), attr | colorFG[fg] | colorBG[bg]);
}

void gotoxy(int xpos, int ypos)
{
  COORD scrn;    

  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

  scrn.X = xpos; scrn.Y = ypos;

  SetConsoleCursorPosition(hOuput,scrn);
}

void clrscr(void)
{
	/*
    CONSOLE_SCREEN_BUFFER_INFO sbinf;
    int size;
    COORD scrn = {0, 0};
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdOut, &sbinf);
    size = (sbinf.srWindow.Right-sbinf.srWindow.Left+1)*
        (sbinf.srWindow.Bottom-sbinf.srWindow.Top+1);
    FillConsoleOutputCharacter(hStdOut, 32, size, scrn, NULL);
    */
    system("cls");
}

void showCursor(int visible)
{
    CONSOLE_CURSOR_INFO ConCurInf;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hStdOut, &ConCurInf);
    ConCurInf.bVisible = visible;
    SetConsoleCursorInfo(hStdOut, &ConCurInf);
}



