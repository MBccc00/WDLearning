#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int hanoti(int);
void hanoti_move(int n, char start, char temp, char end);

/**********************************************************************
 ��ŵ��
����������A��B��C��A������ N �� (N>1) ����Բ�̣��̵ĳߴ����µ������α�С��Ҫ�����й�������Բ������ C �ˣ�
ÿ��ֻ���ƶ�һ��Բ��;
���̲��ܵ���С�����档
��ʾ���ɽ�Բ����ʱ���� B �ˣ�Ҳ�ɽ��� A ���Ƴ���Բ�������ƻ� A �ˣ�����������ѭ������������
�ʣ�������Ҫ�ƶ����ٴΣ�����ƣ���ӡ�������ƶ��켣

 **********************************************************************/

int main(void) {
	printf("enter the number of plate:");
	int num;
	scanf("%d", &num);

	char a='A', b='B', c='C';//��ӡ�ƶ��켣
	hanoti_move(num, a, b, c);

	int res = hanoti (num);//���㲽��
	printf("total move step:%d", res);

	return 0;
}

void hanoti_move(int n, char start, char tmp, char end) {//�����β�����Ϊ��Ŀ����ʼ����ת��Ŀ��
	if (n == 1) {
		printf("%c---->%c.\n", start, end);
		return;
	}
//
	hanoti_move(n - 1, start, end, tmp);//�Ƚ���Ŀ���̣���n-1������ת������ת
	printf("%c---->%c.\n", start, end);//�����µĴ���ת����Ŀ��
	hanoti_move(n - 1, tmp, start, end);//�ٽ�����ʼ������ת��n-1��ת����Ŀ��
}

int hanoti(n) {//�ݹ�����ŵ������
	if (n == 1)
		return 1;
	return hanoti(n - 1)*2 + 1;
}