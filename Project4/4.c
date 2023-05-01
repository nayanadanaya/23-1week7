#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int sum = 0;

int isSequence(int* a, int size)
{
	int i, up = 0, down = 0, ans = -1;
	if (a[0] > a[1])
		down = 1;
	else
		up = 1;

	for (i = 0; i < size - 2; i++) {
		if (down == 1) {
			if (a[i] - a[i + 1] == a[i + 1] - a[i + 2])
				ans = 1;
			else {
				return 0;
			}
		}
		else {
			if (a[i+1] - a[i] == a[i+2] - a[i + 1])
				ans = 1;
			else {
				return 0;
			}
		}
	}

	return 1;
}

int pick(int items[], int n, int picked[], int m, int toPick, int num1[], int num2[]) {
	int i;
	int lastIndex;
	int smallest;

	if (toPick == 0) {
		for (i = 0; i < m-2; i++) {
			if (picked[i] != num1[i] && picked[i] != num1[i - 1] && picked[i] != num1[i + 1])
				return;
		}

		if (isSequence(picked,m) == 1)
			sum++;

		return;
	}

	lastIndex = m - toPick - 1;

	if (m == toPick)
		smallest = picked[0];
	else
		smallest = picked[lastIndex] + 1;

	for (i = smallest; i < n; i++) {
		picked[lastIndex + 1] = i;
		pick(items, n, picked, m, toPick - 1,num1,num2);
	}
	return sum;
}

int main(void) // 이 main 함수를 그대로 사용해도 좋고, 변경하여도 좋다
{
	int items[3] = { -1, 0, 1 };
	int n;
	int* bucket;
	int* num1;
	int* num2;
	//printf("개수 입력");
	scanf("%d", &n);
	bucket = (int*)malloc(sizeof(int) * n);
	num1 = (int*)malloc(sizeof(int) * n);
	num2 = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num1[i]);
	printf("%d\n", pick(items, 3, bucket, n, n, num1, num2));
}