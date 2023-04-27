#include <iostream>
using namespace std;


//class Date
//{
//	int year;
//	int month;
//	int day;
//};
//
//class Stack
//{
//public:
//	//构造函数，不带缺省值
//	/*Stack()
//	{
//		int* _a = (int*)malloc(sizeof(int) * 4);
//		if (_top == _capacity)
//		{
//			int* _tmp = (int*)realloc(_a, sizeof(int) * 4);
//			if (_tmp != nullptr)
//				_a = _tmp;
//		}
//		_top = 0;
//		_capacity = 4;
//	}*/
//
//	//构造函数，带缺省值
//	Stack(int capacity=4)
//	{
//		int* _a = (int*)malloc(sizeof(int) * capacity);
//		if (_top == _capacity)
//		{
//			int* _tmp = (int*)realloc(_a, sizeof(int) * capacity);
//			if (_tmp != nullptr)
//				_a = _tmp;
//		}
//		_top = 0;
//		_capacity = capacity;
//	}
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//	Date d1;
//};


//int main()
//{
//	Stack s1;
//	//Stack s2(10);
//	return 0;
//}


//class Date
//{
//public:
//	void Init(int year,int month,int day)
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
//int main()
//{
//	Date d1;
//	d1.Init(2023, 4, 27);
//	//...使用
//	Date d2;
//	d2.Init(2022, 2, 22);
//	//...
//	return 0;
//}


//class Date
//{
//public:
//	Date()
//	{
//		cout << "hello structure funtion!!!" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int day;
//};
//
//int main()
//{
//	Date d1;
//	return 0;
//}

//struct Stack
//{
//	int* _a = nullptr;
//	int _top;
//	int _capacity;
//};
//class Date
//{
//public:
//	void Print()
//	{
//		cout << _year << ' ' << _month << ' ' << _day << endl;
//		cout << _s1._a << ' ' << _s1._capacity << ' ' << _s1._top << endl;
//	}
//private:
//	int _year;
//	int _month=10;
//	int _day;
//	Stack _s1;
//};
//int main()
//{
//	Date d1;
//	d1.Print();
//	return 0;
//}


//class Stack
//{
//	int* _a = nullptr;
//	int _top = 0;
//	int _capacity = 4;
//};
////等价于
//class Stack
//{
//public:
//	Stack()
//	{
//		_a = nullptr;
//		_top = 0;
//		_capacity = 4;
//	}
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};

//struct TreeNode
//{
//	TreeNode* left;
//	TreeNode* right;
//	int val;
//};


//class TreeNode
//{
//public:
//	TreeNode(int val = 0)
//	{
//		_left = nullptr;
//		_right = nullptr;
//		_val = val;
//	}
//private:
//	TreeNode* _left;
//	TreeNode* _right;
//	int _val;
//};
//int main()
//{
//	//创建一个树节点，很灵活的创建
//	TreeNode tr(5);
//	TreeNode tr(6);
//	TreeNode tr(7);
//	TreeNode tr(8);
//	return 0;
//}

//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 3)
//	{
//		_a = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (NULL == _a)
//		{
//			perror("malloc申请空间失败!!!");
//			return;
//		}
//		_capacity = capacity;
//		_top = 0;
//	}
//	void Push(DataType data)
//	{
//		//CheckCapacity()
//		_a[_top++] = data;
//	}
//	~Stack()
//	{
//		cout << "you can see me!" << endl;
//		if (_a)
//		{
//			free(_a);
//			_a = NULL;
//			_capacity = 0;
//			_top = 0;
//		}
//	}
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//int main()
//{
//	Stack s1;
//	return 0;
//}

class Stack
{
private:
	int* _a;
	int _top;
	int _capacity;
};

class Date
{
	int _year;
	int _month;
	int _day;
};

class Queue
{
private:
	Stack pushst;
	Stack popst;
};












