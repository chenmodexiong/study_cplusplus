
//牛客 ：： KY258 日期累加
//描述
//设计一个程序能计算一个日期加上若干天后是什么日期。
//输入描述：
//输入第一行表示样例个数m，接下来m行每行四个整数分别表示年月日和累加的天数。
//输出描述：
//输出m行，每行按yyyy - mm - dd的个数输出。
//输入：
//1
//2008 2 3 100
//输出：
//2008 - 05 - 13

#include <climits>
#include <iomanip>
#include <iostream>
#include <istream>
#include <ostream>
using namespace std;
class Date
{
    friend ostream& operator<<(ostream& out, const Date& d);
    friend istream& operator>>(istream& in, Date& d);
public:
    int GetMonthDay(const int year, const int month);
    Date(int year = 1, int month = 1, int day = 1)
        :_year(year), _month(month), _day(day)
    {};
    Date& operator+(int num)
    {
        _day += num;
        while (_day > GetMonthDay(_year, _month))
        {
            _day -= GetMonthDay(_year, _month);
            _month += 1;
            if (_month == 13)
            {
                _year += 1;
                _month = 1;
            }
        }
        return *this;
    }
private:
    int _year;
    int _month;
    int _day;
};
int Date::GetMonthDay(const int year, const int month)
{
    static int date[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    if (month == 2 && ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)))
        return 29;
    else
        return date[month];
}
ostream& operator<<(ostream& out, const Date& d)
{
    //printf("%d-%02d-%02d\n",d._year,d._month,d._day);
    cout << d._year << '-' << setw(2) << setfill('0') << d._month << '-' << setw(2) << setfill('0') << d._day << endl;
    return out;
}
istream& operator>>(istream& in, Date& d)
{
    in >> d._year >> d._month >> d._day;
    return in;
}
int main()
{
    int i = 0;
    cin >> i;
    Date d1;
    for (int j = 1; j <= i; j++)
    {
        int m = 0;
        cin >> d1 >> m;
        cout << d1 + m;
    }
}










