#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bubbleSort(int* A, int n)
{
	int i, temp, j;

	for (j = 0; j < n; j++) {
		for (i = 0; i < n - 1; i++) {
			if (A[i] > A[i + 1])
			{
				temp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = temp;
			}
		}
	}

}

int main(void)
{
	srand(time(NULL));
	int n, i;
	int* A;

	scanf("%d", &n);

	A = (int*)malloc(sizeof(int) * n);
	
	for (i = 0; i < n; i++)
		A[i] = rand()%1000;

	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	bubbleSort(A, n);
	
	for (i = 0; i < n; i++)
		printf("%d ", A[i]);

	return 0;
}