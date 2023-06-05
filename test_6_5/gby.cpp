//#include <iostream>
//using namespace std;
//#include <ctime>
//#include <cstring>
//#include <cstdlib>
//#include <string>
//
//int InitNum()
//{
//	int num1 = rand() % 20, num2 = rand() % 20;//两个随机数
//	string s1 = "+-*/";
//	int d = rand() % 4;//d控制运算符
//	switch (s1[d])
//	{
//	case '+':
//		cout << num1 << "+" << num2 << "=" << num1 + num2 << endl;
//		return num1 + num2;
//	case '-':
//		cout << num1 << "-" << num2 << "=" << num1 - num2 << endl;
//		return num1 - num2;
//	case '*':
//		cout << num1 << "*" << num2 << "=" << num1 * num2 << endl;
//		return num1 * num2;
//	case '/':
//		cout << num1 << "/" << num2 << "=" << num1 / num2 << endl;
//		return num1 / num2;
//	}
//}
//int GetMaxi(int* arr, int n)
//{
//	int maxi = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		if (arr[i] > arr[maxi])
//			maxi = i;
//	}
//	return maxi;
//}
//int GetMini(int* arr, int n)
//{
//	int mini = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		if (arr[i] < arr[mini])
//			mini = i;
//	}
//	return mini;
//}
//void Swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//void UpSort(int* arr, int n)
//{
//	for (int j = 0; j < n - 1; ++j)
//	{
//		for (int i = 1; i < n - j; ++i)
//		{
//			if (arr[i - 1] > arr[i])
//				Swap(arr[i - 1], arr[i]);
//		}
//	}
//}
//void DownSort(int* arr, int n)
//{
//	for (int j = 0; j < n - 1; ++j)
//	{
//		for (int i = 1; i < n - j; ++i)
//		{
//			if (arr[i - 1] < arr[i])
//				Swap(arr[i - 1], arr[i]);
//		}
//	}
//}
//
//int main()
//{
//	srand((unsigned int)time(NULL));
//	int arr[10];//存结果的数组
//	int ret = 0;//求和
//	for (int i = 0; i < 10; ++i)
//	{
//		arr[i] = InitNum();
//		ret += arr[i];
//	}
//	int a[10];
//	memcpy(a, arr, sizeof(int) * 10);//为了排序的效率再重新操作一个数组
//	cout << "平均数:" << ret / 10 << endl;
//	cout << "最大值:" << arr[GetMaxi(arr, 10)] << endl;
//	cout << "最小值:" << arr[GetMini(arr, 10)] << endl;
//	cout << "排升序:UpSort" << endl;
//	UpSort(arr, 10);
//	for (int i = 0; i < 10; ++i)
//		cout << arr[i] << ' ';
//	cout << endl;
//	cout << "排降序:DownSort" << endl;
//	DownSort(a, 10);
//	for (int i = 0; i < 10; ++i)
//		cout << a[i] << ' ';
//	cout << endl;
//	return 0;
//}



#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int GetMaxi(int* arr, int n)
{
	int maxi = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] > arr[maxi])
			maxi = i;
	}
	return maxi;
}

int GetMini(int* arr, int n)
{
	int mini = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] < arr[mini])
			mini = i;
	}
	return mini;
}

void Swap(int* pa, int* pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

void UpSort(int* arr, int n)
{
	for (int j = 0; j < n - 1; ++j)
	{
		for (int i = 1; i < n - j; ++i)
		{
			if (arr[i - 1] > arr[i])
				Swap(&arr[i - 1], &arr[i]);
		}
	}
}

void DownSort(int* arr, int n)
{
	for (int j = 0; j < n - 1; ++j)
	{
		for (int i = 1; i < n - j; ++i)
		{
			if (arr[i - 1] < arr[i])
				Swap(&arr[i - 1], &arr[i]);
		}
	}
}

void add(int* arr, int t, int* ret)
{
	int num1, num2, answer;
	num1 = rand() % 10;
	num2 = rand() % 10;
	printf("%d+%d=", num1, num2);
	scanf("%d", &answer);
	if (answer == num1 + num2)
		t = t + 1;
	arr[(*ret)++] = num1 + num2;
}

void sub(int* arr, int t, int* ret)
{
	int num1, num2, answer;
	num1 = rand() % 10;
	num2 = rand() % 10;
	printf("%d-%d=", num1, num2);
	scanf("%d", &answer);
	if (answer == num1 - num2)
		t = t + 1;
	arr[(*ret)++] = num1 - num2;
}

void mul(int* arr, int t, int* ret)
{
	int num1, num2, answer;
	num1 = rand() % 10;
	num2 = rand() % 10;
	printf("%d*%d=", num1, num2);
	scanf("%d", &answer);
	if (answer == num1 * num2)
		t = t + 1;
	arr[(*ret)++] = num1 * num2;
}

void div(int* arr, int t, int* ret)
{
	int num1, num2, answer;
	num1 = rand() % 10;
	num2 = rand() % 10;
	printf("%d/%d=", num1, num2);
	scanf("%d", &answer);
	if (answer == num1 / num2)
		t = t + 1;
	arr[(*ret)++] = num1 / num2;
}

int main()
{
	srand((unsigned int)time(NULL));
	int n = 10;//控制10个算式
	int t = 0;//计算算对的次数
	int ret = 0;//存放结果的下标
	int arr[10];//存放结果的数组
	for (int i = 0; i < n; ++i)
	{
		int op = rand() % 4 + 1;
		switch (op)
		{
		case 1:
			add(arr, t, &ret); break;
		case 2:
			sub(arr, t, &ret); break;
		case 3:
			mul(arr, t, &ret); break;
		case 4:
			div(arr, t, &ret); break;
		}
	}
	printf("回答正确 %d 道\n", t);
	printf("最大值:%d\n", arr[GetMaxi(arr, 10)]);
	printf("最小值:%d\n", arr[GetMini(arr, 10)]);
	printf("排升序:UpSort\n");
	UpSort(arr, n);
	for (int i = 0; i < 10; ++i)
		printf("%d ", arr[i]);
	printf("\n");
	printf("排降序:DownSort\n");
	DownSort(arr, n);
	for (int i = 0; i < 10; ++i)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}

