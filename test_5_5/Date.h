#pragma once

#include <iostream>
using namespace std;

class Date
{
public:
	//构造函数
	Date(int year, int month, int day);
	//拷贝构造
	Date(const Date& d);
	//赋值运算符重载
	Date& operator=(const Date& d);
	//析构
	~Date() {};

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
	Date& operator++(int);

	//日期-日期，返回天数
	int operator-(const Date& d);

private:
	int _year;
	int _month;
	int _day;
};
