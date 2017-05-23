#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
TODO: Implement a function that concatenates 2 strings (dest and source).
The return value should be the concatenated strings.
*/
void SummaString(char *str1, int len_str1, char *str2, char *sumstr, int len_sumstr);
void PrintCharArray(char *str, int length);

int main()
{
    char string1[] = "Alma";
    char string2[] = "fa;";

    int length1 = sizeof(string1)/sizeof(string1[0]);
    int length2 = sizeof(string2)/sizeof(string2[0]);
    int summalength = length1 + length2;

    char sumstring[summalength];

    SummaString(string1, length1, string2, sumstring, summalength);
    PrintCharArray(sumstring, summalength);

    return 0;
}

void SummaString(char *str1, int len_str1, char *str2, char *sumstr, int len_sumstr)
{
    for (int i = 0; i < len_sumstr; i++) {
        if (i < len_str1) {
            sumstr[i] = str1[i];
        } else {
            sumstr[i-1] = str2[i - len_str1];
        }
    }
}

void PrintCharArray(char *str, int length)
{
    for (int i = 0; i < length; i++) {
        printf("%c", str[i]);
    }
}



