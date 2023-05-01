#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
static int sum = -1;
static int smallestOne = 100;

int isSequence(int* items, int* a, int size)
{
    int i=0, up = 0, down = 0, ans = -1, small = 0;

    for (i = 0; i < size; i++) 
        if (items[i] != a[i] && items[i] + 1 != a[i] && items[i] - 1 != a[i])
            return 0;
    
    for (i = 0; i < size; i++)
        if (items[i] + 1 == a[i] || items[i] - 1 == a[i])
            small++;

    if (a[0] > a[1])
        down = 1;
    else
        up = 1;
    for (i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
    for (i = 0; i < size - 2; i++) {
        if (down == 1) {
            if (a[i] - a[i + 1] == a[i + 1] - a[i + 2])
                ans = 1;
            else {
                return 0;
            }
        }
        else {
            if (a[i + 1] - a[i] == a[i + 2] - a[i + 1])
                ans = 1;
            else {
                return 0;
            }
        }
    }

    for (i = 0; i < size; i++)
        printf("정답입니다%d ", a[i]);

    if (small < smallestOne)
        smallestOne = small;

    return 1;
}

void pick(int items[], int n, int picked[], int m, int toPick) {
    int i;
    int lastIndex;
    int smallest;

    if (toPick == 0) {
        int* imsi;
        imsi = (int*)malloc(sizeof(int*) * m);
        for (i = 0; i < m; i++) {
            imsi[i] = items[picked[i]];
            //printf("%d ", imsi[i]);
        }
        
        if (isSequence(items, imsi, m) == 1) {
            if (sum == -1)
                sum = 1;
            else
                sum++;
        }

        free(imsi);
        return;
    }

    lastIndex = m - toPick - 1;

    if (m == toPick)
        smallest = 0;
    else
        smallest = picked[lastIndex] + 1;

    for (i = 0; i < n; i++) {
        picked[lastIndex + 1] = i;
        pick(items, n, picked, m, toPick - 1);
    }

}

int main(void)
{
    int imsi[3] = { -1, 0, 1 };
    int* items;
    int m, n, x=0, y=0, i;
    int* picked; //int picked[m]
    //int picked[4];
    scanf("%d", &n);
    m = n;

    picked = (int*)malloc(sizeof(int) * m);
    items = (int*)malloc(sizeof(int) * m * 3);
    for (int i = 0; i < n; i++)
        scanf("%d", &items[i]);
    for (int i = n; i < n * 2; i++)
        items[i] = items[x++]+imsi[0];
    for (int i = n*2; i < n*3; i++)
        items[i] = items[y++] + imsi[2];

    pick(items, n*3, picked, m, m);

    printf("sum:%d", sum);
    if(sum==-1)
        printf("smallest:-1");
    else
        printf("smallest:%d", smallestOne);
    free(picked);
    return 0;
}