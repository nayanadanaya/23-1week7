#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //rand() || srand() : seed��
#include <time.h> //���� �ð� ������

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

	A = (int*)malloc(sizeof(int) * n); //A�� �迭?
	if (A == NULL)
		return 0;

	srand(time(NULL)); //SEED�� ������ ��ġ
	for (i = 0; i < n; i++)
		A[i] = rand()%1000;

	insertionSort(A, n);

	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	free(A);
	return 0;
}