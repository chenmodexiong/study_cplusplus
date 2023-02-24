#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//int main()
//{
//	cout << "hello C++!!\nhello\n";
//	cout << "hello world" << endl << "hello\n";
//	cout << 'a' << 'b' << '\n';
//	cout << 5 << endl;
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	cin >> a >> b;
//	cout << "a=" << a << ' ' << "b=" << b << endl;
//
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	cin >> a >> b;
//	cout << "a+b=" << a + b << endl;
//	return 0;
//}

//void Swap(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	cin >> a >> b;
//	Swap(&a, &b);
//	cout << "a=" << a << ' ' << "b=" << b << endl;
//	return 0;
//}


//class Swap
//{
//private:
//	int a = 10;
//	int b = 20;
//public:
//	Swap(int* a, int* b)
//	{
//		int tmp = *a;
//		*a = *b;
//		*b = tmp;
//	}
//};
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	cin >> a >> b;
//	cout <<"before:" << "a=" << a << ' ' << "b=" << b << endl;
//	Swap(&a, &b);
//	cout << "after:" << "a=" << a << ' ' << "b=" << b << endl;
//
//	return 0;
//}

//int main()
//{
//	cout << "This" << "is";
//	cout << "a" << "C++";
//	cout << "program." << endl;
//
//	return 0;
//}

//int main()
//{
//	int a, b, c;
//	a = 10;
//	b = 23;
//	c = a + b;
//	cout << "a+b=";
//	cout << c;
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	int a, b, c;
//	int f(int x, int y, int z);
//	cin >> a >> b >> c;
//	c = f(a, b, c);
//	cout << c << endl;
//
//	return 0;
//}
//
//int f(int x, int y, int z)
//{
//	int m;
//	if (x < y)
//		m = x;
//	else
//		m = y;
//	if (z < m)
//		m = z;
//	return m;
//}

//int main()
//{
//	int a, b;
//	//c = a + b;
//	cout << "a+b=" << a + b;
//
//	return 0;
//}

//int Add(int x, int y);
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	c = Add(a , b);
//	cout << "a+b=" << c << endl;
//
//	return 0;
//}
//
//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}

int main()
{
	void sort(int x, int y, int z);
	int x, y, z;
	cin >> x >> y >> z;
	sort(x, y, z);

	return 0;
}

void sort(int x, int y, int z)
{
	int temp;
	if (x > y)
	{
		temp = x;
		x = y;
		y = temp;
	}
	if (z < x)
	{
		cout << z << ',' << x << ',' << y << endl;
	}
	else if(z<y)
	{
		cout << x << ',' << z << ',' << y << endl;
	}
	else
	{
		cout << x << ',' << y << ',' << z << endl;
	}
}





















