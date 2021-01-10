#include <stdio.h>

void findMax(int a, int b, int c);

int main(void)
{
    int num[3];
    for(int i=0; i < 3; i++)
    {
        printf("Input Value %d: ", i+1);
        scanf("%d", &num[i]);
    }
    findMax(num[0], num[1], num[2]);
}

void findMax(int a, int b, int c)
{
    if(a > b)
    {
        if(c < a)
        printf("%d is the largest value.\n", a);
        else
        printf("%d is the largest value.\n", c);
    }
    else
    {
        if(c < b)
        printf("%d is the largest value.\n", b);
        else
        printf("%d is the largest value.\n", c);
    }
}