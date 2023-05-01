#pragma warning(disable : 6031)
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
    int i, j, min, min_idx, max, maxidx;

    for (i = left; i < n - 1; i++) {
        min = A[i];
        min_idx = i;

        for (j = i; j < n; j++) {
            if (min < A[j]) {
                max = A[j];
                maxidx = j;
            }
        }

        A[maxidx] = A[i];
        A[i] = max;
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