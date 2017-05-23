#include <stdio.h>
#include <stdlib.h>


// TODO:
// Create a function that takes a double array as a parameter, and the length of the array.
// This function should calculate the avarage of the elements.

// TODO:
// Create an other function that takes a double array as a parameter, and the length of the array.
// It calculates how much elements are under the avarage, and returns with that.

// TODO:
// Create an other function that takes a double array as a parameter, and the length of the array.
// It allocates a new array, and loads into it the elements which are under the average.
// It returns a pointer to the new array.
double AvarageDouble(double *a, int len);
int HowManyUnderAvarage(double *a, int len);

int main()
{
    double array1[] = {234.21, 122.43, 345.123, 666.666};
    int length1 = sizeof(array1)/sizeof(array1[0]);

    double avarage = (AvarageDouble(array1, length1));
    printf("Avarage: %.02f\n", avarage);

    int cmtr = HowManyUnderAvarage(array1, length1);
    printf("Under avarage: %d", cmtr);

    return 0;
}

double AvarageDouble(double *a, int len)
{
    double sum = 0;
    for (int i = 0; i < len; i++) {
        sum += a[i];
    }
    return sum/len;
}

int HowManyUnderAvarage(double *a, int len)
{
    double avarage = AvarageDouble(a, len);
    int counter = 0;

    for (int i = 0; i < len; i++) {
        if (a[i] < avarage) {
            counter++;
        }
    }
    return counter;
}


