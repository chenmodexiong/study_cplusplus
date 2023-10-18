#include <iostream>
using namespace std;
bool IsLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    else
        return false;
}
int day_gol[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int GetDay(int year, int month, int day) {
    int num = 0;
    for (int i = 1; i < month; ++i) {
        num += day_gol[month];
    }
    num += day;
    if (month > 2 && IsLeapYear(year)) {
        num += 1;
    }
    return num;
}
int main() {
    int year, month, day;
    cin >> year >> month >> day;
    int ret = GetDay(year, month, day);
    cout << ret << endl;
    return 0;
}