#include <stdio.h>

int main(void)
{
    int intg;

    printf("Input an integer: ");
    scanf("%d", &intg);

    if(intg < 0 || intg > 80)
    {
        printf("Error!");
    }
    else if(intg >= 1 && intg <= 20)
    {
        printf("Range[0,20]");
    }
    else if(intg >= 21 && intg <= 40)
    {
        printf("Range[21,40]");
    }
    else if(intg >= 41 && intg <= 60)
    {
        printf("Range[41,60]");
    }
    else if(intg >= 61 && intg <= 80)
    {
        printf("Range[61,80]");
    }

    printf("\n");
    return 0;
}