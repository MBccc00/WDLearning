#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int sec_count(int, int, int);
void split_time(long total_sec, int* hour, int* minute, int* second);

/**********************************************************************
 *void split_time(long total_sec, int* hour, int* minute, int* second);
 total_sec 表示从午夜12:00:00开始计算的秒数。
 请将 total_sec 转化以时(0-23)、分(0-59)、秒(0-59)表示的时间，
 并存放到函数外部由指针 hour, minute, second 指向的变量中。
 并在外部，打印出当前的时间                                                 
 **********************************************************************/

//需要的函数：计算秒数，时间转换
//主函数输入输出

int main(void) {
	printf("enter the time:");
	int hour, min, sec;
	scanf("%d%d%d", &hour, &min, &sec);

	long sum=sec_count(hour, min, sec);
	printf("%d\n", sum);

	int* a, * b, * c;
	a = &hour;
	b = &min;
	c = &sec;
	void split_time(sum, a, b, c);
	printf("the time that user enter is:%d/%d/%d.\n", *a, *b, *c);


	return 0;
}

int sec_count(a, b, c ) {//从24：00开始至输入时间的秒数
	return  a * 3600 + b * 60 + c;
}

void split_time(long total_sec, int* hour, int* minute, int* second) {
	*hour = total_sec / 3600;
	*minute = total_sec / 60 - *hour * 60;
	*minute = total_sec - *hour * 3600 - *minute * 60;
}
