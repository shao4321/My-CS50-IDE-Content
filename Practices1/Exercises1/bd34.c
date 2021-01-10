#include <stdio.h>

int main(void)
{
    int input[2], diff, sumOdd=0;
    
    for(int i=0; i < 2; i++)
    {
    printf("Input number %d: ", i+1);
    scanf("%d", &input[i]);
    }
    
    if(input[0] > input[1])
    return  0;
    
    printf("List of odd numbers:\n");
    
    for(int i = input[0]; i <= input[1]; i++)
    {
        if(i % 2 != 0)
        {
        printf("%d, ", i);
        sumOdd += i;
        }
    }
    printf("\nSum = %d\n", sumOdd);

}