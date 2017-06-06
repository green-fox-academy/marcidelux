#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#define WIDTH 20
#define HEIGHT 20

void clrscr(); //clear console
void hidecursor();
void print_ui();
void setupGround(); //Setups the playground
void printGround(); //Print the playground
void delay(unsigned int mseconds); //delay
void starting_page();

//Visual
void dead_snakes();
void is_there_more();
void starting_page();

char ground[WIDTH][HEIGHT];
int gaming = 1;

typedef struct{
int x;
int y;
}coordinate;

void UpgradeGround(coordinate *tempsnake, int len_snake); //change ground elements like snake or apple
void MooveSnake(coordinate *tempsnake, int len_snake, int direction); //Snake is moving
coordinate AddCoordinates(coordinate cor1, coordinate cor2); //add coordinates together
coordinate* setup_snake();
void snake_setup (coordinate *tempsnake);
void snake_grow(coordinate *tempsnake);
void put_apple();

coordinate Snake[50];
int Snake_Length;
coordinate memo1;
coordinate apple;
int speed;

int main()
{
    int biggame = 1;
    int direction = 0;
    int another_snake;
    char input;

    char command[255];
    print_ui();
    printf("Your command: ");
    gets(command);
    clrscr();
    hidecursor();
    starting_page();
    delay(2000);

    while(biggame) {
        srand(time(NULL));
        setupGround();
        snake_setup(Snake);
        speed = 120;
        direction = 0;
        //coordinate *tempo = setup_snake();
        while (gaming) {
            srand(time(NULL));
            if (_kbhit() !=0 ){
                input = _getch();
                if (input == 'w' && direction != 2 )
                    direction = 3;
                else if(input == 'a' && direction != 0)
                    direction = 1;
                else if(input == 's' && direction != 3)
                    direction = 2;
                else if(input == 'd' && direction != 1)
                    direction = 0;
                else if (input == 'f')
                    snake_grow(Snake);
            }
            MooveSnake(Snake, Snake_Length, direction);
            UpgradeGround(Snake, Snake_Length);
            printGround();
            delay(speed);
            clrscr();
        }
        clrscr();
        printf("Bad news mr or mrs snake charmer: your %d years old snake died.\nDo you have another baby snake? (1/0)\n", Snake_Length );
        is_there_more();
        scanf("%d", &another_snake);

        if(another_snake == 0)
            biggame = 0;
        else if (another_snake == 1)
            gaming = 1;
            clrscr();

    }
    clrscr();
    printf("\tAll snakes are dead :(\n");
    dead_snakes();
    return 0;
}

// Console functions
void clrscr()
{
    system("@cls||clear");
}

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
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

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
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

void starting_page()
{
    int delay_temp = 80;
    printf(" _____                  _            _____             _ \n"); delay(delay_temp);
    printf("/  ___|                | |          /  ___|           | |\n"); delay(delay_temp);
    printf("\\ `--. _ __   ___  __ _| | ___   _  \\ `--. _ __   __ _| | _____\n"); delay(delay_temp);
    printf(" `--. \\ '_ \\ / _ \\/ _` | |/ / | | |  `--. \\ '_ \\ / _` | |/ / _ \\\n"); delay(delay_temp);
    printf("/\\__/ / | | |  __/ (_| |   <| |_| | /\\__/ / | | | (_| |   <  __/\n"); delay(delay_temp);
    printf("\\____/|_| |_|\\___|\\__,_|_|\\_\\\\__, | \\____/|_| |_|\\__,_|_|\\_\\___|\n"); delay(delay_temp);
    printf("                              __/ |\n"); delay(delay_temp);
    printf("                             |___/ \n"); delay(delay_temp);
    printf("                        _____\n"); delay(delay_temp);
    printf("                    .-'`     '.\n"); delay(delay_temp);
    printf("                 __/  __       \\\n"); delay(delay_temp);
    printf("                /  \\ /  \\       |    ___\n"); delay(delay_temp);
    printf("               | /`\\| /`\\|      | .-'  /^\\/^\\\n"); delay(delay_temp);
    printf("               | \\(/| \\(/|      |/     |) |)|\n"); delay(delay_temp);
    printf("              .-\\__/ \\__/       |      \\_/\\_/__..._\n"); delay(delay_temp);
    printf("      _...---'-.                /   _              '.\n"); delay(delay_temp);
    printf("     /,      ,             \\   '|  `\\                \\\n"); delay(delay_temp);
    printf("    | ))     ))           /`|   \\    `.       /)  /) |\n"); delay(delay_temp);
    printf("    | `      `          .'       |     `-._         /\n"); delay(delay_temp);
    printf("    \\                 .'         |     ,_  `--....-'\n"); delay(delay_temp);
    printf("     `.           __.' ,         |     / /`'''`\n"); delay(delay_temp);
    printf("       `'-.____.-' /  /,         |    / /\n"); delay(delay_temp);
    printf("           `. `-.-` .'  \\        /   / |\n"); delay(delay_temp);
    printf("             `-.__.'|    \\      |   |  |-\n"); delay(delay_temp);
    printf("                _.._|     |     /   |  |  `'.\n"); delay(delay_temp);
    printf("          .-''``    |     |     |   /  |     `-.\n"); delay(delay_temp);
    printf("       .'`         /      /     /  |   |        '.\n"); delay(delay_temp);
    printf("     /`           /      /     |   /   |\\         \\\n"); delay(delay_temp);
    printf("    /            |      |      |   |   /\\          |\n"); delay(delay_temp);
    printf("   ||            |      /      |   /     '.        |\n"); delay(delay_temp);
    printf("   |\\            \\      |      /   |       '.      /\n"); delay(delay_temp);
    printf("   \\ `.           '.    /      |    \\        '---'/\n"); delay(delay_temp);
    printf("    \\  '.           `-./        \\    '.          /\n"); delay(delay_temp);
    printf("     '.  `'.            `-._     '.__  '-._____.'--'''''--.\n"); delay(delay_temp);
    printf("       '-.  `'--._          `.__     `';----`              \\\n"); delay(delay_temp);
    printf("          `-.     `-.          `.\"'```                     ;\n"); delay(delay_temp);
    printf("             `'-..,_ `-.         `'-.                     /\n"); delay(delay_temp);
    printf("                    '.  '.           '.                 .'\n"); delay(delay_temp);
}

