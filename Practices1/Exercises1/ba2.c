#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, diff, diff3x;
    
    printf("Enter n value: ");
    scanf("%d", &n);
    
    if(n > 51)
    {
        diff3x = (abs(n-51) * 3);
        printf("%d\n", diff3x);
    }
 
    else if(n < 51)
    {
        diff = abs(n - 51);
        printf("%d\n", diff);
    }
}