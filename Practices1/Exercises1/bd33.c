#include <stdio.h>

int main(void)
{
    int n, i, highestVal, j=0;
    
    printf("Input quantity of values: ");
    scanf("%d", &n);
    
    int A[n];
    
    for(i = 0; i < n; i++)
    {
        printf("Input value %d: ", i+1);
        scanf("%d", &A[i]);
    }
    
    for(i = 1; i < n; i++)
    {
        int k = i - 1;
        
        if(A[i] < A[k])
        {
            highestVal = A[k];
            j = k + 1;
        }
        else if(A[k] > A[i])
        {
            highestVal = A[i];
            j = i + 1;
        }
    }
        printf("Highest value: %d\n", highestVal);
        printf("Position of Highest value: %d\n", j);
}