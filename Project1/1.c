#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void changeJinsu(long long n, long long k, long long A[])
{
	int i = 0, length = 0, temp=0;

	while (n > 0) {
		if (n == 1) {
			 A[i++] = 1;
			break;
		}
		A[i++] = n % k;
		n /= k;
	}
	A[i] = -1;

	for (length = 0; A[length] != -1; length++);

	for (i = 0; i < length / 2; i++) {
		temp = A[i];
		A[i] = A[length - i - 1];
		A[length - i - 1] = temp;
	}
}

int isPalindrome(long long A[])
{
	int length, i;
	for (length = 0; A[length] != -1; length++);

	for (i = 0; i < length; i++)
	{
		if (A[i] != A[length - 1 - i])
			return 0;
	}
	return 1;
}

int main(void)
{
	long long n=0, k=0;
	int i;
	long long A[100000]; //프린트해야하는 배열들
	
	scanf("%lld %lld", &n, &k);
	changeJinsu(n, k, A);

	for (i = 0; A[i] != -1; i++)
		printf("%d ", A[i]);

	printf("\n%d", isPalindrome(A));

	return 0;
}