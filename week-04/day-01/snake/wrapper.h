/* console_functions.h */
#ifndef __WINAPI_CONSOLE_WRAPPER_H
#define __WINAPI_CONSOLE_WRAPPER_H

void init_console_functions (void);

void gotoxy (int x, int y);

void clrscr (void);

char getch  (void);


#endif /* __WINAPI_CONSOLE_WRAPPER_H */
