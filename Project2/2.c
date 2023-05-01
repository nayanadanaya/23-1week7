#pragma warning(disable : 6031)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int minusCarryCountR(int n1, int n2, int carry) // 이 함수를 작성하게
{
	int i=0, A[100000], B[100000], sum = 0;
	if (n1 == 0)
		return 0;
	
	while (n1 > 0) {
		A[i++] = n1 % 10;
		n1 /= 10;
	}
	A[i] = -17;
	i = 0;
	while (n2 > 0) {
		B[i++] = n2 % 10;
		n2 /= 10;
	}
	B[i] = -17;

	i = 0;
	while (A[i] != -17) {
		sum = 1;
		if (A[i] < B[i]) {
			if (A[i + sum] > 0) {
				carry++;
				A[i + sum] -= 1;
			}
			else {
				carry++;
				while (A[i + sum] == 0) {
					A[i + sum] = 9;
					carry++;
					sum++;
				}
				A[i + sum] -= 1;
			}
		}
		i++;

	}

	return carry;
}
int main(void)
{
	int num1, num2;
	int carry = 0;
	scanf("%d %d", &num1, &num2);
	printf("%d\n", minusCarryCountR(num1, num2, carry));
	return 0;
}