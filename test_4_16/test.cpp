#include <iostream>
using namespace std;

//int main()
//{
//	int a;
//	double b;
//	char c;
//	// �����Զ�ʶ�����������
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
//	Func();//û�д���ʱ��ʹ�ò�����Ĭ��ֵ
//	Func(10);//����ʱ��ʹ��ָ��ʵ��
//	return 0;
//}

//ȫȱʡ����
//void Func(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a= " << a << endl;
//	cout << "b= " << b << endl;
//	cout << "c= " << c << endl;
//}

//��ȱʡ����
//void Func(int a, int b = 20, int c = 30)
//{
//	cout << "a= " << a << endl;
//	cout << "b= " << b << endl;
//	cout << "c= " << c << endl;
//}

// 1���������Ͳ�ͬ
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


// 2������������ͬ
void f()
{
	cout << "f()" << endl;
}

void f(int a)
{
	cout << "f(int a)" << endl;
}

// 3����������˳��ͬ
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









