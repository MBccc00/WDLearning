#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

//int countBinaryOne(int num);
//int judgeOpposite(int num1, int num2);
int absoluteValue(int num);

/**********************************************************************
 1.��дһ������������һ�������Ķ����Ʊ�ʾ��1�ĸ�����

2.�ж����������Ƿ��෴���š�����1��-2�;����෴�ķ���

3.����λ�������һ�������ľ���ֵ
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
int countBinaryOne(int num) {//�ж����������Ʊ����1����Ŀ
	int sum = 0;
	while (num!=0) {
		sum += num & 1;//��ĩλΪ1ʱ����
		num >>= 1;
	}
	return sum;
}
#endif

#if 1
int judgeOpposite(int num2, int num3) {//�ж������������Ƿ����

	return 0x1fff&(num2&num3);//ֱ���ж����λ����
}
#endif

#if 1
int absoluteValue(int num) {//��������ֵ
	if(num<0)
	return 0x0-(unsigned)num;

	return num;

}
#endif