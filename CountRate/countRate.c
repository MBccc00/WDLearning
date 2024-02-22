#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define YEAR 5
#define INITIAL_CASH 100

void rateCount(int, int);

/**********************************************************************
用户输入初始金额，利率和投资年数，程序将打印一张表格。表格将显示输入的利率以及紧随其后 4 个更高利率下的总金额。程序的会话如下：

Enter initial balance: 100
Enter interest rate: 6
Enter number of years: 5

Years    6%     7%     8%     9%    10%
  1    106.00 107.00 108.00 109.00 110.00
  2    112.36 114.49 116.64 118.81 121.00
  3    119.10 122.50 125.97 129.50 133.10
  4    126.25 131.08 136.05 141.16 146.41
  5    133.82 140.26 146.93 153.86 161.05                                 *
 **********************************************************************/

int main(void) {
	int years, rate;
	printf("Enter interest rate: %d\n", INITIAL_CASH);

	printf("Enter interest rate: \n");
	scanf("%d", &rate);

	printf("Enter number of years:\n ");
	scanf("%d", &years);

	rateCount(rate, years);

	return 0;
}

void rateCount(int rate, int year) {

	printf("\nYears");

	//double balance[YEAR] = { INITIAL_CASH };只有0可以一次性给	全部定义
	double balance[YEAR];
	for (int i = 0;i < YEAR;i++) {
		printf("%11d%% ", rate + i);
		balance[i] =  INITIAL_CASH;
	}
	printf("\n");

	for (int i = 0;i < YEAR;i++) {
		printf("%4d  ", i + 1);

		for (int j = 0;j < YEAR;j++) {
			balance[j] += balance[j] * (rate + j) * 0.01;
			printf("%12.2f", balance[j]);
		}
		printf("\n");

	}

}


//出问题的地方：1.数组整体赋值 2.单个数组变量的赋值
//3.除了定义时，别的时候不要乱带返回类型

