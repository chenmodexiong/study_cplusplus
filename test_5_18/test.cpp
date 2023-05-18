#include <iostream>
using namespace std;

//int globalVar = 1;
//static int staticGlobalVar = 1;
//void Test()
//{
//	static int staticVar = 1;
//	int localVar = 1;
//	int num1[10] = { 1, 2, 3, 4 };
//	char char2[] = "abcd";
//	const char* pChar3 = "abcd";
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//}
//1. ѡ���⣺
//ѡ�� : A.ջ B.�� C.���ݶ�(��̬��) D.�����(������)
//globalVar�����____ staticGlobalVar�����____
//staticVar�����____ localVar�����____
//num1 �����____
//char2�����____ * char2�����___
//pChar3�����____ * pChar3�����____
//ptr1�����____ * ptr1�����____
//2. ����⣺
//sizeof(num1) = ____;
//sizeof(char2) = ____; strlen(char2) = ____;
//sizeof(pChar3) = ____; strlen(pChar3) = ____;
//sizeof(ptr1) = ____;
//3. sizeof �� strlen ����

//void Test()
//{
//	int* p1 = new int;
//	int* p2 = new int(5);
//	int* p3 = new int[5];
//	int* p4 = new int[5] {1, 2, 3};
//	delete p1;
//	delete p2;
//	delete[] p3;
//	delete[] p4;
//}

//void Test1()
//{
//	int* p1 = new int;
//	free(p1);
//	int* p2 = (int*)malloc(sizeof(int));
//	delete p2;
//
//	int* p4 = new int[5] {1,2,3};
//	int* p5 = (int*)malloc(sizeof(int) * 5);
//	free(p4);
//	delete[] p5;
//}
//
//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{}
//	~A() {}
//private:
//	int _a;
//};
//
//void Test2()
//{
//	A* p1 = new A;
//	free(p1);
//	A* p2 = (A*)malloc(sizeof(A));
//	delete p2;
//
//	A* p3 = (A*)malloc(sizeof(A) * 5);
//	A* p4 = new A[5]{ A(1), A(2), A(3),A(4),A(5)};
//	delete[] p3;
//	free(p4);
//}
//
//int main()
//{
//	Test1();
//	Test2();
//	return 0;
//}

//
//class A
//{
//public:
//	A(int a, int b)
//		:_a(a), _b(b)
//	{
//		cout << "���ǹ��캯��" << endl;
//	}
//	~A() 
//	{
//		cout << "������������" << endl;
//	}
//private:
//	int _a;
//	int _b;
//};
//
//void Test1()
//{
//	A* p1 = new A(3, 4);
//	delete p1;
//	A* p2 = new A[5]{ A(1,2),A(3,4),A(5,6),A(7,8),A(9,10) };
//	//A* p2 = new A[5]{ (1,2),(3,4),(5,6),(7,8),(9,10)}; ����������д������������Żᱻ��Ϊ�Ƕ��ű��ʽ
//	delete[] p2;
//}
//
//void Test2()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = new int;
//}
//
//int main()
//{
//	Test1();
//	//Test2();
//	return 0;
//}

//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{
//		cout << "���ǹ��캯��" << endl;
//	}
//	~A()
//	{
//		cout << "������������" << endl;
//	}
//private:
//	int _a;
//};
//
//void Test()
//{
//	A* p1 = new A;
//	delete p1;
//}
//int main()
//{
//	Test();
//	return 0;
//}


//void* __CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc)
//{
//	// try to allocate size bytes
//	void* p;
//	while ((p = malloc(size)) == 0)
//	{
//		if (_callnewh(size) == 0)
//		{
//			// report no memory
//			// ��������ڴ�ʧ���ˣ�������׳�bad_alloc �����쳣
//			static const std::bad_alloc nomem;
//			_RAISE(nomem);
//		}
//	}
//	return (p);
//}
//
//void operator delete(void* pUserData)
//{
//	_CrtMemBlockHeader* pHead;
//	RTCCALLBACK(_RTC_Free_hook, (pUserData, 0));
//	if (pUserData == NULL)
//		return;
//	_mlock(_HEAP_LOCK); /* block other threads */
//	__TRY
//		/* get a pointer to memory block header */
//		pHead = pHdr(pUserData);
//	/* verify block type */
//	_ASSERTE(_BLOCK_TYPE_IS_VALID(pHead->nBlockUse));
//	_free_dbg(pUserData, pHead->nBlockUse);
//	__FINALLY
//		_munlock(_HEAP_LOCK); /* release other threads */
//	__END_TRY_FINALLY
//		return;
//}

/*free��ʵ��*/
//#define free(p) _free_dbg(p, _NORMAL_BLOCK)
//#include <stdlib.h>

//class A
//{
//private:
//	int _a;
//};

//int main()
//{
//	A* p1 = nullptr;
//	try
//	{
//		do
//		{
//			p1 = (A*)operator new(1024*1024);
//			cout << p1 << endl;
//		} while (p1);
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}

class A
{
public:
	A(int a=0)
		:_a(a)
	{

		cout << "���ǹ��캯��" << endl;
	}
	~A()
	{
		cout << "������������" << endl;
	}
private:
	int _a;
};

int main()
{
	// p1����ָ���ֻ��������A������ͬ��С��һ�οռ䣬����������һ��������Ϊ���캯��û��ִ��
	A* p1 = (A*)malloc(sizeof(A));
	new(p1)A(10);//ע�⣺���A��Ĺ��캯���в���ʱ���˴���Ҫ����
	p1->~A();
	free(p1);

	A* p2 = (A*)operator new(sizeof(A));
	new(p2)A(10);
	p2->~A();
	operator delete(p2);

	return 0;
}







