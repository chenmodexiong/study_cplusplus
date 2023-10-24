#include <iostream>

#include <list>
using namespace std;

//Args是一个模板参数包，args是一个函数形参参数包
//声明一个参数包Args..args，这个参数包中可以包含从0到任意个模板参数
template<class ...Args>
void ShowList1(Args... args)
{}

//我们无法直接获取参数包args中的每个参数的，
//只能通过展开参数包的方式来获取参数包中的每个参数，
//这是使用可变模版参数的一个主要特点，也是最大的难点，
//即如何展开可变模版参数

//1.递归函数方式展开
//
//template<class T>
//void showlist(const T& t)
//{
//	cout << t << " ";
//	cout << endl;
//}
//void _showlist()
//{
//	cout << endl;
//}
//template<class T,class ...Args>
//void _showlist(T val,Args... args)
//{
//	cout << val << " ";
//	_showlist(args...);
//}
//template<class ...Args>
//void showlist(Args... args)
//{
//	_showlist(args...);
//}
//int main()
//{
//	showlist();
//	showlist(1);
//	showlist(1, 2);
//	showlist(1, 'A', 3.3);
//	showlist(1, 2.2, string("1111111111"));
//	return 0;
//}

//2.逗号表达式展开参数包

//逗号表达式会按顺序执行逗号前面的表达式
//同时还用到了C++11的另外一个特性——初始化列表，通过初始化列表来初始化一个变长数组
//最终会创建一个元素值都为0的数组int arr
//template<class T>
//void PrintArg(T t)
//{
//	cout << t << " ";
//}
//template<class ...Args>
//void showlist(Args... args)
//{
//	int arr[] = { (PrintArg(args),0)... };
//	//int arr[] = { (PrintArg(args1),0),(PrintArg(args2),0),(PrintArg(args3),0)...etc... };
//	cout << endl;
//}
//template<class T>
//int PrintArg(T t)
//{
//	cout << t << " ";
//	return 0;
//}
//template<class ...Args>
//void showlist(Args... args)
//{
//	int arr[] = { PrintArg(args)... };
//	cout << endl;
//}
//int main()
//{
//	showlist(1);
//	showlist(1, 'A');
//	showlist(1, 'B', string("111111111"));
//	return 0;
//}
// 
// 
// 
// 
// emplace系列的接口，支持模板的可变参数，并且万能引用
//template <class... Args>
//void emplace_back(Args&&... args);
//int main()
//{
//	std::list< std::pair<int, char> > mylist;
//	// emplace_back支持可变参数，拿到构建pair对象的参数后自己去创建对象
//	// 那么在这里我们可以看到除了用法上，和push_back没什么太大的区别
//
//	mylist.emplace_back(10, 'a');
//	mylist.emplace_back(20, 'b');
//	mylist.emplace_back(make_pair(30, 'c'));
//	mylist.push_back(make_pair(40, 'd'));
//	mylist.push_back({ 50, 'e' });
//	for (auto e : mylist)
//		cout << e.first << ":" << e.second << endl;
//
//	// 带有拷贝构造和移动构造的string，再试试呢
//	// 我们会发现其实差别也不到，emplace_back是直接构造了，push_back
//	// 是先构造，再移动构造，其实也还好。
//
//	return 0;
//}

//两个默认成员函数
//C++11 新增了两个：移动构造函数和移动赋值运算符重载

//没有自己实现移动构造函数，且没有实现析构函数 、拷贝构造、拷贝赋值重载中的任
//意一个。那么编译器会自动生成一个默认移动构造。默认生成的移动构造函数，对于内置类
//型成员会执行逐成员按字节拷贝，自定义类型成员，则需要看这个成员是否实现移动构造，
//如果实现了就调用移动构造，没有实现就调用拷贝构造
// 
//如果你提供了移动构造或者移动赋值，编译器不会自动提供拷贝构造和拷贝赋值

// 以下代码在vs2013中不能体现，在vs2019下才能演示体现上面的特性。

namespace lzb
{
	//模拟实现string
	class string
	{
	public:
		//默认构造--“初始化”
		string(const char* str = "") //注意这里的空字符串,其实有‘\0’
		{							//为了解决"未初始化对象"的默认构造函数的问题
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			//strcpy(_str, str);
			memcpy(_str, str, _size + 1);
		}
		//清理
		/*~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}*/
		//拷贝构造
		//string(const string& s)
		//{
		//	_str = new char[s._capacity + 1];
		//	//strcpy(_str, s._str);
		//	memcpy(_str, s._str, s._size + 1);
		//	_size = s._size;
		//	_capacity = s._capacity;
		//}
		//移动构造
		string(string&& s)
		{
			cout << "我是移动构造" << endl;
			swap(s);
		}
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}
		string& operator=(string&& s)
		{
			cout << "我是移动赋值" << endl;
			swap(s);
			return *this;
		}
		//赋值
		//void swap(string& s)
		//{
		//	std::swap(_str, s._str);
		//	std::swap(_size, s._size);
		//	std::swap(_capacity, s._capacity);
		//}
		////全自动赋值
		//string& operator=(string tmp)
		//{
		//	swap(tmp);
		//	return *this;
		//}
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		/* 聪明人写法 */
		//		string tmp(s);
		//		swap(tmp);
		//		/*std::swap(_str, tmp._str);
		//		std::swap(_size, tmp._size);
		//		std::swap(_capacity,tmp._capacity);*/

		//		/* 正常传统写法 */
		//		//char* tmp = new char[s._capacity + 1];
		//		//memcpy(tmp, s._str, s._size + 1);
		//		//delete[] _str;
		//		//_str = tmp;
		//		//_size = s._size;
		//		//_capacity = s._capacity;
		//	}
		//	return *this;
		//}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}
class Person
{
public:
	Person(const char* name = "", int age = 0)
		:_name(name)
		, _age(age)
	{}

	/*~Person()
	{ }*/

private:
	lzb::string _name;
	int _age;
};

int main()
{
	Person s1;
	Person s2 = s1; //error
	Person s3 = std::move(s1);
	Person s4;
	s4 = std::move(s2);
	return 0;
}

