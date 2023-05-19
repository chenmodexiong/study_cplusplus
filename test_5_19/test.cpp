#include <iostream>
using namespace std;

//template<typename T>
//void Swap(T& t1,T& t2)
//{
//	T tmp = t1;
//	t1 = t2;
//	t2 = tmp;
//}
//int main()
//{
//	double d1 = 10.1;
//	double d3 = 5.2;
//	int d2 = 5;
//	int d4 = 3;
//	Swap(d1, d3);
//	Swap(d2, d4);
//	//Swap(d1, (double)d2);//类型转换会产生临时变量，具有常属性
//	//Swap((int)d1, d2);
//	return 0;
//}

//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}
//..............

//template <typename T>
//void Swap(T& t1, T& t2)
//{
//	T tmp = t1;
//	t1 = t2;
//	t2 = tmp;
//}

//template <typename T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//int main()
//{
//	int a = 10, b = 20;
//	cout << Add(a, b) << endl;
//	double c = 3.14, d = 5.2;
//	cout << Add(c, d) << endl;
//	return 0;
//}

//template <typename T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//int main()
//{
//	int a = 10;
//	double b = 3.14;
//	Add(a, (int)b);
//	Add((double)a, b);
//	return 0;
//}

//int Add(const int& a, const int& b)
//{
//	return a + b;
//}
//
//template <typename T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 3.14;
//	Add(a, b);
//	Add<int>(a, b);
//	Add<double>(a, b);
//	return 0;
//}

//
//int Add(const int& a, const int& b)
//{
//	return a + b;
//}
//
//template <typename T1,typename T2>
//T1 Add(const T1& left, const T2& right)
//{
//	return left + right;
//}
//
////T2 Add2(const T1& left, const T2& right)
////{
////	return left + right;
////}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	double c = 3.14;
//	Add(a, b);
//	Add(a, c);
//	return 0;
//}


//template<class T1, class T2, ..., class Tn>
//class 类模板名
//{
//	// 类内成员定义
//};

// 动态顺序表
// 注意：Vector不是具体的类，是编译器根据被实例化的类型生成具体类的模具
template<class T>
class Vector
{
public:
	Vector(size_t capacity = 10)
		:_pData(new T[capacity]), _size(0),_capacity(capacity)
	{}
	~Vector();
	void PushBack(const T& data);
	void PopBack();
	//......
private:
	T* _pData;
	size_t _size;
	size_t _capacity;
};

// 注意：类模板中函数放在类外进行定义时，需要加模板参数列表
template <class T>
Vector<T>::~Vector()
{
	if (_pData)
		delete[] _pData;
	_size = _capacity = 0;
}

