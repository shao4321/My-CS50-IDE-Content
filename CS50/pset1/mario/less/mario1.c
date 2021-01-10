#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Enter a Height: \n");

    int n= get_int(0);

    if(n < 1 || n > 8)
    {

    do
    {
        printf("Please enter a value between 1 to 8.\n");
        n= get_int(0);
        if (n >= 1 && n <= 8)
        {
            break;
        }
    } while (n < 1 || n > 8);

    }

    int z = n;

    for(int i = 0; i < n; i++)
    {
        for(int k = z - 1; k > 0; k--)
        {
            printf(" ");
        }
        
        printf("#");
        
        for(int y = 0; y < i; y++)
        {
             printf("#");
        }
        z--;
        printf("\n");
    }
}
