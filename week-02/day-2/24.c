#include <stdio.h>
#include <stdint.h>

int main()
{
	uint8_t i;

	// print the even numbers till 20

	for (i = 0; i < 21; i++) {
        if(i%2==0){
            printf("even number: %d\n",i);
        }
}
	return 0;
}
