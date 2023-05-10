#include <iostream>
using namespace std;

//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};


//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year),_month(month),_day(day)
//	{
//		//一系列操作
//		//.....
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date a(2023,5,10);
//	return 0;
//}

//class B
//{
//public:
//	B(int a)
//		:_a(a)
//	{
//		_b = 10;
//	}
//private:
//	int _a;
//	int _b;
//};
//class A
//{
//public:
//	A(int& a,int b)
//		:_a(a),_b(b)/*_bb1(2)*/
//	{
//		//....
//	}
//private:
//	int& _a;
//	const int _b;
//	B _bb1;
//};
//int main()
//{
//	int tmp = 10;
//	A a(tmp, 20);
//	return 0;
//}
// 
//
//class B
//{
//public:
//	B()
//	{
//		cout << "you can see me" << endl;
//	}
//private:
//	int _a;
//	int _b;
//};
//class A
//{
//public:
//	A(int& a, int b)
//		:_a(a), _b(b)
//	{
//		//....
//	}
//private:
//	int& _a;
//	const int _b;
//	B _bb1;
//};
//int main()
//{
//	int tmp = 10;
//	A a(tmp, 20);
//	return 0;
//}

//class A
//{
//public:
//	A(int a)
//		:_a(a), _b(_a)
//	{
//		//.....
//	}
//	void show()
//	{
//		cout << _a << ' ' << _b << endl;
//	}
//private:
//	int _b;
//	int _a;
//};
//int main()
//{
//	A a(10);
//	a.show();
//	//请问输出什么？
//	return 0;
//}

//
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//		:_size(0),_capacity(capacity)
//	{
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");
//			exit(-1);
//		}
//		memset(_array,0,sizeof(DataType) * capacity);
//	}
//
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//
//private:
//	DataType* _array;
//	size_t _size;
//	size_t _capacity;
//};
//

//class Date
//{
//public:
//	/*explicit*/ Date(int year,int month=1,int day=1)
//		:_year(year),_month(month),_day(day)
//	{
//		//.......
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2023);
//	d1 = 10;
//	return 0;
//}

//class Date
//{
//public:
//	/*explicit*/ Date(int year,int month=1,int day=1)
//		:_year(year),_month(month),_day(day)
//	{
//		cout << "我是构造函数" << endl;
//	}
//	Date(const Date& d)
//	{
//		cout << "我是拷贝构造函数" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2023);
//	d1 = 10;
//	return 0;
//}

//class A
//{
//public:
//	A()
//	{
//		++_count;
//	}
//	A(const A& d)
//	{
//		++_count;
//	}
//	static void show()
//	{
//		cout << _count << endl;
//	}
//private:
//	int _a;
//	int _b;
//	static int _count;
//};
//int A::_count = 0;
//
//A aa2;
//int main()
//{
//	A aa1;
//	A::show();
//	A aa3(aa1);
//	A::show();
//	return 0;
//}
//
//class A
//{
//public:
//	A()
//	{
//		++_count;
//	}
//	A(const A& d)
//	{
//		++_count;
//	}
//	void Test()
//	{
//		show();
//		cout << "test" << endl;
//	}
//	static void show()
//	{
//		/*Test();*/
//		cout << _count << endl;
//	}
//private:
//	int _a;
//	int _b;
//	static int _count;
//};
//int A::_count = 0;



class Sum
{
public:
	Sum()
	{
		_ret += _i;
		++_i;
	}
	static int GetCount()
	{
		return _ret;
	}
private:
	static int _ret;
	static int _i;
};
int Sum::_ret = 0;
int Sum::_i = 1;

class Solution
{
public:
	int Sum_Solution(int n)
	{
		Sum a[n];
		return Sum::GetCount();
	}
};





