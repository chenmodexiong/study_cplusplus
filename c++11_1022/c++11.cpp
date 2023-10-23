#include <iostream>
#include <string>
using namespace std;

//lambda表达式
//int main()
//{
//	int a = 10;
//	int b = 20;
//	cout << "a=" << a << "  " << "b=" << b << endl;
//	auto add1 = [](int& x, int& y)->int {return x + y; };
//	auto add2 = [](int& x, int& y) {return x + y; };
//	/*cout << add1(a, b) << endl;
//	cout << add2(a, b) << endl;*/
//	auto swap1 = [](int x, int y) {
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//	swap1(a, b);
//	cout << "a=" << a << "  " << "b=" << b << endl;
//	auto swap2 = [](int& x, int& y) {
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//	swap2(a, b);
//	cout << "a=" << a << "  " << "b=" << b << endl;
//	/*auto swap3 = [=] {
//		int tmp = a;
//		a = b;
//		b = tmp;
//	};*/
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int b = 20;
//	//cout << "a=" << a << "  " << "b=" << b << endl;
//	auto add1 = [](int& x, int& y)->int {return x + y; };
//	auto add2 = [](int& x, int& y) {return x + y; };
//	double rate = 2.5;
//	auto add3 = [](int x, int y) {x = y; };
//	//auto add4 = [rate](int x, int y) { rate = 3; }; //报错error
//	auto add4 = [&rate](int x, int y) { rate = 3; };
//
//	auto add_rate = [rate](int a, int b) {return (a + b) * rate; };
//	cout << add_rate(a, b) << endl;
//
//	int a = 1, b = 2, c = 3, d = 4, e = 5;
//	auto add_x = [&] {a++, b++, c++, d++, e++; };
//	//auto add_y = [&,a] {a++, b++, c++, d++, e++; };
//
//	auto add_1 = [&] {a++, b++, c++, d++, e++; };
//	auto add_2 = [&] {a++, b++, c++, d++, e++; };
//	//add_1 = add_2; //error
//	cout << typeid(add_1).name() << endl;
//	cout << typeid(add_2).name() << endl;
//
//	return 0;
//}

//int main()
//{
//	auto f1 = [] {cout << "hello world" << endl; };
//	auto f2 = [] {cout << "hello world" << endl; };
//	//f1 = f2;
//	cout << typeid(f1).name() << endl;
//	cout << typeid(f2).name() << endl;
//
//	return 0;
//}

class Rate
{
public:
	Rate(double rate) : _rate(rate)
	{}
	double operator()(double money, int year)
	{
		return money * _rate * year;
	}
private:
	double _rate;
};
//int main()
//{
//	// 函数对象
//	double rate = 0.49;
//	Rate r1(rate);
//	r1(10000, 2);
//	// lambda
//	auto r2 = [=](double monty, int year)->double {return monty * rate * year; };
//	r2(10000, 2);
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
class ComparePriceLessGoods {
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
//
//int main()
//{
//	std::vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2,
//	3 }, { "菠萝", 1.5, 4 } };
//	sort(v.begin(), v.end(), ComparePriceLessGoods());
//	sort(v.begin(), v.end(), ComparePriceGreaterGoods());
//	sort(v.begin(), v.end(), CompareEvaluateLessGoods());
//	sort(v.begin(), v.end(), CompareEvaluateGreaterGoods());
//	//lambda表达式
//	auto ret = [](int val1, int val2)->bool {return val1 > val2; };
//	cout << ret(1, 2) << endl;
//
//	auto ComparePriceLess = [](const Goods& g1, const Goods& g2)
//	{return g1._price < g2._price; };
//	auto ComparePriceGreater = [](const Goods& g1, const Goods& g2)
//	{return g1._price > g2._price; };
//	auto CompareEvaluateLess = [](const Goods& g1, const Goods& g2)
//	{return g1._price < g2._price; };
//	auto CompareEvaluateGreater = [](const Goods& g1, const Goods& g2)
//	{return g1._price < g2._price; };
//	sort(v.begin(), v.end(), ComparePriceLessGoods());
//	sort(v.begin(), v.end(), ComparePriceGreaterGoods());
//	sort(v.begin(), v.end(), CompareEvaluateLessGoods());
//	sort(v.begin(), v.end(), CompareEvaluateGreaterGoods());
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
//		{return g1._price < g2._price; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
//		{return g1._price > g2._price; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
//		{return g1._price < g2._price; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
//		{return g1._price < g2._price; });
//	return 0;
//}

















