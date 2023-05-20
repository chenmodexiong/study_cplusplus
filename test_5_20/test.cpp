#include <iostream>
using namespace std;


//template<class T1, class T2> void Swap(T1, T2)
//{
//
//}

//template<class T1, class T2> 
//void Swap(T1, T2)
//{}

//template <class T1,class T2> class A
//{
//
//};

//template <class T1, class T2> 
//class A
//{
//	void Swap(int a, int b)
//	{
//
//	}
//};

class ClassA
{
public:
	ClassA()
		:_a(10)
	{
		cout << "A()" << endl;
	}
	~ClassA()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

//c++语言中，类ClassA的构造函数和析构函数的执行次数分别为()
int main()
{
	//会崩溃
	/*ClassA* pclassa = new ClassA[5];
	delete pclassa;*/
	//正确写法
	/*ClassA* pclassb = new ClassA[5];
	delete[] pclassb;*/
	
	//不会内存泄漏，但是不建议这么用
	/*int* p1 = new int[10];
	delete p1;*/
	//正确用法
	/*int* p2 = new int[10];
	delete[] p2;*/
	return 0;
}













