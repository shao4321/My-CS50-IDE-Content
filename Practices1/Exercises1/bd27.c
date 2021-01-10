#include <stdio.h>

int main(void)
{
    int quantity[5], countp=0, countn=0, i;

    for(i=0; i < 5; i++)
    {
        printf("Enter number %d: ", i+1);
        scanf("%d", &quantity[i]);
    }
    for(i=0; i < 5; i++)
    {
        if(quantity[i] > 0)
        countp++;
        else
        countn++;
    }
    printf("Qty of Positive Numbers: %d\n", countp);
    printf("Qty of Negative Numbers: %d\n", countn);
}