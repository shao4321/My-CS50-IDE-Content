#include <stdio.h>

int main(void)
{
    int x, y, sum, sum3x;
    
    printf("Enter 1st value: ");
    scanf("%d", &x);
    
    printf("Enter 2nd value: ");
    scanf("%d", &y);
    
    if(x == y)
    {
        sum3x = (x + y) * 3;
        printf("%d\n", sum3x);
    }
    else
    {
        sum = x + y;
        printf("%d\n", sum);
    }
}