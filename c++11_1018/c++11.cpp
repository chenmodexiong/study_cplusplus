#include <iostream>
using namespace std;

//列表初始化
//struct Point
//{
//	int _x;
//	int _y;
//};
//int main()
//{
//	int array1[] = { 1, 2, 3, 4, 5 };
//	int array2[5] = { 0 };
//	Point p = { 1, 2 };
/////////////////////////////////////////////////
//	int array3[]{ 1,2,3,4,5 };
//	int array4[10]{ 0 };
//	Point p2{ 1,2 };
//	int x{ 2 };
//	int* pa = new int[4] {0};
//	return 0;
//}
//构造函数也可列表初始化
class Date {
public:
	Date(int year,int month,int day) 
		:_year(year), _month(month),_day(day) {
		cout << "Date(int year,int month,int day) " << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};
int main() {
	//old style
	Date d1(2023, 10, 18);
	//c++11新增写法
	Date d2{ 2023,10,17 };
	Date d3 = { 2023,10,16 };
	return 0;
}


//std::initializer_list

int main() {


	return 0;
}
