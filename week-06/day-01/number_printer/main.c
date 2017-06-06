#include <stdio.h>
#include <stdint.h>

void printf_numbers(double from, double to)
{
    if (from > to) {
       printf("error: from is bigger than to!\n");
       return;
    } else if(from == to) {
        printf("error: from is equal to!\n");
        return;
    }

	for (double i = from; i < to; i++)
		printf("%.00f,", i);
}

int main()
{
	printf_numbers(2147483600, 2147484600);
	return 0;
}
