#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

//int countBinaryOne(int num);
//int judgeOpposite(int num1, int num2);
int absoluteValue(int num);

/**********************************************************************
 1.编写一个函数，计算一个整数的二进制表示中1的个数。

2.判断两个整数是否相反符号。比如1和-2就具有相反的符号

3.利用位运算符求一个整数的绝对值
 **********************************************************************/

int main(void) {
	
	int num1;
	scanf("%d", &num1);
	int sum1= countBinaryOne(num1);
	printf("this number'binary expression has %d one");
	

	
	int num2, num3;
	scanf("%d%d", &num2, &num3);
	if (judgeOpposite(num2, num3)) {
		printf("two num have oppsite symbols.");
	 }
	else {
		printf("two num have same symbols.");
	}
	
	
	
	int num4;
	scanf("%d", &num4);
	printf("the num's absolue value is %d", absoluteValue(num4));
	

	return 0;
}

#if 1
int countBinaryOne(int num) {//判断整数二进制表达中1的数目
	int sum = 0;
	while (num!=0) {
		sum += num & 1;//最末位为1时计数
		num >>= 1;
	}
	return sum;
}
#endif

#if 1
int judgeOpposite(int num2, int num3) {//判断两个数符号是否相等

	return 0x1fff&(num2&num3);//直接判断最高位符号
}
#endif

#if 1
int absoluteValue(int num) {//求数绝对值
	if(num<0)
	return 0x0-(unsigned)num;

	return num;

}
#endif