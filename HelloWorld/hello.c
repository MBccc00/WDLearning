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

    printf("���������һ��int����: ");
    int c;
    scanf("%d", &c);
    if (c > 0) {
        printf("�������������0!\n");
    }
    else if (c < 0) {
        printf("���������С��0!\n");
    }
    else {
        printf("�������������0!\n");
    }

    printf("��������ʼ��ӡһ������,������Ҫ��ӡ���ε�����������: \n");
    int line;
    int column;
    scanf("%d", &line);
    scanf("%d", &column);
    print_rectangle(line, column);

    return 0;
}