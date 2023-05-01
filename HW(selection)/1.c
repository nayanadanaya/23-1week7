#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student {
	int id;
	int korean, english, math;
};

void selectionSort(struct Student* A, int n) {
	int i, j, min_idx;
	struct Student min;

	for (i = 0; i < n - 1; i++) {
		min = A[0];
		min_idx = 0;
		for (j = 1; j < n - i ; j++) {
			if (min.korean > A[j].korean) {
				min_idx = j;
				min = A[j];
			}
		}

		A[min_idx] = A[n - i - 1];
		A[n - i - 1] = min;
	}
}

int main(void)
{
	int n, i;
	struct Student* A;

	scanf("%d", &n);
	if (n < 1)
		return 0;

	A = (struct Student*)malloc(sizeof(struct Student) * n);
	if (A == NULL)
		return 0;

	srand(time(NULL));
	for (i = 0; i < n; i++) {
		A[i].id = i + 1;
		A[i].math = rand() % 101;
		A[i].english = rand() % 101;
		A[i].korean = rand() % 101;
	}

	for (i = 0; i < n; i++)
		printf("%d\t%d\t%d\t%d\n", A[i].id, A[i].korean, A[i].english, A[i].math);
	printf("-------------------\n");

	selectionSort(A, n);

	for (i = 0; i < n; i++)
		printf("%d\t%d\t%d\t%d\n", A[i].id, A[i].korean, A[i].english, A[i].math);

	free(A);
	return 0;
}