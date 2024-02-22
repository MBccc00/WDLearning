#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
bool judgeLeapYear(int year);
int getDaysOfMonth(int year, int month);
int dateSpan(int year, int mon, int day);
int dayInterval(int year, int mon, int day);
int week(int year, int mon, int day);
int showYearCalandar(int year);



int main(void) {
	int year = 0, mon = 0, day = 0;
	printf("enter the date:");//输入待计算的日期
	scanf("%d%d%d", &year, &mon, &day);

	showYearCalandar(year, mon, day);
}

bool judgeLeapYear(int year) {//判断是否为闰年
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}


int getDaysOfMonth(int year, int month) {//获得当月的天数
	int length[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && judgeLeapYear(year)) {
		return 29;
	}
	return length[month];
}

int dateSpan(int year, int mon, int day) {//判断从基准日期公元一月一日起的时间跨度
	int sum = 0;
	for (int i = 0;i < year;i++) {//该年之前的年所对应时间跨度
		if (judgeLeapYear(year)) {
			sum += 366;
		}
		else sum += 365;
	}

	for (int j = 0;j < mon;j++) {//计算月时间跨度
		sum += getDaysOfMonth(year, j);
	}

	return sum + day;


}



int dayInterval(int year, int mon, int day) {//计算给定日期至1970.1.1之间的时间间隔
	return dateSpan(year, mon, day) - dateSpan(1970, 1, 1);
}

int week(int year, int mon, int day) {

	return (dayInterval(year, mon, day) + 4) % 7;

}

int showYearCalandar(int year) {
	printf("============The Calandar Of Year %d============\n", year);

	int space = 0;
	

	for (int i = 1;i <= 12;i++) {
		int enter = 0;
		printf("%d月\n", i);
		printf(" SUN MON TUE WED THU FRI SAT\n");
		space = week(year, i, 1);

		for (int j = 0;j < space;j++) {
			printf("    ");//单引号是输出字符，双引号是字符串
			enter++;
		}

		for (int k = 1;k <= getDaysOfMonth(year, i);k++) {
			if (enter % 7 == 0) {
				printf("\n");
			}
			if (k < 10)
				printf("%d   ", k);
			else printf("%d  ", k);
			enter++;
		}

		printf("\n");
		printf("\n");
	}

	return 0;

}

