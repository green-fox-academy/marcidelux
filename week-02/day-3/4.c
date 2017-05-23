#include <stdio.h>

/* Write a non void function which has a paramters (let's say for example x).
The funtion than returns the "xth" fibonaci number.
What the hack is a fibonacci number? Search it on wikipedia!
*/
int fiboNumber(int number);

int main(){
    int number;
    int wich=6;
    number=fiboNumber(wich);
    printf("the %d-th fibonumber is: %d",wich,number);
    return 0;
}

int fiboNumber(int number){
int i;
int tempa=0;
int tempb=1;
int memo;
for(i=1; i < number; i++){
    memo=tempb;
    tempb=tempa+tempb;
    tempa=memo;
}
return tempb;
}

