#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int k = 1521;
	// tell if k is dividable by 3 or 5

	if( k % 3 == 0 || k % 5 == 0){
        printf("%d is divadable by 3 or 5",k);
	}
	return 0;
}
