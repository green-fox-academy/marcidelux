#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    int number = 1234;
    int* number_pointer = &number;

    //Task 1:
    //TODO:
    // print the memory address of the variable
    printf("Task 1:\n");
    printf("number memory adress: %x\n", &number);

    //Task 2:
    //TODO:
    // print the value of number using the "number_pointer"
    printf("Task 2:\n");
    printf("number value with pointer: %d\n", *number_pointer);

    //Task 3:
    //TODO:
    // update the value of number variable to 42 using the "number_pointer"
    printf("Task 3:\n");
    *number_pointer=42;
    printf("changed number with pointer: %d\n", number);

    //Task 4:
    //TODO:
    // The "number_pointer" should point to the first element of the array called "numbers",
    // than please print its value with it.
    printf("Task 4:\n");
    int number4[] = {5, 6, 7, 8, 9};
    int* number_pointer4;
    number_pointer4 = number4;
    printf("numbers[0] value: %d\n", *number_pointer4);

    //Task 5:
    int numbers5[] = {5, 6, 7, 8, 9};
    int* number_pointer5 = &numbers5[0];
    //TODO:
    // The "number_pointer" should point to the third element of the array called "numbers",
    number_pointer5 += 2;
    // than please print its value with it. Solve the problem without reusiong the "&" operator
    // for geting the address of the third eleme
    printf("Task 5:\n");
    printf("numbers[2] value: %d\n", *number_pointer5);

    //Task 6:
    int high_number6 = 6655;
    int low_number6 = 2;
    int* hight_number_pointer6 = &high_number6;
    int* other_high_number_pointer6;
    //TODO:
    // The "other_high_number_pointer" should point to the same memory address
    // without using the "&" operator.
    printf("Task 6:\n");
    other_high_number_pointer6 = hight_number_pointer6;
    printf("other high number value: %d\n",*other_high_number_pointer6);

    //Task 7:
    int high_number7 = 6655;
    int low_number7 = 2;
    int* hight_number_pointer7 = &low_number7;
    int* low_number_pointer7 = &high_number7;
    //TODO:
    // Please fix the problem and swap where the pointers point,
    // without using the "&" operator.
    printf("Task 7:\n");
    int memo7;
    memo7 = hight_number_pointer7;
    hight_number_pointer7 = low_number_pointer7;
    low_number_pointer7 = memo7;
    printf("high number value: %d\n",*hight_number_pointer7);
    printf("low number value: %d\n",*low_number_pointer7);

    //Task8:
    int high_number8 = 2;
    int low_number8 = 6655;
    int* hight_number_pointer8 = &high_number8;
    int* low_number_pointer8 = &low_number8;
    //TODO:
    // Please fix the problem and swap the value of the variables,
    // without using the "high_number" and the "low_number" variables.
    printf("Task 8:\n");
    int memo8;
    memo8 = *hight_number_pointer8;
    *hight_number_pointer8 = *low_number_pointer8;
    *low_number_pointer8 = memo8;
    printf("high number value: %d\n",*hight_number_pointer8);
    printf("low number value: %d\n",*low_number_pointer8);



    return 0;
}
