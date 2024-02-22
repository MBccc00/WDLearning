#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define YEAR 5
#define INITAL_CASH 100

int main(void) {
	int years, rate;	// ��������Ͷ�ʵ�����Լ�����
	printf("������������: ");
	scanf("%d", &rate);

	printf("������ҪͶ�ʵ����: ");
	scanf("%d", &years);

	// ����һ������,�����洢����������Ͷ�ʵ����
	double balances[YEAR];	// ��Ҫ���Ǵ�ʱ����û�г�ʼ��,ֻ�����ֵ

	// ��ӡ��ͷ Ҳ����ͼ�εĵ�һ��
	printf("\nYears");
	for (int i = 0; i < YEAR; i++) {
		// ��ӡÿһ�е�����
		printf("%11d%%", (rate + i));
		// ˳���balances��ʼ��
		balances[i] = INITAL_CASH;
	}	// ��ʱbalances�����Ԫ��ȫ���ǳ�ʼ���

	// ��������ӡ���ľ�������
	printf("\n");
	// ���for��������,��������ƴ�ӡ���,�����ж�������ж�����
	for (int i = 1; i <= years; i++) {
		// ��ӡ��һ�е�����
		printf("%4d  ", i);

		// �ڲ�for��������,Ҳ���Ǹ�balances���鸳ֵ,���Ҵ�ӡ��,RATE_NUMS����������
		for (int j = 0; j < YEAR; j++) {
			// ��ӡ�����һ���е�����
			// ����Ҫ���������������i������,Ȼ��Ҫ�浽ԭ������
			balances[j] += balances[j] * (rate + j) * 0.01;
			printf("%12.2f", balances[j]);
		}

		// ����
		printf("\n");
	}

	return 0;
}