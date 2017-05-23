#include <stdio.h>

/* Write a void function which has two float parameters. The function can do the
totoro operation on those parameters and it also prints out the result of the operation
on the screen.
The totoro operation does the following on two variables (let's say we have "a"
 and "b")
result = a*b+(a+b)+a*a*a+b*b*b+3.14159265358979
*/
void totoroFloat(float a, float b);

int main(){
    float a = 12.4;
    float b = 45.231;
    totoroFloat( a, b );
    return 0;
}

void totoroFloat( float a, float b ){
float resu = a*b+(a+b)+a*a*a+b*b*b+3.14159265358979;
printf("%f\n", resu);
return;
}
