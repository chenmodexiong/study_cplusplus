#include <iostream>
#include <functional>
using namespace std;
//function包装器 也叫作适配器。C++中的function本质是一个类模板，也是一个包装器。
//ret = func(x);
// 上面func可能是什么呢？那么func可能是函数名？函数指针？函数对象(仿函数对象)？也有可能
//是lamber表达式对象？所以这些都是可调用的类型！如此丰富的类型，可能会导致模板的效率低下！
//template<class F, class T>
//T useF(F f, T x)
//{
//	static int count = 0;
//	cout << "count:" << ++count << endl;
//	cout << "count:" << &count << endl;
//	return f(x);
//}
//double f(double i)
//{
//	return i / 2;
//}
//struct Functor
//{
//	double operator()(double d)
//	{
//		return d / 3;
//	}
//};
//int main()
//{
//	// 函数名
//	cout << useF(f, 11.11) << endl;
//	// 函数对象
//	cout << useF(Functor(), 11.11) << endl;
//	// lamber表达式
//	cout << useF([](double d)->double { return d / 4; }, 11.11) << endl;
//	return 0;
//}
// 
//int f(int a, int b) {
//	return a + b;
//}
//struct Functor
//{
//public:
//	int operator() (int a, int b) {
//		return a + b;
//	}
//};
//class Plus
//{
//public:
//	static int plusi(int a, int b) {
//		return a + b;
//	}
//	double plusd(double a, double b) {
//		return a + b;
//	}
//};
//int main()
//{
//	// 函数名(函数指针)
//	std::function<int(int, int)> func1 = f;
//	cout << func1(1, 2) << endl;
//	// 函数对象
//	std::function<int(int, int)> func2 = Functor();
//	cout << func2(1, 2) << endl;
//	// lamber表达式
//	std::function<int(int, int)> func3 = [](const int a, const int b)
//	{return a + b; };
//	cout << func3(1, 2) << endl;
//	// 类的成员函数
//	std::function<int(int, int)> func4 = &Plus::plusi;
//	cout << func4(1, 2) << endl;
//	std::function<double(Plus, double, double)> func5 = &Plus::plusd;
//	cout << func5(Plus(), 1.1, 2.2) << endl;
//	return 0;
//}


#include <vector>

using namespace std;
//
//int main(void)
//{
//	vector<int>array;
//	array.push_back(100);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(500);
//	vector<int>::iterator itor;
//	for (itor = array.begin(); itor != array.end(); itor++)
//	{
//		if (*itor == 300)
//		{
//			itor = array.erase(itor);
//		}
//	}
//	for (itor = array.begin(); itor != array.end(); itor++)
//	{
//		cout << *itor << " ";
//	}
//	return 0;
//}

int main()
{
	int ar[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(ar) / sizeof(int);
	vector<int> v(ar, ar + n);
	cout << v.size() << ":" << v.capacity() << endl;
	v.reserve(100);
	v.resize(20);
	cout << v.size() << ":" << v.capacity() << endl;
	v.reserve(50);
	v.resize(5);
	cout << v.size() << ":" << v.capacity() << endl;
}







