#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>

#define WIDTH 20
#define HEIGHT 20

void clrscr(); //clear console
void setupGround(); //Setups the playground
void printGround(); //Print the playground
void delay(unsigned int mseconds); //delay
void dead_snakes();
void is_there_more();

char ground[WIDTH][HEIGHT];
int gaming = 1;

typedef struct{
int x;
int y;
}coordinate;

void UpgradeGround(coordinate *tempsnake, int len_snake); //change ground elements like snake or apple
void MooveSnake(coordinate *tempsnake, int len_snake, int direction); //Snake is moving
coordinate AddCoordinates(coordinate cor1, coordinate cor2); //add coordinates together

coordinate Snake[];
int Snake_Length = 3;
coordinate memo1;

int main()
{
    int biggame = 1;
    int direction = 0;
    int another_snake;
    char input;

    while(biggame) {
        setupGround();
        coordinate *tempo = setup_snake();
        while (gaming) {
            if (_kbhit() !=0 ){
                input = _getch();
                if (input == 'w'){direction = 3;} else if(input == 'a'){direction = 1;}else if(input == 's'){direction = 2;}else if(input == 'd'){direction = 0;}
            }
            MooveSnake(Snake, Snake_Length, direction);
            UpgradeGround(Snake, Snake_Length);
            printGround();
            delay(150);
            clrscr();
        }
        clrscr();
        printf("Bad news mr or mrs snake charmer: your snake died.\nDo you have another snake? (1/0)\n");
        is_there_more();
        scanf("%d", &another_snake);

        if(another_snake == 0)
            biggame = 0;
        else if (another_snake == 1)
            gaming = 1;


    }
    clrscr();
    printf("\tAll snakes are dead :(\n");
    dead_snakes();
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

void dead_snakes()
{
    printf("                      .-=-.          .--.\n");
    printf("          __        .'     '.       /  X )\n");
    printf("  _     .'  '.     /   .-.   \\     /  .-'\\\n");
    printf(" ( \\   / .-.  \\   /   /   \\   \\   /  /    ^\n");
    printf("  \\ `-` /   \\  `-'   /     \\   `-`  /\n");
    printf("   `-.-`     '.____.'       `.____.'\n");
}

void is_there_more()
{
    printf("        ____\n");
    printf("  _,.-'`_ o `;__,\n");
    printf("   _.-'` '---'  '\n");
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

coordinate* setup_snake()
{
    coordinate *temp_snake = (coordinate*)calloc(3, sizeof(coordinate));

    for (int i = 0; i < 3; i++){
        temp_snake->x = 1;
        temp_snake->y = i + 1;
        temp_snake++;
    }

    return temp_snake;
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void UpgradeGround(coordinate *tempsnake, int len_snake)
{
    ground[memo1.x][memo1.y] = ' ';
    for (int i = 0; i < len_snake; i++) {
        ground[tempsnake -> x][tempsnake -> y] = 'o';
        tempsnake++;
    }
}

void MooveSnake(coordinate *tempsnake, int len_snake, int direction)
{
    coordinate temp;
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























