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

//c++�����У���ClassA�Ĺ��캯��������������ִ�д����ֱ�Ϊ()
int main()
{
	//�����
	/*ClassA* pclassa = new ClassA[5];
	delete pclassa;*/
	//��ȷд��
	/*ClassA* pclassb = new ClassA[5];
	delete[] pclassb;*/
	
	//�����ڴ�й©�����ǲ�������ô��
	/*int* p1 = new int[10];
	delete p1;*/
	//��ȷ�÷�
	/*int* p2 = new int[10];
	delete[] p2;*/
	return 0;
}













