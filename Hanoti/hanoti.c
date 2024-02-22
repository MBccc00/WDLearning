#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int hanoti(int);
void hanoti_move(int n, char start, char temp, char end);

/**********************************************************************
 汉诺塔
有三根杆子A，B，C。A杆上有 N 个 (N>1) 穿孔圆盘，盘的尺寸由下到上依次变小。要求按下列规则将所有圆盘移至 C 杆：
每次只能移动一个圆盘;
大盘不能叠在小盘上面。
提示：可将圆盘临时置于 B 杆，也可将从 A 杆移出的圆盘重新移回 A 杆，但都必须遵循上述两条规则。
问：最少需要移动多少次？如何移？打印出它的移动轨迹

 **********************************************************************/

int main(void) {
	printf("enter the number of plate:");
	int num;
	scanf("%d", &num);

	char a='A', b='B', c='C';//打印移动轨迹
	hanoti_move(num, a, b, c);

	int res = hanoti (num);//计算步数
	printf("total move step:%d", res);

	return 0;
}

void hanoti_move(int n, char start, char tmp, char end) {//传入形参依次为数目，开始，中转，目的
	if (n == 1) {
		printf("%c---->%c.\n", start, end);
		return;
	}
//
	hanoti_move(n - 1, start, end, tmp);//先借助目的盘，将n-1个盘子转移至中转
	printf("%c---->%c.\n", start, end);//将余下的大盘转移至目的
	hanoti_move(n - 1, tmp, start, end);//再借助开始，将中转的n-1个转移至目的
}

int hanoti(n) {//递归解决汉诺塔问题
	if (n == 1)
		return 1;
	return hanoti(n - 1)*2 + 1;
}