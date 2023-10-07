#include <iostream>
using namespace std;
//构成多态的两个条件
//1. 必须通过基类的指针或者引用调用虚函数
//2. 被调用的函数必须是虚函数，且派生类必须对基类的虚函数进行重写

//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
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
//协变(基类与派生类虚函数返回值类型不同)
//派生类重写基类虚函数时，与基类虚函数返回值类型不同。即基类虚函数返回基类对象的指
//针或者引用，派生类虚函数返回派生类对象的指针或者引用时，称为协变。

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

//析构函数的重写
//编译器对析构函数的名称做了特殊处理，编译后析构函数的名称统一处理成destructor

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

//final：修饰虚函数，表示该虚函数不能再被重写
//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-舒适" << endl; }
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

//对象中的这个指针我们叫做虚函数表指针(v代表virtual，f代表function)。
//一个含有虚函数的类中都至少都有一个虚函数表指针，因为虚函数
//的地址要被放到虚函数表中，虚函数表也简称虚表


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