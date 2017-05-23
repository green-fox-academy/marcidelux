#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
  int* pointer = NULL;

  // TODO:
  // Please allocate a 5 long array and fill it with numbers from 0 to 4, then print the whole array
  pointer = (int*)calloc(5, sizeof(uint8_t));

  for(int i = 0; i < 5; i++) {
    pointer[i] = i;
  }

  for(int i = 0; i < 5; i++) {
    printf("Number%d: %d\n",(i+1),pointer[i]);
  }

  // Please delete the array before the program exits

  free( pointer );
  return 0;
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