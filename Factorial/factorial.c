#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int factorial_recursive(int n);
int factorial_loop(int n);

/**********************************************************************
分别用循环和递归方式求解 n 的阶乘 n!。
f(n) = 1,          if n = 0
f(n) = n * f(n-1), if n > 0
 **********************************************************************/

int main(void) {
	printf("enter the num:");
	int num;
	scanf("%d", &num);

	int i= factorial_recursive(num);
	printf("using recursive way,the result is %d.\n", i);

	int j = factorial_loop(num);
	printf("using loop way,the result is %d.\n", i);
	

	return 0;
}

int factorial_recursive(int n) {
	if (n == 0) return 1;
	
	return n * factorial_recursive(n - 1);
}

int factorial_loop(int n) {
	int res = 1;
	for (int i = 0;i <= n;i++) {
		res *= n;
	}

	return res;
}