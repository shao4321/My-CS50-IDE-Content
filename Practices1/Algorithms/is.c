#include <stdio.h>
#define N 4

void insertionSort(int A[], int n);

int main(void)
{
    int num[] = { 5, 2, 1, 7 };

    insertionSort(num,N);

    for(int i=0; i < N-1;i++)
    {
        printf("%d, ", num[i]);
    }
    printf("%d.", num[N-1]);
    printf("\n");
}

void insertionSort(int A[], int n)
{
    for(int i=1; i < n-1 ; i++) //scan thru n-1 times starting from the 2nd number
    {
        int temp = A[i]; //assign the ith number to a new variable
        int hole = i; //the ith number will become "empty"
        while(hole > 0 && A[hole-1] > temp) //only 2nd number and onwards might become "empty"
        {
            A[hole] = A[hole-1];
            hole--; //decrement hole by 1 to move back 1 time for assigning the ith number
        }
        A[hole] = temp;
    }
}
