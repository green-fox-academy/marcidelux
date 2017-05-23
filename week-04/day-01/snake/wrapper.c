
/* console_functions.c */
#include "ConsoleFunctions.h"
#include <windows.h>

static HANDLE hStdout;
static HANDLE hStdin;
static CONSOLE_SCREEN_BUFFER_INFO csbi;
static const COORD startCoords = {0,0};


void init_console_functions (void)
{
  hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  hStdin = GetStdHandle(STD_INPUT_HANDLE);

  GetConsoleScreenBufferInfo(hStdout, &csbi);
}

void gotoxy(int x, int y)
{
  COORD coord;

  coord.X = x;
  coord.Y = y;

  SetConsoleCursorPosition(hStdout,coord);
}


void clrscr(void)
{
  DWORD dummy;

  FillConsoleOutputCharacter(hStdout,
                             ' ',
                             csbi.dwSize.X * csbi.dwSize.Y,
                             startCoords,
                             &dummy);
  gotoxy(0,0);
}


char getch(void)
{
  INPUT_RECORD inp_rec;
  DWORD        bytes_read;
  BOOL         success;

  do
  {
    success = PeekConsoleInput(hStdin, &inp_rec, 1, &bytes_read);
    FlushConsoleInputBuffer(hStdin);
  } while(!success || inp_rec.EventType != KEY_EVENT || bytes_read==0);

  return (char)inp_rec.Event.KeyEvent.uChar.AsciiChar;
}
