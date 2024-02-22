#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int rollDice(void);
bool judgeContinue(void);


/**********************************************************************
编写程序模拟掷骰子的游戏（两个骰子）。每局游戏的规则如下：

第一次掷的时候，如 果点数之和为 7 或 11 则获胜；如果点数之和为2、3或12则落败；其他情况下的点数之和称为“目标”，游戏继续。在后续的投掷中，如果玩家再次掷出“目标”点数则获胜，掷出7则落败，其他情况都忽略，游戏继续进行。

每局游戏结束时，程序询问用户是否再玩一次，如果用 户输入的回答不是 y 或 Y ，程序会显示胜败的次数然后终止。(拓展题，不要求每个同学回答)

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
	srand(time(NULL));//随机数获得骰子值
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

	} while (judgeContinue());//当条件满足时继续

	printf("Wins: %d Losses: %d\n", countWin, countLose);

	return 0;
		

}

bool judgeContinue(void) {//由用户输入判断是否继续
	char a;
	printf("Play Again?\n");
	scanf(" %c", &a);//空格用来吸收换行符等
	while (getchar() != '\n');//清空缓冲区
	return ('y' == a ||'Y' == a);
}

