#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_rectangle(int line, int column) {
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < column; j++) {
            printf("#");
        }
        printf('/n');
    }
}

int main(void) {
    printf("hello world!\n");

    int a = 10;
    int b = 20;
    int sum = a + b;

    printf("请键盘输入一个int整数: ");
    int c;
    scanf("%d", &c);
    if (c > 0) {
        printf("您输入的数大于0!\n");
    }
    else if (c < 0) {
        printf("您输入的数小于0!\n");
    }
    else {
        printf("您输入的数就是0!\n");
    }

    printf("接下来开始打印一个矩形,请输入要打印矩形的行数和列数: \n");
    int line;
    int column;
    scanf("%d", &line);
    scanf("%d", &column);
    print_rectangle(line, column);

    return 0;
}