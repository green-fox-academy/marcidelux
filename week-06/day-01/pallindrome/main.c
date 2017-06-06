#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void  palindrome(char *input);

int main()
{
	char input[100];

	printf("please enter a word: \n");
	scanf("%s", input);

	palindrome(input);

	return 0;
}

void  palindrome(char *input)
{
    if (input == NULL) {
        printf("Empty char!\n");
        return;
    }

	printf("%s", input);

	int leng = strlen(input);
	int *pointer = input;

	for (int i = 0; i < strlen(input); i++) {
		pointer = &input[strlen(input) - i - 1];
		printf("%c", *pointer);
	}
}
