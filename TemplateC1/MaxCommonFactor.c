
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int EuclideanMaxCommon(numer,denomi);

/*
写一个程序，实现分数相加。用户以分子/分母的形式输入分数，程序打印相加后的结果(化为最简分数)。如：

输入:
Enter first fraction: 5/6
Enter second fraction: 3/4
输出：
The sum is 19/12
*/

int main(void) {
	int numerator1, denominator1, numerator2, denomirator2;//依照格式输入两个分数
	printf("Enter first fraction:");
	scanf("%d/%d", &numerator1, &denominator1);
	printf("Enter second fraction:");
	scanf("%d/%d", &numerator2, &denomirator2);

	int numer, denomi;

	numer = numerator1 * denomirator2 + numerator2 * denomirator2;//不约分时进行加和后的分子分母
	denomi = denominator1 * denomirator2;

	int MaxCommon = 0;
	MaxCommon = EuclideanMaxCommon(numer, denomi);//欧几里得法计算最大公约数

	printf("The sum is %d/%d", numer / MaxCommon, denomi / MaxCommon);

}


int EuclideanMaxCommon(numer, denomi) {
	int remainder = 0;
	while (denomi > 0) {//类似七巧板不停分割的思想
		if (numer % denomi == 0) break;//余数为0跳出循环，已找到最大公约数
		else {
			remainder = numer % denomi;
			numer = denomi;
			denomi = remainder;
		}
	}
	return remainder;
}

