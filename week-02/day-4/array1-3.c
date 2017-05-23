#include <stdio.h>
#include <stdlib.h>

int main()
{
    char my_name_array[] = "My Name";
    printf("Task1:\n");
	//TODO:
    // Print out the array character-by-character
    int to = (sizeof(my_name_array))/(sizeof(my_name_array[0]));
    for(int i=0; i<to; i++){
    printf("%c",my_name_array[i]);
    }
    printf("\n\n");
    //Task 2:
    printf("Task2:\n");
    char char_array[] = {'a', 'b', 'c', 'd'};
    char char_array_the_same[] = "abcd";

	//TODO:
    // Print out the two arrays character-by-character

	//TODO:
    // What is the difference between the arrays?
    int to2 = (sizeof(char_array))/(sizeof(char_array[0]));
    for(int i=0; i<to2; i++){
    printf("%c",char_array[i]);
    }

    printf("\n");
    int to3 = (sizeof(char_array_the_same))/(sizeof(char_array[0]));
    for(int i=0; i<to3; i++){
    printf("%c",char_array_the_same[i]);
    }
    printf("\n\n");
    //Task3:
    printf("Task3:\n");
    int int_array[] = {1, 654, 987, 654, 31};
    float float_array[] = {1.2, 3.14, 1.41, 0.707, 1.73};
	//TODO:
    // Print out the content of the arrays
    printf("3.0 array:\n ");
    int to4 = (sizeof(int_array))/(sizeof(int_array[0]));
    for(int i=0; i<to4; i++){
    printf("%d\n",int_array[i]);
    }

    printf("3.1 array:\n");
    int to5 = (sizeof(float_array))/(sizeof(float_array[0]));
    for(int i=0; i<to5; i++){
    printf("%.2f\n",float_array[i]);
    }

}
