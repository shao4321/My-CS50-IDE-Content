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

    for(int i = 0; i < n; i++) //loop for rows
    {
        for(int k = z - 1; k > 0; k--) //loop for spaces in nth row
        {
        printf(" ");
        }
        printf("#");

        for(int y = 0; y < i; y++)
        {
            printf("#");
        }
        z--;

        printf("  ");

        for(int q = 0; q <= i; q++)
        {
            printf("#");
        }
        printf("\n");
    }
}

