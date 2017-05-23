#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void palli(char a[]);

char b[255];

int main()
{
    char a[255];
    printf("Give me a word, and I will make a pallindrome from it.\n");
    gets(a);
    palli(a);
    printf("\nHere is the word: %s\n",b);
}

void palli(char a[]){
    int al = strlen(a);
    int i;
    for(i = 0; i<al; i++){
        b[i] = a[i];
    }
    for(int j = 0; j < al; j++){
        b[i+j] = a[al-j-1];
    }
return;
}
