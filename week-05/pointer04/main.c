#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Add two numbers using pointers
*/

int main()
{

    int a  = 20;
    int b = 17;
    int *a_p = &a;
    int *b_p = &b;

    int sum = *a_p + *b_p;
    printf("%d + %d = %d ", a, b, sum);

    return 0;
}
