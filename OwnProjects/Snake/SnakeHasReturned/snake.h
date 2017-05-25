#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

typedef struct{
    int x;
    int y;
}Snake_Part;

typedef struct{
    Snake_Part *part_of_snake;
    unsigned int snake_length;
}Snake;

void Snake_init(Snake *temp_snake);
void Snake_Growing(Snake *temp_snake, int x, int y);
void print_snake(Snake *temp_snake);


#endif // SNAKE_H_INCLUDED
