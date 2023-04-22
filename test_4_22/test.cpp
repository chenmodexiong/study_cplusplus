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
			perror("malloc…Í«Îø’º‰ ß∞‹");
			return;
		}
		_capacity = capacity;
		_size = 0;
	}
	void Push(const DataType& data)
	{
		// ¿©»›
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

#include "test.h"

void Person::Print()
{
	cout << _name << _sex << _age << endl;
}

class Date
{
public:
	void Init(int year)
	{
		_year = year;
	}
private:
	int _year;
};

class Date
{
public:
	void Init(int year)
	{
		mYear = year;
	}
private:
	int mYear;
};



