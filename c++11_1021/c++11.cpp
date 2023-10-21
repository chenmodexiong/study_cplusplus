#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//左值引用和右值引用

//左值是一个表示数据的表达式(如变量名或解引用的指针)，我们可以获取它的地址 + 可以对它赋
//值，左值可以出现赋值符号的左边，右值不能出现在赋值符号左边。定义时const修饰符后的左
//值，不能给他赋值，但是可以取它的地址。左值引用就是给左值的引用，给左值取别名

//int main()
//{
//	//左值
//	int* p = new int[10];
//	const int b = 2;
//	int c = 1;
//	//左值的引用
//	int*& pp = p;
//	const int& bb = b;
//	int& cc = c;
//	int& pval = *p;
//	return 0;
//}

//右值也是一个表示数据的表达式，如：字面常量、表达式返回值，函数返回值(这个不能是左值引
//用返回)等等，右值可以出现在赋值符号的右边，但是不能出现出现在赋值符号的左边，右值不能
//取地址。右值引用就是对右值的引用，给右值取别名

//int main()
//{
//	double x = 1.1, y = 2.2;
//	// 以下几个都是常见的右值
//	10;
//	x + y;
//	fmin(x, y);
//	//右值引用
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	double&& rr3 = fmin(x, y);
//	// error ‘=’左边必须是左值
//	10 = 1;
//	x + y = 1;
//	fmin(x, y) = 1;
//	return 0;
//}

//右值是不能取地址的，但是给右值取别名后，会导致右值被存储到特定位置，且可
//以取到该位置的地址，也就是说例如：不能取字面量10的地址，但是rr1引用后，可以对rr1取地
//址，也可以修改rr1。如果不想rr1被修改，可以用const int&& rr1 去引用
//
//int main()
//{
//	double x = 1.1, y = 2.2;
//	int&& rr1 = 10;
//	const double&& rr2 = x + y;
//	rr1 = 20;
//	rr2 = 5.5;//报错
//	return 0;
//}

//左值引用
//1. 左值引用只能引用左值，不能引用右值。
//2. 但是const左值引用既可引用左值，也可引用右值。
//右值引用
//1. 右值引用只能右值，不能引用左值。
//2. 但是右值引用可以move以后的左值。
//int main()
//{
//	int a = 10;
//	int& ra = a;
//	//int& ra = 10;//报错
//	//const可以引用左值，也可引用右值
//	const int& ra2 = a;
//	const int& ra3 = 10;
//	
//	int&& rb1 = 20;
//	int b = 20;
//	//int&& rb2 = b;//报错
//	int&& rb3 = std::move(b);
//	return 0;
//}

//右值引用使用场景和意义
#include "string.h"

//void func1(lzb::string s)
//{}
//void func2(const lzb::string& s)
//{}
//int main()
//{
//	lzb::string s1("hello world");
//	// func1和func2的调用可以看到左值引用做参数减少了拷贝，提高效率的使用场景和价值
//	func1(s1);
//	func2(s1);
//	// string operator+=(char ch) 传值返回存在深拷贝
//	// string& operator+=(char ch) 传左值引用没有拷贝提高了效率
//	s1 += '!';
//	return 0;
//}

//// 移动构造
//string(string&& s)
//	:_str(nullptr)
//	, _size(0)
//	, _capacity(0)
//{
//	cout << "string(string&& s) -- 移动语义" << endl;
//	swap(s);
//}
//// 移动赋值
//string& operator=(string&& s)
//{
//	cout << "string& operator=(string&& s) -- 移动语义" << endl;
//	swap(s);
//	return *this;
//}
namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			//cout << "string(char* str)" << endl;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		// s1.swap(s2)
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}
		// 拷贝构造
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- 深拷贝" << endl;
			string tmp(s._str);
			swap(tmp);
		}
		// 赋值重载
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- 深拷贝" << endl;
			string tmp(s);
			swap(tmp);
			return *this;
		}
		// 移动构造
		string(string&& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(string&& s) -- 移动构造" << endl;
			swap(s);
		}
		// 移动赋值
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- 移动赋值" << endl;
			swap(s);
			return *this;
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity; // 不包含最后做标识的\0
	};
	bit::string to_string(int value)
	{
		bool flag = true;
		if (value < 0)
		{
			flag = false;
			value = 0 - value;
		}
		bit::string str;
		while (value > 0)
		{
			int x = value % 10;
			value /= 10;
			str += ('0' + x);
		}
		if (flag == false)
		{
			str += '-';
		}
		std::reverse(str.begin(), str.end());
		return str;
	}
}

