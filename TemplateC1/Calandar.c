#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
bool JudgeLeapYear(year);
void NextDay(year, month, day, leap);

/*用C语言编写程序实现以下需求：

编写一个函数，输入一个公元年份（如2004），判断该年是否为闰年，并返回判断结果。

平年闰年的规则如下：

如果年份不是4的倍数，则是平年。
如果年份是4的倍数但不是100的倍数，则是闰年。
如果年份是100的倍数但不是400的倍数，则是平年。
如果年份是400的倍数，则是闰年。
要求使用bool类型作为函数的返回值*/

/*紧接着上一问，编写一个函数，输入年、月、日，计算并输出下一天的日期。

比如：

传入函数的日期是2004年3月31日

那么函数体内部要直接打印下一天是：2004年4月1日

要求：

键盘录入年月日日期时，键盘录入的格式是："年/月/日"*/

int main(void) {
	printf("enter the year:");
	int year;
	scanf("%d/", &year);
	bool leap=JudgeLeapYear(year);
	//printf("the result is %d", result);
	int month, day;
	sacnf("%d/%d", &month, &day);
	NextDay(year, month, day,leap);
	JudgeLeapYear(year);
	system("pause");
	return 0;

}


bool JudgeLeapYear(year) {//变量和函数名通常用小驼峰
	/*if (year % 4 != 0) return false;
	else if (year % 100 != 0) return true;
	else if (year % 400 != 0) return false;
	else return true;
	*/
	/*啰嗦，return结束当前程序运行，将true的请况先规整为一类，余下部分就一定错了；
	而且if本身就进行了条件判断，所以直接用return进行条件判断即可
	*/
	return ((year % 100 != 0&& year % 4 == 0||(year % 400 == 0))
}


void NextDay(year, month, day,leap) {
	switch (month)//用数组直接存月份的天数，注意在0处放置一个占位符
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day == 31) {
			if (month = 12) {
				year++;
				day = 1;
				month = 1;
			}
			else {
				month++;
				day = 1;
			}
			
		}
		else
			day++;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (day = 30) {
			month++;
			day = 1;
		}
		else
			day++;
		break;
	case 2:
		if (leap) {
			if (day == 29) {
				month++;
				day = 1;
			}
			else
				day++;
		}
		break;

	}
	print("next day is %d/%d/%d", year, month, day);
}