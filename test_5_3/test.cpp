#include <iostream>
using namespace std;

//class Date
//{
//public:
//	void Show(int a=10)
//	{
//		cout << a << endl;
//		cout << _year << ' ' << _month;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//int main()
//{
//	Date d1;
//	d1.Show();
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	// Date(const Date& d) // ��ȷд��
//	Date(const Date& d) // ����д�������뱨������������ݹ�
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	Date d2(d1);
//	return 0;
//}

//class Stack
//{
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//class Date
//{
//private:
//	// ��������(��������)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//	Stack st1;
//};
//int main()
//{
//	Date d1;
//	// ���Ѿ����ڵ�d1��������d2���˴������Date��Ŀ������캯��
//	// ��Date�ಢû����ʽ���忽�����캯��������������Date������һ��Ĭ�ϵĿ������캯��
//	Date d2(d1);
//	return 0;
//}

//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc����ռ�ʧ��");
//			return;
//		}
//		//ע�⣺�������û���漰��Դ����ʱ���������캯���Ƿ�д�����ԣ�
//		//һ���漰����Դ����ʱ���򿽱����캯����һ��Ҫд�ģ��������ǳ������
//		_size = 0;
//		_capacity = capacity;
//	}
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
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
//private:
//	DataType* _array;
//	size_t _size;
//	size_t _capacity;
//};
//int main()
//{
//	Stack s1;
//	s1.Push(1);
//	s1.Push(2);
//	s1.Push(3);
//	s1.Push(4);
//	Stack s2(s1);
//	return 0;
//}

// ȫ�ֵ�operator
// �Ƚ����ڴ�С
//class Date
//{
//public:
//	Date(int year = 0,int month=0,int day=0)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	int _year;
//	int _month;
//	int _day;
//};
//bool operator < (const Date& d1,const Date& d2)
//{
//	if (d1._year < d2._year)
//		return true;
//	else if (d1._year == d2._year && d1._month < d2._month)
//		return true;
//	else if (d1._year == d2._year && d1._month == d2._month && d1._day < d2._day)
//		return true;
//	else
//		return false;
//}
//bool operator > (const Date& d1,const Date& d2)
//{
//	if (d1._year > d2._year)
//		return true;
//	else if (d1._year == d2._year && d1._month > d2._month)
//		return true;
//	else if (d1._year == d2._year && d1._month == d2._month && d1._day > d2._day)
//		return true;
//	else
//		return false;
//}
//int main()
//{
//	Date d1(2023, 12, 10);
//	Date d2(2022, 12, 10);
//	cout << (d1 < d2) << endl;
//	cout << (d1 > d2) << endl;
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 0, int month = 0, int day = 0)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	bool operator < (const Date& d)
//	{
//		if (_year < d._year)
//			return true;
//		else if (_year == d._year && _month < d._month)
//			return true;
//		else if (_year == d._year && _month == d._month && _day < d._day)
//			return true;
//		else
//			return false;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2021, 12, 10);
//	Date d2(2022, 12, 10);
//	cout << (d1 < d2) << endl;
//	cout << d1.operator<(d2);
//	return 0;
//}


//class Date
//{
//public:
//	Date(int year = 0, int month=0, int day=0)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	/*ע����δ����е�ϸ��*/
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2023, 5, 3);
//	Date d2(2020, 3, 3);
//	Date d3(2022, 6, 6);
//	d1 = d2 = d3;
//	return 0;
//}

class Time
{
public:
	Time()
	{
		_hour = 10;
		_minute = 10;
		_second = 10;
	}
	Time& operator=(const Time& t)
	{
		if (this != &t)
		{
			_hour = t._hour;
			_minute = t._minute;
			_second = t._second;
		}
		return *this;
	}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	Date(int year = 0, int month=0, int day=0)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};
int main()
{
	Date d1(2020, 2, 2);
	Date d2(2021, 3, 3);
	d1 = d2;
	return 0;
}







