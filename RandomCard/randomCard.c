#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SUIT_NUMS 4
#define POINTS_NUMS 13

void random(void);

/**********************************************************************
 *  写一个随机发牌的程序。用户指定发几张牌，程序打印手牌。程序的会话如下：

Enter number of cards in hand: 5
Your hand: 9c 7d 3c 5d kd                                 *
 **********************************************************************/

int main(void) {
	srand(time(NULL));
	random();

	return 0;
}

void random(void) {
	int num = 0, temp1 = 0, temp2 = 0;
	printf("Enter number of cards in hand: ");
	scanf("%d", &num);
	printf("Your hand:");

	const char *suits[] = { 'C', 'D', 'H', 'S' };//定义手牌
	const char *points[] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };

	for (int i = 0;i <= num;i++) {
		temp1 = rand() % SUIT_NUMS;//宏定义
		temp2 = rand() % POINTS_NUMS;


		printf(" %c%c", suits[temp1], points[temp2]);//注意数组存放的数据类型
	}

}