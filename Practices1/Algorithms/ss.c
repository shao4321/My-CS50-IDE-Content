#include <stdio.h>
//#define N 4

void selectionSort(int A[], int n);

int main(void)
{
    //int num[] = { 3, 2, 4, 7 };
    int N;

    printf("Quantities: ");
    scanf("%d", &N);

    int num[N];

    for(int i=0; i < N; i++)
    {
        printf("Enter number %d: ", i+1);
        scanf("%d", &num[i]);
    }

    selectionSort(num,N);

    for(int i=0; i < N-1;i++)
    {
        printf("%d, ", num[i]);
    }
    printf("%d.", num[N-1]);
    printf("\n");
}

void selectionSort(int A[], int n)
{
    for(int i=0; i < n-1; i++) //scan through n-1 times
    {
        int iMin = i; // finding the min among all the numbers and move it to the left
        for(int j=i+1; j < n; j++) //scan through the rest of the numbers except the first
        {
            if(A[j] < A[iMin]) //comparing each of the numbers with the min number
            iMin = j;
        }
        int temp = A[i]; //swapping of that particular number(that is lower than the previous min) to become the current min
        A[i] = A[iMin];
        A[iMin] = temp;
    }

}