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
//1. 选择题：
//选项 : A.栈 B.堆 C.数据段(静态区) D.代码段(常量区)
//globalVar在哪里？____ staticGlobalVar在哪里？____
//staticVar在哪里？____ localVar在哪里？____
//num1 在哪里？____
//char2在哪里？____ * char2在哪里？___
//pChar3在哪里？____ * pChar3在哪里？____
//ptr1在哪里？____ * ptr1在哪里？____
//2. 填空题：
//sizeof(num1) = ____;
//sizeof(char2) = ____; strlen(char2) = ____;
//sizeof(pChar3) = ____; strlen(pChar3) = ____;
//sizeof(ptr1) = ____;
//3. sizeof 和 strlen 区别？

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
//		cout << "我是构造函数" << endl;
//	}
//	~A() 
//	{
//		cout << "我是析构函数" << endl;
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
//	//A* p2 = new A[5]{ (1,2),(3,4),(5,6),(7,8),(9,10)}; 不可以这样写，这里面的括号会被认为是逗号表达式
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
//		cout << "我是构造函数" << endl;
//	}
//	~A()
//	{
//		cout << "我是析构函数" << endl;
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
//			// 如果申请内存失败了，这里会抛出bad_alloc 类型异常
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

/*free的实现*/
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

		cout << "我是构造函数" << endl;
	}
	~A()
	{
		cout << "我是析构函数" << endl;
	}
private:
	int _a;
};

int main()
{
	// p1现在指向的只不过是与A对象相同大小的一段空间，还不能算是一个对象，因为构造函数没有执行
	A* p1 = (A*)malloc(sizeof(A));
	new(p1)A(10);//注意：如果A类的构造函数有参数时，此处需要传参
	p1->~A();
	free(p1);

	A* p2 = (A*)operator new(sizeof(A));
	new(p2)A(10);
	p2->~A();
	operator delete(p2);

	return 0;
}







