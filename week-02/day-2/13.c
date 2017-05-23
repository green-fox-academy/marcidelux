#include <stdio.h>
#include <stdint.h>

int main()
{
    uint16_t number = 254;
	uint8_t result;

	result = number + 23;
	// Check the result with printf
    printf("%d \n",result);
 	// What happened?!
        // It showed me 21 (when it was uint8)
	// Try again with different datatype
	uint16_t result_16 = number + 23;
	// Check the result with printf
    printf("%d \n",result_16);
	// What happened and why?
        //Its okay now because our number caused owerflow in 8bit but in 16 it didn't cause it
	//----------------------------------------
	int16_t number_negative = number;
	// Check the result with printf
    printf("%d \n",number_negative);
	// What happened and why?
    return 0;
}
