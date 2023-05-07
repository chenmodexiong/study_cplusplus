#include <iostream>
using namespace std;

//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << "Print()" << endl;
//		cout << "year:" << _year << endl;
//		cout << "month:" << _month << endl;
//		cout << "day:" << _day << endl << endl;
//	}
//	void Print() const
//	{
//		cout << "Print()const" << endl;
//		cout << "year:" << _year << endl;
//		cout << "month:" << _month << endl;
//		cout << "day:" << _day << endl << endl;
//	}
//private:
//	int _year; // Äê
//	int _month; // ÔÂ
//	int _day; // ÈÕ
//};
//
//void Test()
//{
//	Date d1(2022, 1, 13);
//	d1.Print();
//	const Date d2(2022, 1, 13);
//	d2.Print();
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

class Date
{
public:
	Date& operator& ()
	{
		return *this;
	}
	const Date& operator&() const 
	{
		return *this;
	}
private:
	int _year;
	int _month;
	int _day;
};












