#include <iostream>
using namespace std;

//描述
//根据输入的日期，计算是这一年的第几天。
//保证年份为4位数且日期合法。
//进阶：时间复杂度：
//O(n) ，空间复杂度：
//O(1)
//输入描述：
//输入一行，每行空格分割，分别是年，月，日
//输出描述：
//输出是这一年的第几天


int main()
{                       //1,2,3,4,5,6,7,8,9,10,11,12                
    int date[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    int count = 0;
    int year = 0, month = 0, day = 0;
    cin >> year >> month >> day;
    if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0))
    {
        date[2] += 1;
        for (int i = 1; i < month; ++i)
        {
            count += date[i];
        }
        count += day;
    }
    else
    {
        for (int i = 1; i < month; ++i)
        {
            count += date[i];
        }
        count += day;
    }
    cout << count << endl;
}

//描述
//有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天
//输入描述：
//有多组数据，每组数据有两行，分别表示两个日期，形式为YYYYMMDD
//输出描述：
//每组数据输出一行，即日期差值

#include <iostream>
using namespace std;
bool IsLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    else
        return false;
}
int GetMonthDay(int year, int month)
{
    int date[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    if (IsLeapYear(year) && month == 2)
        return date[month] + 1;
    else
        return date[month];
}
void Swap(int& d1, int& d2)
{
    int tmp = d1;
    d1 = d2;
    d2 = tmp;
}
bool ismax(int year1, int month1, int day1, int year2, int month2, int day2)
{
    if (year1 > year2)
        return true;
    else if (year1 == year2)
    {
        if (month1 > month2)
            return true;
        else if (month1 == month2)
        {
            if (day1 > day2)
                return true;
        }
    }
    return false;
}
int main()
{
    int year1, month1, day1;
    int year2, month2, day2;
    scanf("%4d%2d%2d", &year1, &month1, &day1);
    scanf("%4d%2d%2d", &year2, &month2, &day2);
    //默认第一个日期为大
    //MaxDate(year1,year2,month1,month2,day1,day2);
    if (!ismax(year1, month1, day1, year2, month2, day2))
    {
        Swap(year1, year2);
        Swap(month1, month2);
        Swap(day1, day2);
    }
    //小的日期自增和大日期相等为止
    int count = 1;
    while (year1 != year2 || month1 != month2 || day1 != day2)
    {
        ++count;
        ++day2;
        if (day2 > GetMonthDay(year2, month2))
        {
            day2 = 1;
            month2++;
            if (month2 > 12)
            {
                month2 = 1;
                year2++;
            }
        }
    }
    cout << count << endl;
}










//描述
//给出年分m和一年中的第n天，算出第n天是几月几号。
//输入描述：
//输入包括两个整数y(1 <= y <= 3000)，n(1 <= n <= 366)。
//输出描述：
//可能有多组测试数据，对于每组数据， 按 yyyy - mm - dd的格式将输入中对应的日期打印出来。
#include <iostream>
using namespace std;
bool IsLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    else
        return false;
}
int GetMonthDay(int year, int month)
{
    int date[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    if (IsLeapYear(year) && month == 2)
        return date[month] + 1;
    else
        return date[month];
}
int main()
{
    int year, n, day;
    while ((scanf("%d %d", &year, &n)) != EOF)
    {
        int month = 0;
        while (n > GetMonthDay(year, month))
        {
            n -= GetMonthDay(year, month);
            ++month;
        }
        day = n;
        printf("%04d-%02d-%02d\n", year, month, day);
    }
    return 0;
}


// int daytable[2][13]{
//     {0,31,28,31,30,31,30,31,31,30,31,30,31},
//     {0,31,29,31,30,31,30,31,31,30,31,30,31}
// };
// int main() 
// {
//     int year,days;
//     while((scanf("%d %d",&year,&days))!=EOF)
//     {
//         int leap=((year%4==0 && year%100!=0) || (year%400==0));
//         int month=0;
//         while(days>daytable[leap][month])
//         {
//             days-=daytable[leap][month];
//             ++month;
//         }
//         printf("%04d-%02d-%02d\n",year,month,days);
//     }
//     return 0;
// }

//编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
//不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

class Solution {
public:
    void reverseString(vector<char>& s)
    {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
        {
            swap(s[i], s[j]);
        }
    }
};

//给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 - 1 。
class Solution 
{
public:
    int firstUniqChar(string s)
    {
        for (int i = 0; i < s.size(); ++i)
        {
            if (s.find(s[i]) == s.rfind(s[i]))
                return i;
        }
        return -1;
    }
};