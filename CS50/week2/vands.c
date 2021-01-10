#include <stdio.h>
#include <cs50.h>

int increment(int x);

int main(void)
{
    int x = 2;
    int y;
    y = increment(x) + x;
    printf("x is %i, y is %i\n", x , y);
}

int increment(int x)
{
    x = 5;
    x = x + 2;
    return x;
}