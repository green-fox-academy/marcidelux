#include <stdio.h>
#include <stdint.h>

int main()
{
	uint8_t z = 100;
	// if z is between 10 and 20 print 'Sweet!'
	// if less than 10 print 'More!',
	// if more than 20 print 'Less!'
	if( z >= 10 && z <= 20){
        printf("Sweet!");
	}else if(z < 10){
        printf("More!");
	}else if(z > 20){
        printf("Less!");
	}else{
        printf("Oh shi.. something went wrong!");
	}

	return 0;
}
