#include <stdio.h>

int main(void)
{
    char x[10];
    FILE* ptr1 = fopen("file3.txt", "a");

    fputc("hello" , ptr1);

    fclose(ptr1);
}