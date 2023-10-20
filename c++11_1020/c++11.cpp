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
//class Date {
//public:
//	Date(int year, int month, int day)
//		:_year(year), _month(month), _day(day) {
//		cout << "Date(int year,int month,int day) " << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main() {
//	//old style
//	Date d1(2023, 10, 18);
//	//c++11新增写法
//	Date d2{ 2023,10,17 };
//	Date d3 = { 2023,10,16 };
//	return 0;
//}


//std::initializer_list
//int main()
//{
//	// the type of il is an initializer_list
//	auto il = { 10, 20, 30 };
//	cout << typeid(il).name() << endl;
//	return 0;
//}
//使用场景
//std::initializer_list一般是作为构造函数的参数，C++11对STL中的不少容器就增加
//std::initializer_list作为参数的构造函数，这样初始化容器对象就更方便了。也可以作为operator =
//的参数，这样就可以用大括号赋值。

//int main()
//{
//	vector<int> v = { 1,2,3,4 };
//	list<int> lt = { 1,2 };
//	 这里{"sort", "排序"}会先初始化构造一个pair对象
//	map<string, string> dict = { {"sort", "排序"}, {"insert", "插入"} };
//	 使用大括号对容器赋值
//	v = { 10, 20, 30 };
//	return 0;
//}

namespace bit
{
	template<class T>
	class vector {
	public:
		typedef T* iterator;
		vector(initializer_list<T> l)
		{
			_start = new T[l.size()];
			_finish = _start + l.size();
			_endofstorage = _start + l.size();
			iterator vit = _start;
			typename initializer_list<T>::iterator lit = l.begin();
			while (lit != l.end())
			{
				*vit++ = *lit++;
			}
			//for (auto e : l)
			// *vit++ = e;
		}
		vector<T>& operator=(initializer_list<T> l) {
			vector<T> tmp(l);
			std::swap(_start, tmp._start);
			std::swap(_finish, tmp._finish);
			std::swap(_endofstorage, tmp._endofstorage);
			return *this;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
}

