#include <stdio.h>
#include <stdlib.h>
/*
Create a program which writes down the following sentence 100 times:
"I won't cheat on the test!"
Do it with:
    - for loop
    - while loop
    - do while loop
Also create a funtion which does the same.
*/
void IhaveNeverCheatedOnTests_For (int times);
void IhaveNeverCheatedOnTests_While (int times);
void IhaveNeverCheatedOnTests_DoWhile (int times);



int main()
{
    int times = 100;
    IhaveNeverCheatedOnTests_For(times);
    IhaveNeverCheatedOnTests_While(times);
    IhaveNeverCheatedOnTests_DoWhile(times);
    return 0;
}

void IhaveNeverCheatedOnTests_For (int times)
{
   printf("For:\n");
    for(int i = 0; i < times; i++) {
        printf("I have never cheated on tests!\n");
    }
}

void IhaveNeverCheatedOnTests_While (int times)
{
    printf("While:\n");
    int i = 0;
    while(i < times) {
        printf("I have never cheated on tests!\n");
        i++;
    }
}

void IhaveNeverCheatedOnTests_DoWhile (int times)
{
    printf("While:\n");
    int i = 0;
    do {
        printf("I have never cheated on tests!\n");
        i++;
    } while (i < times);
}

