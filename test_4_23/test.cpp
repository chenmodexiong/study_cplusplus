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
			perror("malloc����ռ�ʧ��");
			return;
		}
		_capacity = capacity;
		_size = 0;
	}
	void Push(const DataType& data)
	{
		// ����
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
// ������Ҫָ��PrintPersonInfo������Person�������
void Person::PrintPersonInfo()
{
	cout << _name << " " << _gender << " " << _age << endl;
}


//int main()
//{
//	Person._age = 100; // ����ʧ�ܣ�error C2059: �﷨����:��.��
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

// ���м��г�Ա���������г�Ա����
class A1 {
public:
	void f1() {}
private:
	int _a;
};
//����ֻ�г�Ա����
class A2 {
public:
	void f2(){}
};
//����ʲô��û�У�����
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
//	int _year; // ��
//	int _month; // ��
//	int _day; // ��
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
	int _year; // ��
	int _month; // ��
	int _day; // ��
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


// 1.�������������н���ǣ� A�����뱨�� B�����б��� C����������
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

// 1.�������������н���ǣ� A�����뱨�� B�����б��� C����������
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