#include <iostream>
using namespace std;

//����
//������������ڣ���������һ��ĵڼ��졣
//��֤���Ϊ4λ�������ںϷ���
//���ף�ʱ�临�Ӷȣ�
//O(n) ���ռ临�Ӷȣ�
//O(1)
//����������
//����һ�У�ÿ�пո�ָ�ֱ����꣬�£���
//���������
//�������һ��ĵڼ���


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

//����
//���������ڣ�����������֮�������������������������������ǹ涨����֮�������Ϊ����
//����������
//�ж������ݣ�ÿ�����������У��ֱ��ʾ�������ڣ���ʽΪYYYYMMDD
//���������
//ÿ���������һ�У������ڲ�ֵ

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
    //Ĭ�ϵ�һ������Ϊ��
    //MaxDate(year1,year2,month1,month2,day1,day2);
    if (!ismax(year1, month1, day1, year2, month2, day2))
    {
        Swap(year1, year2);
        Swap(month1, month2);
        Swap(day1, day2);
    }
    //С�����������ʹ��������Ϊֹ
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










//����
//�������m��һ���еĵ�n�죬�����n���Ǽ��¼��š�
//����������
//���������������y(1 <= y <= 3000)��n(1 <= n <= 366)��
//���������
//�����ж���������ݣ�����ÿ�����ݣ� �� yyyy - mm - dd�ĸ�ʽ�������ж�Ӧ�����ڴ�ӡ������
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

//��дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� s ����ʽ������
//��Ҫ�����������������Ŀռ䣬�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ���⡣

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

//����һ���ַ��� s ���ҵ� ���ĵ�һ�����ظ����ַ����������������� ����������ڣ��򷵻� - 1 ��
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