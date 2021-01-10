#include <stdio.h>
#define N 4

void bubbleSort(int A[], int n);

int main(void)
{
    int num[] = { 5, 2, 1, 7 };

    bubbleSort(num,N);

    for(int i=0; i < N-1;i++)
    {
        printf("%d, ", num[i]);
    }
    printf("%d.", num[N-1]);
    printf("\n");
}

void bubbleSort(int A[], int n)
{

    for(int k=0; k < n; k++) //starting from 1st to nth number //moving on to the next number and go through the below 1 to 1 comparison process
        int flag = 0;
        for(int i=1; i < n; i++) //scanning the 1 number to compare with the rest
        {
            if(A[i] < A[i-1]) //comparing the first and second number
            {
                int temp = A[i]; //swap
                A[i] = A[i-1];
                A[i-1] = temp;
                flag = 1;
            }
            if(flag == 0) //break if no more swap for that particular number ->which means this number is sorted
            break;
        }
    }

}




