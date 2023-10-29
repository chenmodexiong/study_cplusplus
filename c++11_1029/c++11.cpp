#include <iostream>
#include <functional>
using namespace std;
//function��װ�� Ҳ������������C++�е�function������һ����ģ�壬Ҳ��һ����װ����
//ret = func(x);
// ����func������ʲô�أ���ôfunc�����Ǻ�����������ָ�룿��������(�º�������)��Ҳ�п���
//��lamber���ʽ����������Щ���ǿɵ��õ����ͣ���˷ḻ�����ͣ����ܻᵼ��ģ���Ч�ʵ��£�
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
//	// ������
//	cout << useF(f, 11.11) << endl;
//	// ��������
//	cout << useF(Functor(), 11.11) << endl;
//	// lamber���ʽ
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
//	// ������(����ָ��)
//	std::function<int(int, int)> func1 = f;
//	cout << func1(1, 2) << endl;
//	// ��������
//	std::function<int(int, int)> func2 = Functor();
//	cout << func2(1, 2) << endl;
//	// lamber���ʽ
//	std::function<int(int, int)> func3 = [](const int a, const int b)
//	{return a + b; };
//	cout << func3(1, 2) << endl;
//	// ��ĳ�Ա����
//	std::function<int(int, int)> func4 = &Plus::plusi;
//	cout << func4(1, 2) << endl;
//	std::function<double(Plus, double, double)> func5 = &Plus::plusd;
//	cout << func5(Plus(), 1.1, 2.2) << endl;
//	return 0;
//}

int Plus1(int a, int b)
{
	return a + b;
}
double Sub(double a, double b,int rate)
{
	return (a + b) * rate;
}

class Plus
{
public:
	int operator()(int a, int b) {
		return a + b;
	}
};
class Test
{
public:
	double operator()(double a, double b,double rate) {
		return (a + b) * rate;
	}
	int plus(int a, int b) {
		return a + b;
	}
};
int main()
{
	function<int(int,int)> func1=Plus();
	cout << func1(3, 4) << endl;
	cout << typeid(placeholders::_1).name() << endl;
	std::function<double(double,double,double)> func2_back = Test();
	std::function<double(double, double)> func2 = 
		bind(Test(), placeholders::_1, placeholders::_2, 4.0);
	cout << func2(4.1, 4.2) << endl;
	Test st;
	std::function<int(int, int)> func3 = bind(&Test::plus, &st, placeholders::_1, placeholders::_2);
	std::function<int(int, int)> func4 = bind(&Test::plus, st, placeholders::_1, placeholders::_2);
	std::function<int(int, int)> func5 = bind(&Test::plus,Test(),placeholders::_1, placeholders::_2);

	std::function<int(int, int)> plus1 = bind(Plus1, placeholders::_1, placeholders::_2);
	std::function<double(double, double)> sub1 = bind(Sub, placeholders::_1, placeholders::_2, 4);
	cout << plus1(3, 3) << endl;
	cout << sub1(3.3, 3.3) << endl;
	std::function<double(double, double)> type = bind(Sub, placeholders::_1, placeholders::_2, 4);
	cout << typeid(type).name() << endl;
	auto viewtype = bind(Sub, placeholders::_1, placeholders::_2, 4);
	cout << typeid(viewtype).name() << endl;

	return 0;
}







