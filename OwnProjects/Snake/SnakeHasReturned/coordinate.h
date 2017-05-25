#ifndef COORDINATE_H_INCLUDED
#define COORDINATE_H_INCLUDED

typedef struct{
    int x;
    int y;
}coordinate;

coordinate AddCoordinates(coordinate cor1, coordinate cor2);
void CoordinateCpy(coordinate cor1, coordinate cor2);

#endif // COORDINATE_H_INCLUDED
