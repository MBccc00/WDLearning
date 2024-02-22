#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
int DateSpan(year1, mon1, day1, year2, mon2, day2);
bool JudgeLeapYear(year);
void NextDay(year, month, day, leap);
int Week(span, year2);

/*
* 编写一个函数，输入两个日期（年/月/日），计算这两个日期之间相隔的天数。

要求键盘录入的第一个日期，必须要早于第二个日期。

例如：

键盘录入2020/01/01和2020/01/02，打印它们相隔1天

键盘录入2020/01/01和2021/01/02，打印它们相隔367天
*/

int main(void) {
	int year1, year2, mon1, mon2, day1, day2;
	printf("enter two date:");
	scanf("%d/%d/%d %d/%d/%d", year1, mon1, day1, year2, mon2, day2);
	int span = DateSpan(year1, mon1, day1, year2, mon2, day2);
	printf("the interval is %d", span);

	int week = Week(year1, mon1, day1, year2, mon2, day2);
	printf("this day is the %dth of this week", week);

}

bool JudgeLeapYear(year) {
	if (year % 4 != 0) return false;
	else if (year % 100 != 0) return true;
	else if (year % 400 != 0) return false;
	else return true;
}


int StartYearNow(year, month, day, leap) {
	int sum = 0,date=0;
	for (int i = 1;i <= month;i++) {
		switch (i)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			date = 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			date = 30;
			break;
		case 2:
			if (leap) 
				date = 29;
			else
				date = 28;
			
			break;

		}
		sum += date;
	}
	return sum + day;
}

int DateSpan(year1, mon1, day1, year2, mon2, day2) {
	int sum = 0;
	for (int i = year1+1;i < year2;i++) {
		if (JudgeLeapYear(i))
			sum += 366;
		else
			sum += 365;
	}

	if (JudgeLeapYear(year1))
		sum += 366 - startYearNow(year1, mon1, day1, JudgeLeapYear(year1)) + startYearNow(year2, mon2, day2, JudgeLeapYear(year2));
	else
		sum += 365 - startYearNow(year1, mon1, day1, JudgeLeapYear(year1)) + startYearNow(year2, mon2, day2, JudgeLeapYear(year2));

	return sum;
}

int Week(year1, mon1, day1, year2, mon2, day2) {
	int span = DateSpan(1970, 1, 1, year2, mon2, day2);
	for (int year = 1970;year < year2;year++) {
		{
			if (JudgeLeapYear(year)) span -= 366;
			else span -= 365;
		}
		int week = (span + 4) % 7;
				
		return week;

}