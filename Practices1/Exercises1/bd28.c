#include <stdio.h>

int main(void)
{
    int quantity[5], countp=0, countn=0, totalP = 0, i;
    float averageP;

    for(i=0; i < 5; i++)
    {
        printf("Enter number %d: ", i+1);
        scanf("%d", &quantity[i]);
    }
    for(i=0; i < 5; i++)
    {
        if(quantity[i] > 0)
        {
        totalP += quantity[i];
        countp++;
        }
        else
        countn++;
    }

    averageP = (int)totalP / (int)countp;

    printf("Qty of Positive Numbers: %d\n", countp);
    printf("Average value of the said positive numbers: %.2f\n", averageP);
}