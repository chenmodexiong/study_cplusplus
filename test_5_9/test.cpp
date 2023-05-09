#include <iostream>
using namespace std;

//class Date
//{
//public:
//	//初始化列表
//	Date() :_year(2020), _month(1), _day(1)
//	{}
//	/*Date() :_year(2020), _month(1), _day(1)
//	{
//		_year = 2020;
//		_month = 1;
//		_day = 1;
//	}*/
//private:
//	int _year;
//	int _month;
//	int _day;
//};


//class Date
//{
//public:
//	//初始化列表
//	Date(int year=2023,int month=1,int day=1) 
//		:_year(year), _month(month), _day(day)
//	{
//		//.....
//	}
//
//	/*Date() :_year(2020), _month(1), _day(1)
//	{
//		//......
//	}*/
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//必须放在初始化列表的三类变量
//1.引用成员变量
//2.const成员变量
//3.自定义类型成员(且该类没有默认构造函数时)

//class Time
//{
//public:
//	Time(int aa1):_hour(aa1),_min(1),_sec(1)
//	{
//		cout << "you can see me" << endl;
//	}
//private:
//	int _hour;
//	int _min;
//	int _sec;
//};
//
//class A
//{
//public:
//	/*A(int a,int& ref):_a(a),_b(ref),_t()
//	{
//		
//	}*/
//
//private:
//	const int _a;
//	int& _b;
//	Time _t;
//};
//
//void Test()
//{
//	int a = 20;
//	A a1(1,a);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}



//class A
//{
//public:
//	A(int a):_a1(a),_a2(_a1)
//	{
//
//	}
//	void Print() 
//	{
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
//int main() 
//{
//	A aa(1);
//	aa.Print();
//}

//class A
//{
//public:
//	/*explicit*/ A(int a):_a1(a),_a2(_a1)
//	{}
//	void Print() 
//	{
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a1;
//	int _a2;
//};
//int main() 
//{
//	A a1(1);
//	a1 = 2023;
//
//	return 0;
//}

//static静态成员

class A
{
public:
	A() 
	{
		++_scount; 
	}
	A(const A& t) 
	{ 
		++_scount;
	}
	~A() 
	{
		--_scount; 
	}
	static int GetACount() 
	{ 
		return _scount; 
	}
private:
	static int _scount;
};

int A::_scount = 0;
A aa1;

void TestA()
{
	cout << A::GetACount() << endl;
	A a1, a2;
	A a3(a1);
	cout << A::GetACount() << endl;
}

int main()
{
	TestA();
	return 0;
}

