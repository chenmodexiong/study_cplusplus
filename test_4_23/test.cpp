#include <iostream>
using namespace std;

typedef int DataType;
//struct Stack
class Stack
{
	void Init(size_t capacity)
	{
		_array = (DataType*)malloc(sizeof(DataType) * capacity);
		if (nullptr == _array)
		{
			perror("malloc申请空间失败");
			return;
		}
		_capacity = capacity;
		_size = 0;
	}
	void Push(const DataType& data)
	{
		// 扩容
		_array[_size] = data;
		++_size;
	}
	DataType Top()
	{
		return _array[_size - 1];
	}
	void Destroy()
	{
		if (_array)
		{
			free(_array);
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}
	DataType* _array;
	size_t _capacity;
	size_t _size;
};

//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << _sex << _age << endl;
//	}
//private:
//	char* _name;
//	char* _sex;
//	int _age;
//};


//void Person::Print()
//{
//	cout << _name << _sex << _age << endl;
//}

//class Date
//{
//public:
//	void Init(int year)
//	{
//		_year = year;
//	}
//private:
//	int _year;
//};
//
//class Date
//{
//public:
//	void Init(int year)
//	{
//		mYear = year;
//	}
//private:
//	int mYear;
//};

class Person
{
public:
	void PrintPersonInfo();
private:
	char _name[20];
	char _gender[3];
	int _age;
};
// 这里需要指定PrintPersonInfo是属于Person这个类域
void Person::PrintPersonInfo()
{
	cout << _name << " " << _gender << " " << _age << endl;
}


//int main()
//{
//	Person._age = 100; // 编译失败：error C2059: 语法错误:“.”
//	return 0;
//}

//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//private:
//	char _a;
//};
//
//int main()
//{
//	A a;
//	cout << sizeof(a) << endl;
//	cout << sizeof(A) << endl;
//	return 0;
//}


//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//private:
//	char _a;
//	int _b;
//};
//
//int main()
//{
//	A a;
//	cout << sizeof(a) << endl;
//	cout << sizeof(A) << endl;
//	return 0;
//}

// 类中既有成员变量，又有成员函数
class A1 {
public:
	void f1() {}
private:
	int _a;
};
//类中只有成员函数
class A2 {
public:
	void f2(){}
};
//类中什么都没有，空类
class A3 {

};
//int main()
//{
//	cout << sizeof(A1) << endl;
//	cout << sizeof(A2) << endl;
//	cout << sizeof(A3) << endl;
//	return 0;
//}

//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year; // 年
//	int _month; // 月
//	int _day; // 日
//};
//int main()
//{
//	Date d1, d2;
//	d1.Init(2023, 4, 11);
//	d2.Init(2023, 4, 22);
//	d1.Print();
//	d2.Print();
//	return 0;
//}

class Date
{
public:
	void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
	}
private:
	int _year; // 年
	int _month; // 月
	int _day; // 日
};
//int main()
//{
//	Date d1, d2;
//	d1.Init(2023, 4, 11);
//	d2.Init(2023, 4, 22);
//	d1.Print();
//	d2.Print();
//	return 0;
//}


// 1.下面程序编译运行结果是？ A、编译报错 B、运行崩溃 C、正常运行
//class A
//{
//public:
//	void Print()
//	{
//		cout << "Print()" << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->Print();
//	return 0;
//}

// 1.下面程序编译运行结果是？ A、编译报错 B、运行崩溃 C、正常运行
//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->PrintA();
//	return 0;
//}

class lzb
{
public:
	void Print()
	{
		cout << "hello" << endl;
	}
private:
	int a;
	Date st;
};
int main()
{
	lzb d1;
	return 0;
}