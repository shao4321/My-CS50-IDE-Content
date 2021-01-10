#include <stdio.h>
#include <string.h>

int main()
{
	char s[100];
	printf("Enter a letter: ");
	scanf("%s", s);

	int q = strlen(s);

	for(int i=q-1; i >= 0; i--)
	printf("%c", s[i]);

	return 0;
}