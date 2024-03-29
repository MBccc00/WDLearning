#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10

/**********************************************************************
 

大致图案如下：

1

1 1

1 2 1

1 3 3 1

1 4 6 4 1

1 5 10 10 5 1

........



杨辉三角从纯粹数字规律上来说，就是：

每一行的元素和行数一样，即行数等于列数。第一行有一列，第二行有两列....

第一行的元素从1开始，且之后每个元素的值，都是上一行同列元素和上一行左边列的元素之和。

前两行的元素和每一行的首尾元素由于没有上一行同列元素或上一行左列元素，默认都是1。

现在请你用二维数组来存储杨辉三角的前十行(每一行就是一个一维数组)，并以杨辉三角的打印格式来最终打印杨辉三角。                                  *
 **********************************************************************/

int main(void) {
	int tri[0x000a][SIZE] = { {0} };
	for (int i = 0;i < SIZE;i++) {//将下半区域初始化为1
		for (int j = 0;j <= i;j++)
			tri[i][j] = 1;
	}

	for (int i = 2;i < SIZE;i++) {
		for (int j = 1;j < i;j++) {
			tri[i][j] = tri[i - 1][j] + tri[i - 1][j - 1];
		}
	}

	for (int i = 0;i < SIZE;i++) {//遍历输出
		for (int j = 0;j <= i;j++) {
			printf("%3d ", tri[i][j]);
		}
		printf("\n");
	}

	return 0;
}