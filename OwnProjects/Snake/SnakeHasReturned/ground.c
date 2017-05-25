#include "ground.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void setupGround(ground *temp_ground)
{
    for ( int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++){
            if (i == 0 || j == 0 || i == WIDTH-1 || j == HEIGHT-1 ) {
                temp_ground->playground
                ground[i][j] = '+';
            } else{
                ground[i][j] = ' ';
            }
        }
    }

}
