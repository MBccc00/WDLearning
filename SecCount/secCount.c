#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int sec_count(int, int, int);
void split_time(long total_sec, int* hour, int* minute, int* second);

/**********************************************************************
 *void split_time(long total_sec, int* hour, int* minute, int* second);
 total_sec ��ʾ����ҹ12:00:00��ʼ�����������
 �뽫 total_sec ת����ʱ(0-23)����(0-59)����(0-59)��ʾ��ʱ�䣬
 ����ŵ������ⲿ��ָ�� hour, minute, second ָ��ı����С�
 �����ⲿ����ӡ����ǰ��ʱ��                                                 
 **********************************************************************/

//��Ҫ�ĺ���������������ʱ��ת��
//�������������

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

int sec_count(a, b, c ) {//��24��00��ʼ������ʱ�������
	return  a * 3600 + b * 60 + c;
}

void split_time(long total_sec, int* hour, int* minute, int* second) {
	*hour = total_sec / 3600;
	*minute = total_sec / 60 - *hour * 60;
	*minute = total_sec - *hour * 3600 - *minute * 60;
}
