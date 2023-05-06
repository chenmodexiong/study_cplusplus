#pragma once
#include <assert.h>
#include <iostream>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream& out, Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	//构造函数
	Date(int year, int month, int day);
	//拷贝构造
	Date(const Date& d);
	//赋值运算符重载
	Date& operator=(const Date& d);
	//析构
	~Date() {};
	//打印
	void Show()
	{
		cout << _year << "年" << _month << "月" << _day << "日" << endl;
	}
	int GetMonthDay(const int year, const int month);

	// < 运算符重载
	bool operator<(const Date& d);
	// == 运算符重载
	bool operator==(const Date& d);
	// <= 运算符重载
	bool operator<=(const Date& d);
	// > 运算符重载
	bool operator>(const Date& d);
	// >= 运算符重载
	bool operator>=(const Date& d);
	// != 运算符重载
	bool operator!=(const Date& d);
	
	//日期+=天数
	Date& operator+=(const int day);
	//日期+天数
	Date operator+(const int day);
	//日期-天数
	Date operator-(const int day);
	//日期-=天数
	Date& operator-=(const int day);

	//前置++
	Date& operator++();
	//后置++
	Date operator++(int);
	//前置--
	Date& operator--();
	//后置--
	Date operator--(int);

	//日期-日期，返回天数
	int operator-(const Date& d);

private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& out, Date& d);
ostream& operator>>(ostream& in, Date& d);

