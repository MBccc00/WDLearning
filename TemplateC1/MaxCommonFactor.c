
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int EuclideanMaxCommon(numer,denomi);

/*
дһ������ʵ�ַ�����ӡ��û��Է���/��ĸ����ʽ��������������ӡ��Ӻ�Ľ��(��Ϊ������)���磺

����:
Enter first fraction: 5/6
Enter second fraction: 3/4
�����
The sum is 19/12
*/

int main(void) {
	int numerator1, denominator1, numerator2, denomirator2;//���ո�ʽ������������
	printf("Enter first fraction:");
	scanf("%d/%d", &numerator1, &denominator1);
	printf("Enter second fraction:");
	scanf("%d/%d", &numerator2, &denomirator2);

	int numer, denomi;

	numer = numerator1 * denomirator2 + numerator2 * denomirator2;//��Լ��ʱ���мӺͺ�ķ��ӷ�ĸ
	denomi = denominator1 * denomirator2;

	int MaxCommon = 0;
	MaxCommon = EuclideanMaxCommon(numer, denomi);//ŷ����÷��������Լ��

	printf("The sum is %d/%d", numer / MaxCommon, denomi / MaxCommon);

}


int EuclideanMaxCommon(numer, denomi) {
	int remainder = 0;
	while (denomi > 0) {//�������ɰ岻ͣ�ָ��˼��
		if (numer % denomi == 0) break;//����Ϊ0����ѭ�������ҵ����Լ��
		else {
			remainder = numer % denomi;
			numer = denomi;
			denomi = remainder;
		}
	}
	return remainder;
}

