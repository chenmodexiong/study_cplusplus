//#include <stdio.h>
//#include <stdlib.h>
#include <iostream>

//int rand = 0;
//
//int main()
//{
//	int rand = 1;
//	printf("%d", ::rand);
//	return 0;
//}

//namespace lzb
//{
//	int rand = 0;
//}
//
//int main()
//{
//	printf("%d", lzb::rand);
//	return 0;
//}

///*正常定义命名空间*/
//namespace lzb
//{
//	// 命名空间中可以定义变量/函数/类型
//	int rand = 10;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	struct Node
//	{
//		struct Node* next;
//		int val;
//	};
//}
//
///*命名空间可以嵌套*/
//namespace N1
//{
//	int a;
//	int b;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	namespace N2
//	{
//		int c;
//		int d;
//		int Sub(int left, int right)
//		{
//			return left - right;
//		}
//	}
//}
//
///*可以随时添加成员*/
//namespace A {
//	int a = 100;
//	int b = 200;
//}
////将c添加到已有的命名空间A中
//namespace A {
//	int c = 300;
//}
//
///*成员函数可以在外部定义，但要记得加作用域*/
//namespace A {
//	int a = 100;//变量
//
//	void func();
//}
//void A::func()//成员函数 在外部定义的时候 记得加作用域
//{
//	//访问命名空间的数据不用加作用域
//	cout << "func遍历a = " << a << endl;
//}
//void funb()//普通函数
//{
//	cout << "funb遍历a = " << A::a << endl;
//}
//void test06()
//{
//	A::func();
//	funb();
//}
//
///*无名命名空间只能在本文件内使用*/
//namespace {
//	int a = 10;
//	void func() {
//		cout << "hello namespace" << endl;
//	}
//}
//void test() {
//
//	//只能在当前源文件直接访问a 或 func
//	cout << "a = " << a << endl;
//	func();
//}
//
///*给命名空间改个名字*/
//namespace veryLongName {
//	int a = 10;
//	void func() {
//		cout << "hello namespace" << endl;
//	}
//}
//void test() {
//	namespace shortName = veryLongName;
//	cout << "veryLongName::a : " << shortName::a << endl;
//	veryLongName::func();
//	shortName::func();
//}

using namespace std;
namespace lzb
{
	// 命名空间中可以定义变量/函数/类型
	int a = 0;
	int b = 1;
	int Add(int left, int right)
	{
		return left + right; 
	}
	namespace lzb2
	{
		int c = 100;
		struct Node
		{
			struct Node* next;
			int val;
		};
	}
}
using namespace lzb;
using namespace lzb::lzb2;
int main()
{
	cout << a << b << endl;
	cout << c << endl;
	return 0;
}


//using lzb::a;
//using lzb::lzb2::c;
//int main()
//{
//	cout << a << c << endl;
//	return 0;
//}

//int main()
//{
//	cout << lzb::a << lzb::b << endl;//访问a和b
//	cout << lzb::lzb2::c << endl;//访问c
//	return 0;
//}
