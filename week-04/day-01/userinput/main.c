#include <stdio.h>
#include <stdlib.h>

/*
Create a program which ask for a name and an age.
From the age it tells the user when he or she will be 100 years old.
You should only take care of the years (don't bother with the months or days).
*/
void when_will_be_old_as_duck (int age, int currentyear);

int main()
{
    char name[50];
    int age;
    int currentyear = 2017;

    printf("Give me a name:\n");
    gets(name);
    printf("How old are you?\n");
    scanf("%d", &age);

    when_will_be_old_as_duck(age, currentyear);

    return 0;
}

void when_will_be_old_as_duck (int age, int currentyear){
    int time = currentyear + 100 - age;
    printf("You will be old as a duck at year: %d\n", time);
}
