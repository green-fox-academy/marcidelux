#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int j1 = 4;
	int j2 = 3;
	// tell if j1 is higher than j2 squared and smaller than j2 cubed
	if(j1 > sqrt(j2) & j1 < pow(j2,2)){
        printf("%d is bigger than %d^(1/2), and %d is smaller than %d^2",j1,j2,j1,j2);
	}
	return 0;
}
