#include <iostream>
using namespace std;

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year), _month(month), _day(day)
//	{
//		//....
//	}
//	ostream& operator<<(ostream& out)
//	{
//		out << _year << ' ' << _month << ' ' << _day << endl;
//		return out;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2023, 5, 13);
//	d1 << cout;
//	d1.operator<<(cout);
//	return 0;
//}

//class Date
//{
//	friend ostream& operator<<(ostream& out, const Date& d);
//	friend istream& operator>>(istream& in, Date& d);
//public:
//	Date(int year, int month, int day)
//		:_year(year), _month(month), _day(day)
//	{
//		//....
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//ostream& operator<<(ostream& out,const Date& d)
//{
//	out << d._year << ' ' << d._month << ' ' << d._day << endl;
//	return out;
//}
//istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	return in;
//}
//
//int main()
//{
//	Date d1(2023, 5, 13);
//	cout << d1;
//	cin >> d1;
//	cout << d1;
//	return 0;
//}

//class A
//{
//	friend class C;
//public:
//	class B
//	{
//	public:
//		void show(const A& d)
//		{
//			cout << d._a << ' ' << _b << endl;
//		}
//	};
//private:
//	int _a = 1;
//	static int _b;
//};
//class C
//{
//	void show(const A& d)
//	{
//		cout << d._a << ' ' << d._b << endl;
//	}
//};
//int A::_b = 10;
//
//int main()
//{
//	A::B b;
//	b.show(A());
//	cout << sizeof(A) << endl;
//	return 0;
//}

//class A
//{
//public:
//	void show()
//	{
//		cout << _a << _b << endl;
//	}
//private:
//	int _a = 10;
//	int _b = 20;
//};
//
//int main()
//{
//	A().show();
//	return 0;
//}

//class A
//{
//public:
//	A(int a = 0, int b = 0)
//		:_a(a), _b(b)
//	{
//		cout << "我是构造函数" << endl;
//	}
//	A(const A& d)
//	{
//		_a = d._a;
//		_b = d._b;
//		cout << "我是拷贝构造" << endl;
//	}
//	~A()
//	{
//		cout << "我是析构函数" << endl;
//	};
//	A& operator=(const A& d)
//	{
//		cout << "我是赋值重载" << endl;
//		_a = d._a;
//		_b = d._b;
//		return *this;
//	}
//private:
//	int _a;
//	int _b;
//};
//A BuyA()
//{
//	A aa;
//	return aa;
//}
//A& BuyB()
//{
//	A aa;
//	return aa;
//}
//
//int main()
//{
//	A a1;
//	a1 = BuyA();
//	cout << "=============" << endl;
//	A a2 = BuyA();
//	cout << "=============" << endl;
//	A a3 = BuyB();
//	return 0;
//}


class A
{
public:
	A(int a = 0, int b = 0)
		:_a(a), _b(b)
	{
		cout << "我是构造函数" << endl;
	}
	A(const A& d)
	{
		_a = d._a;
		_b = d._b;
		cout << "我是拷贝构造" << endl;
	}
	~A()
	{
		cout << "我是析构函数" << endl;
	};
	A& operator=(const A& d)
	{
		cout << "我是赋值重载" << endl;
		_a = d._a;
		_b = d._b;
		return *this;
	}
private:
	int _a;
	int _b;
};
void BuyA(A aa)
{
	
}

int main()
{
	BuyA(A(1,1));
	cout << "============" << endl;
	A aa;
	aa = 1;
	BuyA(aa);

	return 0;
}








