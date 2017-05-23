#include <stdio.h>
#include <stdlib.h>

// TODO:
// Please create a program that asks for a count when it starts.
// It should ask for a number count times, then it shoud print the average of the numbers.
// It should delete any dynamically allocated resource before the program exits.

int main()
{
    int howmany;
    double avarage;
    int number;
    int sum;
    printf("How many times do you want to give me some tasty numbers?");
    scanf("%d", &howmany);

    int *pointer = (int*)calloc(howmany, sizeof(int));

    for(int i = 0; i < howmany; i++)  {
        printf("Give me the %d-th number:\n",i);
        scanf("%d", &number);
        sum += number;
    }

    avarage = (double)sum/howmany;

    printf("Avarage: %.02f", avarage);

    return;
}
