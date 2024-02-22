#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define YEAR 5
#define INITAL_CASH 100

int main(void) {
	int years, rate;	// 键盘输入投资的年份以及利率
	printf("请输入年利率: ");
	scanf("%d", &rate);

	printf("请输入要投资的年份: ");
	scanf("%d", &years);

	// 定义一个数组,用来存储各个利率下投资的余额
	double balances[YEAR];	// 不要忘记此时数组没有初始化,只有随机值

	// 打印表头 也就是图形的第一行
	printf("\nYears");
	for (int i = 0; i < YEAR; i++) {
		// 打印每一列的利率
		printf("%11d%%", (rate + i));
		// 顺便把balances初始化
		balances[i] = INITAL_CASH;
	}	// 此时balances数组的元素全部是初始金额

	// 接下来打印表格的具体内容
	printf("\n");
	// 外层for控制行数,在这里控制打印年份,这里有多少年就有多少年
	for (int i = 1; i <= years; i++) {
		// 打印第一列的数据
		printf("%4d  ", i);

		// 内层for控制列数,也就是给balances数组赋值,并且打印它,RATE_NUMS决定了列数
		for (int j = 0; j < YEAR; j++) {
			// 打印表格中一列列的数据
			// 首先要根据利率来计算第i年的余额,然后还要存到原数组中
			balances[j] += balances[j] * (rate + j) * 0.01;
			printf("%12.2f", balances[j]);
		}

		// 换行
		printf("\n");
	}

	return 0;
}