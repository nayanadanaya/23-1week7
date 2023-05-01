#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student {
	int id;
	int korean, english, math;
};

void bubbleSortDescendingByKorean(struct Student* A, int n) {
	int i, j;
	struct Student temp;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - 1 - i; j++)
			if (A[j].korean < A[j + 1].korean) {
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
}

void bubbleSortDescendingByMath(struct Student* A, int n) {
	int i, j;
	struct Student temp;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - 1 - i; j++)
			if (A[j].math < A[j + 1].math) {
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
}

void bubbleSortDescendingByEnglish(struct Student* A, int n) {
	int i, j;
	struct Student temp;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - 1 - i; j++)
			if (A[j].english < A[j + 1].english) {
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
}

void bubbleSortAscendingById(struct Student* A, int n) {
	int i, j;
	struct Student temp;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - 1 - i; j++)
			if (A[j].id > A[j + 1].id) {
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
}

int main(void)
{
	int n, i, choose = -1;
	struct Student* A;

	printf("�л� ���� �Է��ϼ��� : ");
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
		printf("�й� : %d\t���� : %d\t���� : %d\t���� : %d\n", A[i].id, A[i].korean, A[i].english, A[i].math);


	while (choose != 0) {
		printf("\n���� ���� ����(1:����,2:����,3:����,4:id(��������),0:������):");
		scanf("%d", &choose);
		if (choose == 1)
			bubbleSortDescendingByKorean(A, n);
		else if (choose == 2)
			bubbleSortDescendingByEnglish(A, n);
		else if (choose == 3)
			bubbleSortDescendingByMath(A, n);
		else if (choose == 4)
			bubbleSortAscendingById(A, n);
		else if (choose == 0)
			break;
		else
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
		for (i = 0; i < n; i++)
			printf("�й� : %d\t���� : %d\t���� : %d\t���� : %d\n", A[i].id, A[i].korean, A[i].english, A[i].math);

	}
	
	free(A);
	return 0;
}