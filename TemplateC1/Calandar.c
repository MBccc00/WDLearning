#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
bool JudgeLeapYear(year);
void NextDay(year, month, day, leap);

/*��C���Ա�д����ʵ����������

��дһ������������һ����Ԫ��ݣ���2004�����жϸ����Ƿ�Ϊ���꣬�������жϽ����

ƽ������Ĺ������£�

�����ݲ���4�ı���������ƽ�ꡣ
��������4�ı���������100�ı������������ꡣ
��������100�ı���������400�ı���������ƽ�ꡣ
��������400�ı������������ꡣ
Ҫ��ʹ��bool������Ϊ�����ķ���ֵ*/

/*��������һ�ʣ���дһ�������������ꡢ�¡��գ����㲢�����һ������ڡ�

���磺

���뺯����������2004��3��31��

��ô�������ڲ�Ҫֱ�Ӵ�ӡ��һ���ǣ�2004��4��1��

Ҫ��

����¼������������ʱ������¼��ĸ�ʽ�ǣ�"��/��/��"*/

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


bool JudgeLeapYear(year) {//�����ͺ�����ͨ����С�շ�
	/*if (year % 4 != 0) return false;
	else if (year % 100 != 0) return true;
	else if (year % 400 != 0) return false;
	else return true;
	*/
	/*���£�return������ǰ�������У���true������ȹ���Ϊһ�࣬���²��־�һ�����ˣ�
	����if����ͽ����������жϣ�����ֱ����return���������жϼ���
	*/
	return ((year % 100 != 0&& year % 4 == 0||(year % 400 == 0))
}


void NextDay(year, month, day,leap) {
	switch (month)//������ֱ�Ӵ��·ݵ�������ע����0������һ��ռλ��
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