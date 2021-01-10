#include <stdio.h>

void swap(char* a, char* b);

int main(void)
{
    char word[3] = { 'X', 'M', 'L' };
    char* wordorig = "XML";

    swap(&word[0], &word[2]);

    printf("The reverse of %s is %c%c%c\n", wordorig, word[0], word[1], word[2]);
}

void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}