#include <stdio.h>

int test(int x);

int main(void)
{
    printf("%d", test(100));
    printf("\n%d", test(200));
    printf("\n%d\n", test(55));
}

int test(int x)
{
    if(x % 10 == 0)
    return 1;

    else
    return 0;
}

