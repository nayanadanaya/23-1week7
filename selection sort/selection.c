#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //rand() || srand() : seed값
#include <time.h> //현재 시간 얻어오는

void selectionsort(int* A, int n)
{
	int i, max_idx, j, max;

	for (i = 0; i < n - 1; i++) {
		max = A[0];
		max_idx = 0;
		for (j = 1; j < n - i ; j++) {
			if (max < A[j]) {
				max_idx = j;
				max = A[j];
				//printf("max_idx %d, max %d\n", max_idx, max);
			}
		}

		A[max_idx] = A[n - 1 - i];
		A[n - 1 - i] = max;
	}

}
int main(void)
{
	int n, i;
	int* A;

	scanf("%d", &n);
	if (n <= 0)
		return 0;

	A = (int*)malloc(sizeof(int) * n); //A를 배열?
	if (A == NULL)
		return 0;

	srand(time(NULL)); //SEED는 최초의 위치
	for (i = 0; i < n; i++)
		A[i] = rand() % 1000;

	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	selectionsort(A, n);

	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	free(A);
	return 0;
}