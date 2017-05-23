#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>


/*
Try to write a console program which is similar to the classic game "snake".
You will need consol related special library functions.
On windows use conio.h
On linux use curses.h
You can use the getch() function to get the code of the button which was pressed
by the user.
At first try to make a snake which goes straight on the screen.
After that try to change the direction of the movement with the arrow keys.
*/
void printScreen();
void delay(unsigned int mseconds);

int x = 0;
int y = 0;


char screen[10][10] = {
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},
};


int main()
{
    char input =  0;
    printScreen();

    while(1){
        if (_kbhit()!=0){
            input = _getch();
            move(input);
            clrscr();
            printScreen();
        }
    }

    return 0;
}

void move(char direction){

    if(direction == 'a') {
        y--;
    }else if(direction == 'd') {
        y++;
    }else if(direction == 'w') {
        x--;
    }else if( direction == 's') {
        x++;
    }

    if ( x < 0) {
        x = 0;
    }
    if (y < 0) {
        y = 0;
    }
    if (x > 9){
        x = 9;
    }
    if (y > 9){
        y = 9;
    }

    screen[x][y] = 'H';

}

void printScreen(){
    for ( int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++){
           printf(" %c ",screen[i][j]);
           if ( j == 9){
            printf("\n");
           }
        }
    }
}

void clrscr()
{
    system("@cls||clear");
}
 /*
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
*/
