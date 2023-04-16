#include <iostream>
using namespace std;

//int main()
//{
//	int a;
//	double b;
//	char c;
//	// 可以自动识别变量的类型
//	cin >> a;
//	cin >> b >> c;
//	cout << a << endl;
//	cout << b << " " << c << endl;
//	return 0;
//}

//void Func(int a = 0)
//{
//	cout << a << endl;
//}
//
//int main()
//{
//	Func();//没有传参时，使用参数的默认值
//	Func(10);//传参时，使用指定实参
//	return 0;
//}

//全缺省参数
//void Func(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a= " << a << endl;
//	cout << "b= " << b << endl;
//	cout << "c= " << c << endl;
//}

//半缺省参数
//void Func(int a, int b = 20, int c = 30)
//{
//	cout << "a= " << a << endl;
//	cout << "b= " << b << endl;
//	cout << "c= " << c << endl;
//}

// 1、参数类型不同
int Add(int left, int right)
{
	cout << "int Add(int left, int right)" << endl;
	return left + right;
}

double Add(double left, double right)
{
	cout << "double Add(double left, double right)" << endl;
	return left + right;
}


// 2、参数个数不同
void f()
{
	cout << "f()" << endl;
}

void f(int a)
{
	cout << "f(int a)" << endl;
}

// 3、参数类型顺序不同
void f(int a, char b)
{
	cout << "f(int a,char b)" << endl;
}
void f(char b, int a)
{
	cout << "f(char b, int a)" << endl;
}

int main()
{
	Add(1, 2);
	Add(1.1, 2.2);
	return 0;
}









