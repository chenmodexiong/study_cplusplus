#pragma once
#include <assert.h>
#include <iostream>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream& out, Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	//���캯��
	Date(int year, int month, int day);
	//��������
	Date(const Date& d);
	//��ֵ���������
	Date& operator=(const Date& d);
	//����
	~Date() {};
	//��ӡ
	void Show()
	{
		cout << _year << "��" << _month << "��" << _day << "��" << endl;
	}
	int GetMonthDay(const int year, const int month);

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
	Date operator++(int);
	//ǰ��--
	Date& operator--();
	//����--
	Date operator--(int);

	//����-���ڣ���������
	int operator-(const Date& d);

private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& out, Date& d);
ostream& operator>>(ostream& in, Date& d);

