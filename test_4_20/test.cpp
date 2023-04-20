#include <iostream>
using namespace std;

//int main()
//{
//	int a = 10;
//	int& ra = a;
//	cout << a << endl;
//	cout << ra << endl;
//}

//int main()
//{
//	int a = 10;
//	int& ra = a;
//	int& rra = ra;
//	cout << a <<' '<< ra <<' '<< rra;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int b = 20;
//	int& ra = a;
//	ra = b;
//	cout << ra;
//	return 0;
//}

//void TestConstRef()
//{
//	const int a = 10;
//	//int& ra = a; // 该语句编译时会出错，a为常量
//	const int& ra = a;
//
//	//int& b = 10; // 该语句编译时会出错，b为常量
//	const int& b = 10;
//
//	double d = 12.34;
//	//int& rd = d; // 该语句编译时会出错，类型不同
//	const int& rd = d;
//	cout << rd;
//}

//void Swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	Swap(a, b);
//	cout << a << ' ' << b;
//	return 0;
//}

//int& Count(int a)
//{
//	static int n = a;
//	n++;
//	// ...
//	return n;
//}
//
//int main()
//{
//	cout << Count(10) << endl;
//	printf("hehe\n");
//	cout << Count(10) << endl;
//	return 0;
//}

//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int& ret = Add(1, 2);
//	cout << ret << endl;
//	Add(3, 4);
//	cout << ret << endl;
//	cout << "Add(1, 2) is :" << ret << endl;
//	return 0;
//}

//#include <time.h>
//struct A { int a[10000]; };
//void TestFunc1(A a) {}
//void TestFunc2(A& a) {}
//void TestRefAndValue()
//{
//	A a;
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//
//	// 分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}


//#include <time.h>
//struct A { int a[10000]; };
//A a;
//// 值返回
//A TestFunc1() { return a; }
//// 引用返回
//A& TestFunc2() { return a; }
//void TestReturnByRefOrValue()
//{
//	// 以值作为函数的返回值类型
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	// 以引用作为函数的返回值类型
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	// 计算两个函数运算完成之后的时间
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}

//int main()
//{
//	//TestRefAndValue();
//	TestReturnByRefOrValue();
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	int& ra = a;
//	return 0;
//}

//#include "test.h"
//
//int main()
//{
//	Add(1, 2);
//	return 0;
//}

//
//int main()
//{
//	auto a = 10;
//	cout << a;
//	return 0;
//}


//#include <string>
//#include <map>
//int main()
//{
//	std::map<std::string, std::string> m{ { "apple", "苹果" }, { "orange",
//	"橙子" },
//	{"pear","梨"} };
//	std::map<std::string, std::string>::iterator it = m.begin();
//	while (it != m.end())
//	{
//		//....
//	}
//	return 0;
//}

//typedef char* pstring;
//int main()
//{
//	const pstring p1; // 编译成功还是失败？
//	const pstring* p2; // 编译成功还是失败？
//	return 0;
//}

//int TestAuto()
//{
//	return 10;
//}
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = TestAuto();
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	//auto e; 无法通过编译，使用auto定义变量时必须对其进行初始化
//	return 0;
//}

//int main()
//{
//	int x = 10;
//	auto a = &x;
//	auto* b = &x;
//	auto& c = x;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	*a = 20;
//	*b = 30;
//	c = 40;
//	return 0;
//}

//void TestAuto()
//{
//	auto a = 1, b = 2;
//	auto c = 3, d = 4.0; // 该行代码会编译失败，因为c和d的初始化表达式类型不同
//}

// 此处代码编译失败，auto不能作为形参类型，因为编译器无法对a的实际类型进行推导
//void TestAuto(auto a)
//{}

//void TestAuto()
//{
//	int a[] = { 1,2,3 };
//	auto b[] = { 4，5，6 };
//}


//void TestFor()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//		array[i] *= 2;
//	for (int* p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)
//		cout << *p << endl;
//}


//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//	for (auto& e : arr)
//		e *= 2;
//
//	for (auto& e : arr)
//		cout << e << ' ';
//	return 0;
//}


//void TestFor(int array[])
//{
//	for (auto& e : array)
//		cout << e << endl;
//}

//void TestPtr()
//{
//	int* p1 = NULL;
//	int* p2 = 0;
//	// ……
//}

void f(int)
{
	cout << "f(int)" << endl;
}
void f(int*)
{
	cout << "f(int*)" << endl;
}
int main()
{
	f(0);
	f(NULL);
	f((int*)NULL);
	return 0;
}





