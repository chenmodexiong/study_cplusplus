#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//��ֵ���ú���ֵ����

//��ֵ��һ����ʾ���ݵı��ʽ(�������������õ�ָ��)�����ǿ��Ի�ȡ���ĵ�ַ + ���Զ�����
//ֵ����ֵ���Գ��ָ�ֵ���ŵ���ߣ���ֵ���ܳ����ڸ�ֵ������ߡ�����ʱconst���η������
//ֵ�����ܸ�����ֵ�����ǿ���ȡ���ĵ�ַ����ֵ���þ��Ǹ���ֵ�����ã�����ֵȡ����

//int main()
//{
//	//��ֵ
//	int* p = new int[10];
//	const int b = 2;
//	int c = 1;
//	//��ֵ������
//	int*& pp = p;
//	const int& bb = b;
//	int& cc = c;
//	int& pval = *p;
//	return 0;
//}

//��ֵҲ��һ����ʾ���ݵı��ʽ���磺���泣�������ʽ����ֵ����������ֵ(�����������ֵ��
//�÷���)�ȵȣ���ֵ���Գ����ڸ�ֵ���ŵ��ұߣ����ǲ��ܳ��ֳ����ڸ�ֵ���ŵ���ߣ���ֵ����
//ȡ��ַ����ֵ���þ��Ƕ���ֵ�����ã�����ֵȡ����

//int main()
//{
//	double x = 1.1, y = 2.2;
//	// ���¼������ǳ�������ֵ
//	10;
//	x + y;
//	fmin(x, y);
//	//��ֵ����
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	double&& rr3 = fmin(x, y);
//	// error ��=����߱�������ֵ
//	10 = 1;
//	x + y = 1;
//	fmin(x, y) = 1;
//	return 0;
//}

//��ֵ�ǲ���ȡ��ַ�ģ����Ǹ���ֵȡ�����󣬻ᵼ����ֵ���洢���ض�λ�ã��ҿ�
//��ȡ����λ�õĵ�ַ��Ҳ����˵���磺����ȡ������10�ĵ�ַ������rr1���ú󣬿��Զ�rr1ȡ��
//ַ��Ҳ�����޸�rr1���������rr1���޸ģ�������const int&& rr1 ȥ����
//
//int main()
//{
//	double x = 1.1, y = 2.2;
//	int&& rr1 = 10;
//	const double&& rr2 = x + y;
//	rr1 = 20;
//	rr2 = 5.5;//����
//	return 0;
//}

//��ֵ����
//1. ��ֵ����ֻ��������ֵ������������ֵ��
//2. ����const��ֵ���üȿ�������ֵ��Ҳ��������ֵ��
//��ֵ����
//1. ��ֵ����ֻ����ֵ������������ֵ��
//2. ������ֵ���ÿ���move�Ժ����ֵ��
//int main()
//{
//	int a = 10;
//	int& ra = a;
//	//int& ra = 10;//����
//	//const����������ֵ��Ҳ��������ֵ
//	const int& ra2 = a;
//	const int& ra3 = 10;
//	
//	int&& rb1 = 20;
//	int b = 20;
//	//int&& rb2 = b;//����
//	int&& rb3 = std::move(b);
//	return 0;
//}

//��ֵ����ʹ�ó���������
#include "string.h"

//void func1(lzb::string s)
//{}
//void func2(const lzb::string& s)
//{}
//int main()
//{
//	lzb::string s1("hello world");
//	// func1��func2�ĵ��ÿ��Կ�����ֵ���������������˿��������Ч�ʵ�ʹ�ó����ͼ�ֵ
//	func1(s1);
//	func2(s1);
//	// string operator+=(char ch) ��ֵ���ش������
//	// string& operator+=(char ch) ����ֵ����û�п��������Ч��
//	s1 += '!';
//	return 0;
//}

//// �ƶ�����
//string(string&& s)
//	:_str(nullptr)
//	, _size(0)
//	, _capacity(0)
//{
//	cout << "string(string&& s) -- �ƶ�����" << endl;
//	swap(s);
//}
//// �ƶ���ֵ
//string& operator=(string&& s)
//{
//	cout << "string& operator=(string&& s) -- �ƶ�����" << endl;
//	swap(s);
//	return *this;
//}
namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			//cout << "string(char* str)" << endl;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		// s1.swap(s2)
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}
		// ��������
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- ���" << endl;
			string tmp(s._str);
			swap(tmp);
		}
		// ��ֵ����
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- ���" << endl;
			string tmp(s);
			swap(tmp);
			return *this;
		}
		// �ƶ�����
		string(string&& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(string&& s) -- �ƶ�����" << endl;
			swap(s);
		}
		// �ƶ���ֵ
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- �ƶ���ֵ" << endl;
			swap(s);
			return *this;
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity; // �������������ʶ��\0
	};
	bit::string to_string(int value)
	{
		bool flag = true;
		if (value < 0)
		{
			flag = false;
			value = 0 - value;
		}
		bit::string str;
		while (value > 0)
		{
			int x = value % 10;
			value /= 10;
			str += ('0' + x);
		}
		if (flag == false)
		{
			str += '-';
		}
		std::reverse(str.begin(), str.end());
		return str;
	}
}

