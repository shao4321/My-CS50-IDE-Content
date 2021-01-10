#include <stdio.h>

int main(void)
{
    int p, q, r, s;

    do
    {
    printf("Input 4 integers: ");
    scanf("%d %d %d %d", &p , &q, &r, &s);
    } while(r < 0 || s < 0 || (p%2 != 0));

    if(q > r && s > p)
    {
        if((r+s) > (p+q))
        printf("Correct Values\n");
        else
        printf("Wrong Values\n");
    }
    else
    {
    printf("Wrong Values\n");
    }
}
