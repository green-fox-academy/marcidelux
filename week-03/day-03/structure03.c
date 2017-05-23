#include <stdio.h>


struct RectangularCuboid {
    double a;
    double b;
    double c;
};

double GetSurface (struct RectangularCuboid cubo);
double GetVolume (struct RectangularCuboid cubo);

// TODO:
// Write a function called "GetSurface" that takes a RectangularCuboid
// and returns it's surface

// TODO:
// Write a function called "GetVolume" that takes a RectangularCuboid
// and returns it's volume

int main() {

    struct RectangularCuboid cubo;
    double surface;
    double volume;

    cubo.a = 12.5;
    cubo.b = 65.3;
    cubo.c = 32;

    surface = GetSurface(cubo);
    volume = GetVolume(cubo);

    printf("surface: %.02f\n", surface);
    printf("volume: %.02f\n", volume);

    return 0;
}

double GetSurface (struct RectangularCuboid cubo){
    double surface;
    surface = 2 * ((cubo.a * cubo.b) + (cubo.a * cubo.c) + (cubo.b * cubo.c));
    return surface;
}

double GetVolume (struct RectangularCuboid cubo){
    double volume;
    volume = cubo.a * cubo.b * cubo.c;
    return volume;
}

/*			  !         !          
			 ! !       ! !          
			! . !     ! . !          
			   ^^^^^^^^^ ^            
			 ^             ^          
		   ^  (0)       (0)  ^       
		  ^        ""         ^       
		 ^   ***************    ^     
	   ^   *                 *   ^    
	  ^   *   /\   /\   /\    *    ^   
	 ^   *                     *    ^
	^   *   /\   /\   /\   /\   *    ^
   ^   *                         *    ^
   ^  *                           *   ^
   ^  *                           *   ^
	^ *                           *  ^  
	 ^*                           * ^ 
	  ^ *                        * ^
	  ^  *                      *  ^
/*		^  *       ) (         * ^
