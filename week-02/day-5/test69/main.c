//Pallinkrok searcher

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pallisearch(char a[]);

char b[255];
int ok=0;

int main()
{
    char a[255];
    printf("Give me some words I will search pallindromes in it.\n");
    gets(a);
    pallisearch(a);
   // printf("\nHere is the word: %d\n",ok);
}

void pallisearch(char a[]){
    int al = strlen(a);
    int ok=1;

        for(int i = 1; i < al; i++){
        int j=1;
        ok=1;
            while(ok){
                if(a[i-j]==a[i+j]){
                        for(int l = -j; l < j+1; l++){
                         printf("%c",a[i+l]);
                        }
                        printf("\t");
                        j++;
                    }else{
                        ok=0;
                        j=1;
                    }
            }
        }


return;
}
