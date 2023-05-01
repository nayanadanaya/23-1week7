#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void testPrint(int* a, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void selectionSortNew(int A[], int left, int n)
{
	int i, j, max, max_idx;

	for (i = left; i < n - 1; i++) {
		max = A[left];
		max_idx = left;

		for (j = 1; j < n - i; j++) {
			if (max < A[j]) {
				max = A[j];
				max_idx = j;
			}
		}

		//swap A[max_idx] <-> A[n-1-i]
		A[max_idx] = A[n - 1 - i];
		A[n - 1 - i] = max;
	}
}

int main(void)
{
	int n;
	int a[100];
	int start;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &start);
	selectionSortNew(a, start, n);
	testPrint(a, n);
	return 0;
}