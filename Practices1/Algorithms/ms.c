#include <stdio.h>
#include <stdlib.h>

void merge(int A[], int L, int M, int R);
void mergeSort(int A[], int L, int R);
void printarray(int A[], int size);

int main(void)
{
    int num[] = { 5, 2, 1, 7 };
    int num_size = sizeof(num) / sizeof(num[0]);

    printf("Given Array: \n");

    printarray(num, num_size);


    mergeSort(num, 0, num_size - 1);

    printf("Sorted Array: \n");
    printarray(num, num_size);

    return 0;
}

void merge(int A[], int L, int M, int R)  //mergesort for one cycle (1 parent, 2 kids)
{
    int j,h;
    int n1 = M - L + 1;
    int n2 = R - M;

    int l[n1], r[n2];

    for(j=0; j < n1; j++)
    l[j] = A[L + j];

    for(h=0; h < n2; h++)
    r[h] = A[M + 1 + h];

    int k = L;

    while(j < n1 && h < n2)
    {
        if(l[j] <= r[h])
        {
            A[k] = l[j];
            j++;
        }
        else
        {
            A[k] = r[h];
            h++;
        }
        k++;
    }
    while(j < n1)
    {
        A[k] = l[j];
        j++;
        k++;
    }
    while(h < n2)
    {
        A[k] = r[h];
        h++;
        k++;
    }
}

void mergeSort(int A[], int L, int R)
{
    if(L < R)
    {

    int M = L + (R - L) / 2;

    mergeSort(A, L, M);
    mergeSort(A, M+1, R);

    merge(A, L, M, R);
    }
}

void printarray(int A[], int size)
{
    for(int i=0; i < size; i++)
    printf("%d", A[i]);
    printf("\n");
}

