#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int rollDice(void);
bool judgeContinue(void);


/**********************************************************************
��д����ģ�������ӵ���Ϸ���������ӣ���ÿ����Ϸ�Ĺ������£�

��һ������ʱ���� ������֮��Ϊ 7 �� 11 ���ʤ���������֮��Ϊ2��3��12����ܣ���������µĵ���֮�ͳ�Ϊ��Ŀ�ꡱ����Ϸ�������ں�����Ͷ���У��������ٴ�������Ŀ�ꡱ�������ʤ������7����ܣ�������������ԣ���Ϸ�������С�

ÿ����Ϸ����ʱ������ѯ���û��Ƿ�����һ�Σ������ ������Ļش��� y �� Y ���������ʾʤ�ܵĴ���Ȼ����ֹ��(��չ�⣬��Ҫ��ÿ��ͬѧ�ش�)

You rolled: 8
Your point is 8
You rolled: 3
You rolled: 10
You rolled: 8
You win!

Play again? y

You rolled: 6
Your point is 6
You rolled: 5
You rolled: 12
You rolled: 3
You rolled: 7
You lose!

Play again? y

You rolled: 11
You win!

Play again? n

Wins: 2 Losses: 1
 **********************************************************************/

int main(void) {
	srand(time(NULL));//������������ֵ
	rollDice();
	return 0;
}

int rollDice(void) {
	int countWin = 0, countLose = 0;
	
	do {

		int num = rand() % 12+1;
		int point = num;
		int temp = rand()%12+1;
		

		if (num == 7 || num == 11) {
			printf("You rolled: %d\n", num);
			printf("You Win!\n");
			printf("\n");
			countWin++;
		}
		else if (num == 2 || num == 3 || num == 12) {
			printf("You rolled: %d\n", num);
			printf("You Lose!\n");
			printf("\n");
			countLose++;
		}
		else {
			printf("You rolled: %d\nYour point is %d\n", num, num);
			int temp = rand() % 12 + 1;

			if (temp == 7) {
				printf("You Lose!\n");
				printf("\n");
				countLose++;
			}
			else  {
				while (temp != point) {
					temp = rand() % 12 + 1;
					printf("You rolled: %d\n", temp);
				}
				printf("You win!\n");
				printf("\n");
				countWin++;
			}
		}

	} while (judgeContinue());//����������ʱ����

	printf("Wins: %d Losses: %d\n", countWin, countLose);

	return 0;
		

}

bool judgeContinue(void) {//���û������ж��Ƿ����
	char a;
	printf("Play Again?\n");
	scanf(" %c", &a);//�ո��������ջ��з���
	while (getchar() != '\n');//��ջ�����
	return ('y' == a ||'Y' == a);
}

