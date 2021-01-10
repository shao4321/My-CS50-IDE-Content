#include <stdio.h>


int main(void)
{
    int num[2], multiplierCheck;

    do
    {
    for(int i=0; i < 2; i++)
    {
        printf("Input number %d: ", i+1);
        scanf("%d", &num[i]);
    }
    if(num[1] < num[0])
    printf("1st number should not be greater than the 2nd number!\n");
    } while(num[1] < num[0]);

    multiplierCheck = num[1] % num[0];

    if(multiplierCheck != 0)
    printf("Not Multiplied!\n");
    else
    printf("Multiplied!\n");
}