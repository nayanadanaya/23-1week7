#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //rand() || srand() : seed값
#include <time.h> //현재 시간 얻어오는

void insertionSort(int* A, int n)
{
	int i, j, k, temp;

	for (i = 1; i < n; i++) {
		for (j = 0; j < i; j++)
			if (A[j] > A[i]) break;

		temp = A[i];
		for (k = i; k > j; k--)
			A[k] = A[k - 1];
		A[j] = temp;
	}

}
int main(void)
{
	int n, i;
	int *A;

	scanf("%d", &n);
	if (n <= 0)
		return 0;

	A = (int*)malloc(sizeof(int) * n); //A를 배열?
	if (A == NULL)
		return 0;

	srand(time(NULL)); //SEED는 최초의 위치
	for (i = 0; i < n; i++)
		A[i] = rand()%1000;

	insertionSort(A, n);

	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	free(A);
	return 0;
}