//int main()
//{
//	// 在bit::string to_string(int value)函数中可以看到，这里
//	// 只能使用传值返回，传值返回会导致至少1次拷贝构造(如果是一些旧一点的编译器可能是两次拷贝构造)。
//	/*bit::string ret1 = bit::to_string(1234);
//	bit::string ret2(ret1);
//	bit::string ret3;
//	ret3 = bit::to_string(1234);*/
//	lzb::string s1 = "11111111111111";
//	lzb::string s2(forward<lzb::string>(s1));
//	return 0;
//}

//int& func1(int& x)
//{
//	int a = x;
//	cout << "int& func1(int& x)" << endl;
//	return a;
//}
//int& func1(int&& x)
//{
//	int a = x;
//	cout << "int& func2(int&& x)" << endl;
//	return a;
//}
//int main()
//{
//	int a;
//	func1(a);
//	func1(10);
//	return 0;
//}

// 模板中的&&不代表右值引用，而是万能引用，其既能接收左值又能接收右值。
// 模板的万能引用只是提供了能够接收同时接收左值引用和右值引用的能力，
// 但是引用类型的唯一作用就是限制了接收的类型，后续使用中都退化成了左值，
// 我们希望能够在传递过程中保持它的左值或者右值的属性, 就需要用我们下面的完美转发
void Fun(int& x) { cout << "左值引用" << endl; }
void Fun(const int& x) { cout << "const左值引用" << endl; }
void Fun(int&& x) { cout << "右值引用" << endl; }
void Fun(const int&& x) { cout << "const右值引用" << endl; }
template<class T>
void PerfectForword(T&& t)
{
	//Fun(t);
	//利用forward进行完美转发，保留它的属性
	Fun(forward<T>(t));
}
//int main()
//{
//	PerfectForword(10);
//	int a = 10;
//	PerfectForword(a);
//	PerfectForword(std::move(a));
//	const int b = 10;
//	PerfectForword(b);
//	PerfectForword(std::move(b));
//	return 0;
//}

#include "list.h"

//int main()
//{
//	//利用完美转发，全部走右值引用
//	lzb::list<string> lt;
//	std::string s1("111111111111111111111");
//	lt.push_back(move(s1));
//	return 0;
//}

//lambda表达式
#include <algorithm>
#include <functional>
#include <vector>
//int main()
//{
//	int array[] = { 4,1,8,5,3,7,0,9,2,6 };
//	// 默认按照小于比较，排出来结果是升序
//	std::sort(array, array + sizeof(array) / sizeof(array[0]));
//	// 如果需要降序，需要改变元素的比较规则
//	std::sort(array, array + sizeof(array) / sizeof(array[0]), greater<int>());
//	return 0;
//}

struct Goods
{
	string _name; // 名字
	double _price; // 价格
	int _evaluate; // 评价
	Goods(const char* str, double price, int evaluate)
		:_name(str)
		, _price(price)
		, _evaluate(evaluate)
	{}
};
class ComparePriceLessGoods{
public:
	bool operator()(const Goods& g1, const Goods& g2) {
		return g1._price < g2._price;
	}
};
class ComparePriceGreaterGoods {
public:
	bool operator()(const Goods& g1, const Goods& g2) {
		return g1._price > g2._price;
	}
};
class CompareEvaluateLessGoods {
public:
	bool operator()(const Goods& g1, const Goods& g2) {
		return g1._evaluate < g2._evaluate;
	}
};
class CompareEvaluateGreaterGoods {
public:
	bool operator()(const Goods& g1, const Goods& g2) {
		return g1._evaluate > g2._evaluate;
	}
};
int main()
{
	std::vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2,
	3 }, { "菠萝", 1.5, 4 } };
	sort(v.begin(), v.end(), ComparePriceLessGoods());
	sort(v.begin(), v.end(), ComparePriceGreaterGoods());
	sort(v.begin(), v.end(), CompareEvaluateLessGoods());
	sort(v.begin(), v.end(), CompareEvaluateGreaterGoods());
	//lambda表达式
	auto ret=[](int val1, int val2)->bool {return val1 > val2; };
	cout << ret(1,2) << endl;

	auto ComparePriceLess = [](const Goods& g1, const Goods& g2)
								{return g1._price < g2._price; };
	auto ComparePriceGreater = [](const Goods& g1, const Goods& g2)
									{return g1._price > g2._price; };
	auto CompareEvaluateLess = [](const Goods& g1, const Goods& g2)
									{return g1._price < g2._price; };
	auto CompareEvaluateGreater = [](const Goods& g1, const Goods& g2)
									{return g1._price < g2._price; };
	sort(v.begin(), v.end(), ComparePriceLessGoods());
	sort(v.begin(), v.end(), ComparePriceGreaterGoods());
	sort(v.begin(), v.end(), CompareEvaluateLessGoods());
	sort(v.begin(), v.end(), CompareEvaluateGreaterGoods());

	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
						{return g1._price < g2._price; });
	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
						{return g1._price > g2._price; });
	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
						{return g1._price < g2._price; });
	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
						{return g1._price < g2._price; });
	return 0;
}





