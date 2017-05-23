#include <stdio.h>
#include <stdlib.h>
#include <string.h>
<<<<<<< HEAD

int main()
{
    int boolean;
=======
int boolean=1;
int main()
{
>>>>>>> c2b6b9c5a9b90646b24d71b6741a866d50ffded8
    char a[255];
    char b[255];

    printf("First word: \n");
    gets(a);
    printf("Second word: \n");
    gets(b);
<<<<<<< HEAD

    anagram(a,b);

=======
    anagram(a,b);
        int lb = strlen(b);
    for(int i=0; i<lb; i++){
        if(b[i]!='0'){
            boolean = 0;
        }
    }
    if(boolean==1){
        printf("COOL STORY BRO\n");
    }else{
        printf("NOT COOL\n");
    }
>>>>>>> c2b6b9c5a9b90646b24d71b6741a866d50ffded8
    return 0;
}

void anagram (char a[], char b[]){
<<<<<<< HEAD
    char memo[1];
=======
>>>>>>> c2b6b9c5a9b90646b24d71b6741a866d50ffded8
    int la = strlen(a);
    int lb = strlen(b);

if (la!=lb){
    printf("First word's length: %d\n",la);
    printf("First word's length: %d\n",lb);
<<<<<<< HEAD
    printf("One of the word is longer than the other!");
    return;
    }

for(int i=0; i<la; i++){
    for(int j=0; j<lb; j++){
            if(a[i]==b[j]){

                printf("First words %d-th character is same as Second words %d-th character\n",i,j);
            }
    }
}
=======
    printf("One of the word is longer than the other!\n");
    return 0;
    }

    for(int i=0; i<la; i++){
    for(int j=0; j<lb; j++){
            if(a[i]==b[j]){
                //printf("First words %d-th character is same as Second words %d-th character\n",i,j);
                b[j]='0';
            }
    }

}

>>>>>>> c2b6b9c5a9b90646b24d71b6741a866d50ffded8
return;
}


