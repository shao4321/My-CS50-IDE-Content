#include <stdio.h>

int main(void)
{
    printf("Even numbers between 1 to 50 (inclusive):\n");
    for(int count = 1; count < 51 ; count++)
    {
        if(count % 2 == 0)
        printf("%d, ", count);
    }
    printf("\n");
}