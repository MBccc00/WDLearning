#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int sum_array(int*,int);
void find_target(int*, int,int);
void reverse_array(int* ,int);
void copy_array(int*, int*,int);
void odd_first(int*,int);
void output_array(int* , int );


/**********************************************************************
 *数组元素的逆序。要求使用指针操作直接完成，不要使用下标运算。
数组元素求和。要求使用`*p++`来完成数组元素的累加
给定一个int数组以及一个目标值，请编写函数找到这个目标值的下标，要求该函数没有返回值。
编写函数交换数组中两个下标的元素。
要求不能使用[]运算符且函数声明如下：void swap(int *arr, int i, int j)
给定一个整数数组，编写一个函数 copy_array，使用 *p++ 复制这个数组到一个新的数组，要求函数没有返回值。注意：你还没有学过动态内存分配，但应该至少应该知道不能返回局部变量数组。
给定一个整数数组，将所有奇数移到数组前面，偶数移到数组后面。（扩展题）                                *
 **********************************************************************/

//需要的函数功能：逆序reverse；求和sum；找目标下标；复制数组；奇前偶后
int main(void) {
	int array_length;
	printf("enter the array length:");
	scanf("%d", &array_length);

	int *arr = (int*)malloc(sizeof(int) * array_length);//声明并且初始化一个动态数组
	//malloc函数，返回的是指向起始位置的指针
	printf("enter the num:");
	for (int i = 0;i < array_length;i++)//指针的算数运算，是对指针所指向地址的操作
		//i=arr,是错误的表达方式，是将arr现在还没有初始化的首元素的地址传给了一个变量
		//arr[i]也是错误的表达方式，这里arr已经是指针变量，
			scanf("%d",arr+i);
	

	int sum= sum_array(arr,array_length);//计算数组中元素和
	printf("the sum of this array is % d.\n", sum);

	int num;
	printf("enter the target number:");//查找目标数字
	scanf("%d", &num);
	find_target(arr,num,array_length);


	reverse_array(arr,array_length);//数组逆置
	printf("the reverse array is:");
	output_array(arr, array_length);



	int* arr_copy = (int*)malloc(sizeof(int) * array_length);//数组复制
	copy_array(arr,arr_copy,array_length);
	printf("the copy array is:");
	output_array(arr_copy, array_length);


	odd_first(arr, array_length);//调整数组奇数元素在偶数元素之前
	printf("the odd_first array is:");
	output_array(arr, array_length);



	return 0;
}

void output_array(int* arr, int n) {
	for (int i = 0;i < n;i++)
		printf("%d ", *(arr + i));
	printf("\n");
}

int sum_array(int *arr, int n) {
	//形参非int类型，不能省略类型声明
	int sum = 0;
	for (int i = 0;i < n;i++) {
		sum += *(arr + i);
	}

	return sum;
}

void find_target(int *arr, int n,int end) {//寻找数组中是否存在特定值，并且返回下标
	for (int i = 0;i < end;i++) {
		if (*(arr + i) == n) {
			printf("success find.The subscriptd is:%d.\n", i);
			return;
		}
	}

	printf("failed.The target hasn't been found.\n");

}

void reverse_array(int* arr,int n) {//数组逆置
	int tmp = 0;
	for (int i = 0;i < n / 2;i++) {
		tmp = *(arr + i);
		*(arr + i) = *(arr + n - i-1);
		//记得数组下表之间的关系，不然就是未定义行为
		*(arr + n - i-1) = tmp;
	}
}

void copy_array(int* arr, int* array_copy,int n) {
	for (int i = 0;i < n;i++) {
		*(array_copy+i) = *arr++;
	}
}

void odd_first(int* arr, int n) {
	for (int i = 0;i < n/2;i++) {//遍历数组
		if (*(arr + i) % 2) {//奇数在前则指针后移
			i++;
		}
		else {//偶数在前，则检索其之后一个奇数与它对换位置
			for (int j = i;j < n;j++) {

				if (*(arr + j) % 2) {
					int tmp = *(arr + i);
					*(arr + i) = *(arr + j);
					*(arr + j) = tmp;
				}

			}
		}
	}
}
