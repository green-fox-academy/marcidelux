#include "coordinate.h"
#include <stdlib.h>
#include <stdio.h>

coordinate AddCoordinates(coordinate cor1, coordinate cor2)
{
    coordinate temp;
    temp.x = cor1.x + cor2.x;
    temp.y = cor1.y + cor2.y;
    return temp;
}

//cor1 will be the cor2
void CoordinateCpy(coordinate cor1, coordinate cor2)
{
    cor1.x = cor2.x;
    cor1.y = cor2.y;
}
