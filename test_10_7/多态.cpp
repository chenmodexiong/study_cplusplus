#include <iostream>
using namespace std;
//���ɶ�̬����������
//1. ����ͨ�������ָ��������õ����麯��
//2. �����õĺ����������麯���������������Ի�����麯��������д

//class Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
//};
//void Func(Person& p) {
//	p.BuyTicket();
//}
//int main() {
//	Person p;
//	Student st;
//	Func(p);
//	Func(st);
//	return 0;
//}
////////////////////////////////////////////////////////////////////////////////////////////
//Э��(�������������麯������ֵ���Ͳ�ͬ)
//��������д�����麯��ʱ��������麯������ֵ���Ͳ�ͬ���������麯�����ػ�������ָ
//��������ã��������麯����������������ָ���������ʱ����ΪЭ�䡣

//class A {};
//class B : public A {};
//class Person {
//public:
//	virtual A* f() { return new A; }
//};
//class Student : public Person {
//public:
//	virtual B* f() { return new B; }
//};

//������������д
//�����������������������������⴦���������������������ͳһ�����destructor

//class Person {
//public:
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//class Student : public Person {
//public:
//	virtual ~Student() { cout << "~Student()" << endl; }
//};
//int main() {
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	delete p1;
//	delete p2;
//}

//final�������麯������ʾ���麯�������ٱ���д
//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-����" << endl; }
//};

//
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//private:
//	int _b = 1;
//};
//int main() {
//	Base b;
//	cout << sizeof(Base) << endl;
//	return 0;
//}

//�����е����ָ�����ǽ����麯����ָ��(v����virtual��f����function)��
//һ�������麯�������ж����ٶ���һ���麯����ָ�룬��Ϊ�麯��
//�ĵ�ַҪ���ŵ��麯�����У��麯����Ҳ������


class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
	void Func3()
	{
		cout << "Base::Func3()" << endl;
	}
private:
	int _b = 1;
};

class Derive : public Base
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	}
private:
	int _d = 2;
};
int main()
{
	Base b;
	Derive d;
	return 0;
}