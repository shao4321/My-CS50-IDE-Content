#include <stdio.h>
#define N 6

int main()
{
	//code
	int A[N] = {12, 15, 20, 5, 70, 1};
	int max, max2;

	for(int i = 1; i < N; i++)
	{
	    if(A[i] > A[i-1])
	        max = A[i];
	}
	for(int i = 1; i < N; i++)
	{
	    if(A[i] < max && A[i] > A[i-1])
	        max2 = A[i];
	}
	printf("2nd Largest number: %d\n", max2);
	return 0;
}