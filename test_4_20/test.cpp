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
//	//int& ra = a; // ��������ʱ�����aΪ����
//	const int& ra = a;
//
//	//int& b = 10; // ��������ʱ�����bΪ����
//	const int& b = 10;
//
//	double d = 12.34;
//	//int& rd = d; // ��������ʱ��������Ͳ�ͬ
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
//	// ��ֵ��Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//
//	// ��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//
//	// �ֱ���������������н������ʱ��
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}


//#include <time.h>
//struct A { int a[10000]; };
//A a;
//// ֵ����
//A TestFunc1() { return a; }
//// ���÷���
//A& TestFunc2() { return a; }
//void TestReturnByRefOrValue()
//{
//	// ��ֵ��Ϊ�����ķ���ֵ����
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	// ��������Ϊ�����ķ���ֵ����
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	// �������������������֮���ʱ��
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
//	std::map<std::string, std::string> m{ { "apple", "ƻ��" }, { "orange",
//	"����" },
//	{"pear","��"} };
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
//	const pstring p1; // ����ɹ�����ʧ�ܣ�
//	const pstring* p2; // ����ɹ�����ʧ�ܣ�
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
//	//auto e; �޷�ͨ�����룬ʹ��auto�������ʱ���������г�ʼ��
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
//	auto c = 3, d = 4.0; // ���д�������ʧ�ܣ���Ϊc��d�ĳ�ʼ�����ʽ���Ͳ�ͬ
//}

// �˴��������ʧ�ܣ�auto������Ϊ�β����ͣ���Ϊ�������޷���a��ʵ�����ͽ����Ƶ�
//void TestAuto(auto a)
//{}

//void TestAuto()
//{
//	int a[] = { 1,2,3 };
//	auto b[] = { 4��5��6 };
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
//	// ����
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