//int main()
//{
//	// ��bit::string to_string(int value)�����п��Կ���������
//	// ֻ��ʹ�ô�ֵ���أ���ֵ���ػᵼ������1�ο�������(�����һЩ��һ��ı��������������ο�������)��
//	/*bit::string ret1 = bit::to_string(1234);
//	bit::string ret2(ret1);
//	bit::string ret3;
//	ret3 = bit::to_string(1234);*/
//	lzb::string s1 = "11111111111111";
//	lzb::string s2(forward<lzb::string>(s1));
//	return 0;
//}

//int& func1(int& x)
//{
//	int a = x;
//	cout << "int& func1(int& x)" << endl;
//	return a;
//}
//int& func1(int&& x)
//{
//	int a = x;
//	cout << "int& func2(int&& x)" << endl;
//	return a;
//}
//int main()
//{
//	int a;
//	func1(a);
//	func1(10);
//	return 0;
//}

// ģ���е�&&��������ֵ���ã������������ã�����ܽ�����ֵ���ܽ�����ֵ��
// ģ�����������ֻ���ṩ���ܹ�����ͬʱ������ֵ���ú���ֵ���õ�������
// �����������͵�Ψһ���þ��������˽��յ����ͣ�����ʹ���ж��˻�������ֵ��
// ����ϣ���ܹ��ڴ��ݹ����б���������ֵ������ֵ������, ����Ҫ���������������ת��
void Fun(int& x) { cout << "��ֵ����" << endl; }
void Fun(const int& x) { cout << "const��ֵ����" << endl; }
void Fun(int&& x) { cout << "��ֵ����" << endl; }
void Fun(const int&& x) { cout << "const��ֵ����" << endl; }
template<class T>
void PerfectForword(T&& t)
{
	//Fun(t);
	//����forward��������ת����������������
	Fun(forward<T>(t));
}
//int main()
//{
//	PerfectForword(10);
//	int a = 10;
//	PerfectForword(a);
//	PerfectForword(std::move(a));
//	const int b = 10;
//	PerfectForword(b);
//	PerfectForword(std::move(b));
//	return 0;
//}

#include "list.h"

//int main()
//{
//	//��������ת����ȫ������ֵ����
//	lzb::list<string> lt;
//	std::string s1("111111111111111111111");
//	lt.push_back(move(s1));
//	return 0;
//}

//lambda���ʽ
#include <algorithm>
#include <functional>
#include <vector>
//int main()
//{
//	int array[] = { 4,1,8,5,3,7,0,9,2,6 };
//	// Ĭ�ϰ���С�ڱȽϣ��ų������������
//	std::sort(array, array + sizeof(array) / sizeof(array[0]));
//	// �����Ҫ������Ҫ�ı�Ԫ�صıȽϹ���
//	std::sort(array, array + sizeof(array) / sizeof(array[0]), greater<int>());
//	return 0;
//}

struct Goods
{
	string _name; // ����
	double _price; // �۸�
	int _evaluate; // ����
	Goods(const char* str, double price, int evaluate)
		:_name(str)
		, _price(price)
		, _evaluate(evaluate)
	{}
};
class ComparePriceLessGoods{
public:
	bool operator()(const Goods& g1, const Goods& g2) {
		return g1._price < g2._price;
	}
};
class ComparePriceGreaterGoods {
public:
	bool operator()(const Goods& g1, const Goods& g2) {
		return g1._price > g2._price;
	}
};
class CompareEvaluateLessGoods {
public:
	bool operator()(const Goods& g1, const Goods& g2) {
		return g1._evaluate < g2._evaluate;
	}
};
class CompareEvaluateGreaterGoods {
public:
	bool operator()(const Goods& g1, const Goods& g2) {
		return g1._evaluate > g2._evaluate;
	}
};
int main()
{
	std::vector<Goods> v = { { "ƻ��", 2.1, 5 }, { "�㽶", 3, 4 }, { "����", 2.2,
	3 }, { "����", 1.5, 4 } };
	sort(v.begin(), v.end(), ComparePriceLessGoods());
	sort(v.begin(), v.end(), ComparePriceGreaterGoods());
	sort(v.begin(), v.end(), CompareEvaluateLessGoods());
	sort(v.begin(), v.end(), CompareEvaluateGreaterGoods());
	//lambda���ʽ
	auto ret=[](int val1, int val2)->bool {return val1 > val2; };
	cout << ret(1,2) << endl;

	auto ComparePriceLess = [](const Goods& g1, const Goods& g2)
								{return g1._price < g2._price; };
	auto ComparePriceGreater = [](const Goods& g1, const Goods& g2)
									{return g1._price > g2._price; };
	auto CompareEvaluateLess = [](const Goods& g1, const Goods& g2)
									{return g1._price < g2._price; };
	auto CompareEvaluateGreater = [](const Goods& g1, const Goods& g2)
									{return g1._price < g2._price; };
	sort(v.begin(), v.end(), ComparePriceLessGoods());
	sort(v.begin(), v.end(), ComparePriceGreaterGoods());
	sort(v.begin(), v.end(), CompareEvaluateLessGoods());
	sort(v.begin(), v.end(), CompareEvaluateGreaterGoods());

	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
						{return g1._price < g2._price; });
	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
						{return g1._price > g2._price; });
	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
						{return g1._price < g2._price; });
	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
						{return g1._price < g2._price; });
	return 0;
}