// Ground functions
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
    put_apple();
    ground[apple.x][apple.y] = '*';

}

void UpgradeGround(coordinate *tempsnake, int len_snake)
{

    ground[memo1.x][memo1.y] = ' ';
    if (ground[tempsnake -> x][tempsnake -> y] == 'o') {
        ground[tempsnake -> x][tempsnake -> y] = 'X';
        gaming = 0;
        return;
    }

    if (ground[tempsnake -> x][tempsnake -> y] == '+') {
        ground[tempsnake -> x][tempsnake -> y] = 'X';
        gaming = 0;
        return;
    }

    if (ground[tempsnake -> x][tempsnake -> y] == '*') {
        snake_grow(tempsnake);

        int ok = 1;
        while (ok == 1){
            put_apple();
            if(ground[apple.x][apple.y] != 'o' && ground[apple.x][apple.y] != '8') {
                ok = 0;
            }
        }
        ground[apple.x][apple.y] = '*';
       // speed -= 10;
    }


    ground[tempsnake -> x][tempsnake -> y] = '8';

    for (int i = 1; i < len_snake; i++) {
        ground[(tempsnake+i) -> x][(tempsnake+i) -> y] = 'o';
    }
}

// Snake functions
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

    for (int i = 1; i < len_snake; i++) {
        memo2 = *(tempsnake + i);
        *(tempsnake + i) = memo1;
        memo1 = memo2;
    }
}

void snake_setup(coordinate *tempsnake)
{
    for (int i = 0; i < 3; i++) {
        (tempsnake + i)->x = 1;
        (tempsnake + i)->y = 3 - i;
    }

    Snake_Length = 3;
}

coordinate AddCoordinates(coordinate cor1, coordinate cor2)
{
    coordinate temp;
    temp.x = cor1.x + cor2.x;
    temp.y = cor1.y + cor2.y;
    return temp;
}

void snake_grow(coordinate *tempsnake)
{
    Snake_Length++;
    coordinate memo_snake[50];

    memo_snake[0] = memo1;
    for (int i = 1; i < Snake_Length; i++) {
        memo_snake[i].x = (tempsnake + i -1)->x;
        memo_snake[i].y = (tempsnake + i -1)->y;
    }
    tempsnake = memo_snake;
}

void put_apple()
{
        int x;
        x = (rand() % (WIDTH - 2)) + 1;
        int y;
        y = (rand() % (HEIGHT - 2)) + 1;

        apple.x = x;
        apple.y = y;
}

void print_ui()
{
    printf("Todo application\n");
    printf("====================\n");
    printf("-a\tAdds a new task\n");
    printf("-wr\tWrite current todos to file\n");
    printf("-rd\tRead todos froexit(0);m a file\n");
    printf("-l\tLists all the tasks\n");
    printf("-e\tEmpty the list\n");
    printf("-r\tRemoves a task\n");
    printf("-c\tAdd priority to a task\n");
    printf("-pl\tLists all the tasks by priority\n");
    printf("-exit\tExits from Todo\n\n");
}



