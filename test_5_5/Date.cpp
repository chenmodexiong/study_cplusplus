#include "Date.h"

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

bool Date::operator<(const Date& d)
{
	if (_year < d._year)
		return true;
	else if (_year == d._year && _month < d._month)
		return true;
	else if (_year == d._year && _month == d._month && _day < d._day)
		return true;
	else
		return false;
}

bool Date::operator==(const Date& d)
{
	if (_year == d._year && _month == d._month && _day == d._day)
		return true;
	else
		return false;
}

bool Date::operator<=(const Date& d)
{
	return *this < d || *this == d;
}

bool Date::operator>(const Date& d)
{
	return !(*this <= d);
}

bool Date::operator>=(const Date& d)
{
	return !(*this < d);
}

bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

//两处优化
int GetMonthDay(const int year,const int month)
{
	static int date[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		return 29;
	else
		return date[month];
}

Date& Date::operator+=(const int day)
{
	_day += day;
	int curdays = GetMonthDay(_year, _month);
	if (_day>curdays)
	{
		_day -= curdays;
		++_month;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}
	return *this;
}

Date Date::operator+(const int day)
{
	Date temp(*this);
	temp += day;
	return temp;
}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date& Date::operator++(int)
{
	Date temp(*this);
	*this += 1;
	return temp;
}

int Date::operator-(const Date& d)
{
	
}




