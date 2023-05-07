#include "Date.h"

Date::Date(int year = 0, int month = 0, int day = 0)
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
	return *this;
}

bool Date::operator<(const Date& d) const
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

bool Date::operator==(const Date& d) const
{
	if (_year == d._year && _month == d._month && _day == d._day)
		return true;
	else
		return false;
}

bool Date::operator<=(const Date& d) const
{
	return *this < d || *this == d;
}

bool Date::operator>(const Date& d) const
{
	return !(*this <= d);
}

bool Date::operator>=(const Date& d) const
{
	return !(*this < d);
}

bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

//两处优化
int Date::GetMonthDay(const int year, const int month)
{
	static int date[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)))
		return 29;
	else
		return date[month];
}

Date& Date::operator+=(const int day) 
{
	if (day < 0)
	{
		return *this -= day;
	}

	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}
	return *this;
}

Date Date::operator+(const int day) const
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

Date Date::operator++(int)
{
	Date temp(*this);
	*this += 1;
	return temp;
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)
{
	Date temp(*this);
	*this -= 1;
	return temp;
}

//Date& Date::operator--()
//{
//	_day -= 1;
//	if (_day < 1)
//	{
//		_month -= 1;
//		_day += GetMonthDay(_year, _month);
//		if (_month < 1)
//		{
//			_year -= 1;
//			_month = 12;
//		}
//	}
//	return *this;
//}

Date& Date::operator-=(const int day)
{
	if (day > 0)
	{
		return *this += day;
	}

	_day -= day;
	while (_day < 1)
	{
		--_month;
		if (_month < 1)
		{
			_month = 12;
			--_year;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

Date Date::operator-(const int day) const
{
	Date temp(*this);
	temp -= day;
	return temp;
}

int Date::operator-(const Date& d) const
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (max < min)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int count = 0;
	while (min != max)
	{
		++min;
		++count;
	}
	return count * flag;
}

ostream& operator<<(ostream& out, Date& d) 
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return out;
}

istream& operator>>(istream& in, Date& d) 
{
	cout << "Please Enter date:>" << endl;
	int year, month, day;
	in >> year >> month >> day;
	if (month > 0 && month < 13
		&& day > 0 && day <= d.GetMonthDay(year, month))
	{
		d._year = year;
		d._month = month;
		d._day = day;
	}
	else
	{
		cout << "非法日期" << endl;
		assert(false);
	}
	return in;

	/*in >> d._year >> d._month >> d._day;
	return in;*/
}







