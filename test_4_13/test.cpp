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

///*�������������ռ�*/
//namespace lzb
//{
//	// �����ռ��п��Զ������/����/����
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
///*�����ռ����Ƕ��*/
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
///*������ʱ��ӳ�Ա*/
//namespace A {
//	int a = 100;
//	int b = 200;
//}
////��c��ӵ����е������ռ�A��
//namespace A {
//	int c = 300;
//}
//
///*��Ա�����������ⲿ���壬��Ҫ�ǵü�������*/
//namespace A {
//	int a = 100;//����
//
//	void func();
//}
//void A::func()//��Ա���� ���ⲿ�����ʱ�� �ǵü�������
//{
//	//���������ռ�����ݲ��ü�������
//	cout << "func����a = " << a << endl;
//}
//void funb()//��ͨ����
//{
//	cout << "funb����a = " << A::a << endl;
//}
//void test06()
//{
//	A::func();
//	funb();
//}
//
///*���������ռ�ֻ���ڱ��ļ���ʹ��*/
//namespace {
//	int a = 10;
//	void func() {
//		cout << "hello namespace" << endl;
//	}
//}
//void test() {
//
//	//ֻ���ڵ�ǰԴ�ļ�ֱ�ӷ���a �� func
//	cout << "a = " << a << endl;
//	func();
//}
//
///*�������ռ�ĸ�����*/
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
	// �����ռ��п��Զ������/����/����
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
//	cout << lzb::a << lzb::b << endl;//����a��b
//	cout << lzb::lzb2::c << endl;//����c
//	return 0;
//}
