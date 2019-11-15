#include <stdio.h>

int main()
{
    char amsg[10];
	scanf_s("%s", amsg, sizeof(amsg));
	printf("Input was: %s", amsg);

	return 0;  
}