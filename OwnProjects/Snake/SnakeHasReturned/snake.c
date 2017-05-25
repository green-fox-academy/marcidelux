#include "snake.h"
#include "coordinate.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void Snake_init(Snake *temp_snake)
{
    temp_snake->part_of_snake = NULL;
    temp_snake->snake_length = 0;

    Snake_Growing(temp_snake, 1, 3);
    Snake_Growing(temp_snake, 1, 2);
    Snake_Growing(temp_snake, 1, 1);

}

void Snake_Growing(Snake *temp_snake, int x, int y)
{
    // Allocate new space for a bigger snake
    int new_len = temp_snake -> snake_length + 1;
    temp_snake->part_of_snake = realloc(temp_snake->part_of_snake, sizeof(Snake_Part) * new_len);
    temp_snake->snake_length = new_len;

    // Add new tail to the snake. Im growing Stronk! <- Sad the snake
    temp_snake->part_of_snake[new_len - 1].x = x;
    temp_snake->part_of_snake[new_len - 1].y = y;
}

void Snake_Mooving(Snake *temp_snake, coordinate direction)
{





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

void print_snake(Snake *temp_snake)
{
    if (temp_snake == NULL)
        return;
    for (int i = 0; i < temp_snake->snake_length; i++){
            printf("%d x: %d y: %d\n", i, temp_snake->part_of_snake[i].x, temp_snake->part_of_snake[i].y);
    }

}
