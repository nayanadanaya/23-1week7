#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

static int yes = 0;

int calculate(int m, int picked[], int answer)
{
    int sum = 0, i, k = 1;

    for (i = 0; i < m; i++)
    {
        if (picked[i] == 0)
            sum += k;
        if (picked[i] == 1)
            sum -= k;
        k++;
    }

    if (sum == answer)
        return 1;
    else
        return 0;
}

void pick(int n, int picked[], int m, int toPick, int answer) {
    int i;
    int lastIndex;
    int smallest;

    if (toPick == 0) {
        if (calculate(m, picked, answer) == 1)
            yes = 1;
        for (i = 0; i < m; i++) {
            printf("%d ", picked[i]);
        }
        printf("\n");
        return;
    }

    lastIndex = m - toPick - 1;

    if (m == toPick)
        smallest = 0;
    else
        smallest = picked[lastIndex] + 1;

    for (i = 0; i < n; i++) {
        picked[lastIndex + 1] = i;
        pick(n, picked, m, toPick - 1, answer);
    }

}

int main(void)
{
    int m, n, answer;
    int* picked; //int picked[m]
    //int picked[4];
    scanf("%d %d", &n, &answer);
    m = n;

    picked = (int*)malloc(sizeof(int) * m);

    pick(2, picked, m, m, answer); 

    if (yes == 1)
        printf("1");
    else
        printf("0");

    free(picked);
    return 0;
}