#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define WIDTH 30
#define HEIGHT 20

void clrscr(); //clear console
void setupGround(); //Setups the playground
void printGround(); //Print the playground
void delay(unsigned int mseconds); //delay

char ground[WIDTH][HEIGHT];
int gaming = 1;

typedef struct{
int x;
int y;
}coordinate;

void UpgradeGround(coordinate *tempsnake, int len_snake); //change ground elements like snake or apple
void MooveSnake(coordinate *tempsnake, int len_snake, int direction); //Snake is moving
coordinate AddCoordinates(coordinate cor1, coordinate cor2); //add coordinates together

coordinate Snake[] = {{2,5},{2,4},{2,3}};
int Snake_Length = sizeof(Snake)/sizeof(Snake[0]);

int main()
{
    int direction = 0;
    char input;
    setupGround();

    while (gaming) {
        if (_kbhit() !=0 ){
            input = _getch();
            if (input == 'w'){direction = 3;} else if(input == 'a'){direction = 1;}else if(input == 's'){direction = 2;}else if(input == 'd'){direction = 0;}
        }
        MooveSnake(Snake, Snake_Length, direction);
        UpgradeGround(Snake, Snake_Length);
        printGround();
        delay(180);
        clrscr();
    }
    return 0;
}

void clrscr()
{
    system("@cls||clear");
}

void printGround()
{
    for ( int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++){
           printf(" %c ", ground[i][j]);
           if ( j == HEIGHT-1){
            printf("\n");
           }
        }
    }
}

void setupGround()
{
    for ( int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++){
            if (i == 0 || j == 0 || i == WIDTH-1 || j == HEIGHT-1 ) {
                ground[i][j] = '+';
            } else{
                ground[i][j] = ' ';
            }
        }
    }

}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void UpgradeGround(coordinate *tempsnake, int len_snake)
{
    for (int i = 0; i < len_snake; i++) {
        ground[tempsnake -> x][tempsnake -> y] = 'o';
        tempsnake++;
    }

}

void MooveSnake(coordinate *tempsnake, int len_snake, int direction)
{
    coordinate temp;
    coordinate memo1;
    coordinate memo2;

    switch (direction) {

        case 0 :
            temp.x = 0;
            temp.y = 1;
            break;
        case 1 :
            temp.x = 0;
            temp.y = -1;
            break;
        case 2 :
            temp.x = 1;
            temp.y = 0;
            break;
        case 3 :
            temp.x = -1;
            temp.y = 0;
            break;
    }

    memo1 = *tempsnake;
    *tempsnake = AddCoordinates(*tempsnake, temp);
    if (ground[tempsnake -> x][tempsnake -> y] == '+') {
        gaming = 0;
        return;
    }

    for (int i = 1; i < len_snake; i++) {
        memo2 = *(tempsnake + i);
        *(tempsnake + i) = memo1;
        memo1 = memo2;
    }
}

coordinate AddCoordinates(coordinate cor1, coordinate cor2)
{
    coordinate temp;
    temp.x = cor1.x + cor2.x;
    temp.y = cor1.y + cor2.y;
    return temp;
}


