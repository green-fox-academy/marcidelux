#include <stdio.h>
#include <stdlib.h>

void safe_union(int *numb1, int len_numb1, int *numb2, int *sumInt, int len_sumInt);

int main(int argc, char** argv)
{
    int a[3] = {1,2,3};
    int b[3] = {4,5,6};
    int c[6];
    safe_union(a,3,b,c,6);
    for (int i = 0; i<6; i++) {
        printf("%d\n", c[i]);
    }
    return 0;
}


void safe_union(int *numb1, int len_numb1, int *numb2, int *sumInt, int len_sumInt)
{
    for (int i = 0; i < len_sumInt; i++) {
        if (i < len_numb1) {
            sumInt[i] = numb1[i];
        } else {
            sumInt[i] = numb2[i - len_numb1];
        }
    }
}
