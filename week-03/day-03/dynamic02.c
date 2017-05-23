#include <stdio.h>
#include <stdlib.h>

// TODO:
// Please create a program that asks for a count when it starts.
// It should ask for a number count times, then it shoud print the average of the numbers.
// It should delete any dynamically allocated resource before the program exits.

int main() {
    int  n;
    int *numbers;
    int sum=0;
    float avarage;

    printf("How many numbers do you need?");
    scanf("%d",&n);

    numbers = (int*)calloc(n, sizeof(int));
    printf("Enter %d number:\n",n);

    for(int i=0 ; i < n ; i++ ) {
        scanf("%d",&numbers[i]);
    }

    for(int i=0 ; i < n ; i++ ) {
        sum+=numbers[i];
    }

    avarage =(float)sum/n;
    printf("Avarage of the numbers: %.02f", avarage);

    free( numbers );

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