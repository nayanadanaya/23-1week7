#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
static int check = 0;

int sameArr(int items[], int picked[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        if (items[i] != picked[i]+1)
            return 0;

    return 1;
}

void pick(int items[], int n, int picked[], int m, int toPick) {
    int i;
    int lastIndex;
    int smallest;
   

    if (toPick == 0) {
        /*
        for (i = 0; i < m; i++)
            printf("%d", picked[i]);
        printf("\n");
        */
        if (check == 1) {
            //printf("결과입니다");
            for (i = 0; i < m; i++) {
                printf("%d ", picked[i]+1);
            }
            check = -1;
        }
        if (sameArr(items, picked, m) == 1 && check == 0)
            check = 1;

        return;
    }

    lastIndex = m - toPick - 1;

    if (m == toPick)
        smallest = 0;
    else
        smallest = picked[lastIndex] + 1;

    for (i = 0; i < n; i++) {
        int j = 0; int flag = 0;
        for (j = 0; j <= lastIndex; j++)
            if (picked[j] == i) flag = 1;
        if (flag == 1) continue;
        picked[lastIndex + 1] = i;
        pick(items, n, picked, m, toPick - 1);
    }

}

int main(void)
{
    int m, n, i;
    int* picked; //int picked[m]
    int* items;
    //int picked[4];
    scanf("%d", &n);
    m = n;

    items = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
        scanf("%d", &items[i]);

    picked = (int*)malloc(sizeof(int) * m);

    pick(items, n, picked, m, m);
    if (check == 1)
        printf("-1");
    free(picked);
    return 0;
}