#pragma once

#include <iostream>
using namespace std;

class Date
{
public:
	//���캯��
	Date(int year, int month, int day);
	//��������
	Date(const Date& d);
	//��ֵ���������
	Date& operator=(const Date& d);
	//����
	~Date() {};

	// < ���������
	bool operator<(const Date& d);
	// == ���������
	bool operator==(const Date& d);
	// <= ���������
	bool operator<=(const Date& d);
	// > ���������
	bool operator>(const Date& d);
	// >= ���������
	bool operator>=(const Date& d);
	// != ���������
	bool operator!=(const Date& d);
	
	//����+=����
	Date& operator+=(const int day);
	//����+����
	Date operator+(const int day);
	//����-����
	Date operator-(const int day);
	//����-=����
	Date& operator-=(const int day);

	//ǰ��++
	Date& operator++();
	//����++
	Date& operator++(int);

	//����-���ڣ���������
	int operator-(const Date& d);

private:
	int _year;
	int _month;
	int _day;
};
