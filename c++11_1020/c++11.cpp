#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

//�б��ʼ��
//struct Point
//{
//	int _x;
//	int _y;
//};
//int main()
//{
//	int array1[] = { 1, 2, 3, 4, 5 };
//	int array2[5] = { 0 };
//	Point p = { 1, 2 };
/////////////////////////////////////////////////
//	int array3[]{ 1,2,3,4,5 };
//	int array4[10]{ 0 };
//	Point p2{ 1,2 };
//	int x{ 2 };
//	int* pa = new int[4] {0};
//	return 0;
//}
//���캯��Ҳ���б��ʼ��
class Date {
public:
	Date(int year, int month, int day)
		:_year(year), _month(month), _day(day) {
		cout << "Date(int year,int month,int day) " << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};
//int main() {
//	//old style
//	Date d1(2023, 10, 18);
//	//c++11����д��
//	Date d2{ 2023,10,17 };
//	Date d3 = { 2023,10,16 };
//	return 0;
//}


//std::initializer_list
//int main()
//{
//	// the type of il is an initializer_list
//	auto il = { 10, 20, 30 };
//	cout << typeid(il).name() << endl;
//	return 0;
//}
//ʹ�ó���
//std::initializer_listһ������Ϊ���캯���Ĳ�����C++11��STL�еĲ�������������
//std::initializer_list��Ϊ�����Ĺ��캯����������ʼ����������͸������ˡ�Ҳ������Ϊoperator =
//�Ĳ����������Ϳ����ô����Ÿ�ֵ��

//int main()
//{
//	vector<int> v = { 1,2,3,4 };
//	list<int> lt = { 1,2 };
//	 ����{"sort", "����"}���ȳ�ʼ������һ��pair����
//	map<string, string> dict = { {"sort", "����"}, {"insert", "����"} };
//	 ʹ�ô����Ŷ�������ֵ
//	v = { 10, 20, 30 };
//	return 0;
//}

//�Զ�������ʵ��{}�б��ʼ��
namespace bit
{
	template<class T>
	class vector {
	public:
		typedef T* iterator;
		vector(initializer_list<T> l)
		{
			_start = new T[l.size()];
			_finish = _start + l.size();
			_endofstorage = _start + l.size();
			iterator vit = _start;
			typename initializer_list<T>::iterator lit = l.begin();
			while (lit != l.end())
			{
				*vit++ = *lit++;
			}
			//for (auto e : l)
			// *vit++ = e;
		}
		vector<T>& operator=(initializer_list<T> l) {
			vector<T> tmp(l);
			std::swap(_start, tmp._start);
			std::swap(_finish, tmp._finish);
			std::swap(_endofstorage, tmp._endofstorage);
			return *this;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
}
//int main()
//{
//	bit::vector<int> v = { 1,2,3,4 };
//	std::vector<int> v2 = { 1,2,3,4 };
//	auto il = { 1,2,3,4 };
//	cout << typeid(v).name() << endl;
//	cout << typeid(v2).name() << endl;
//	cout << typeid(il).name() << endl;
//	return 0;
//}

//auto
//int main()
//{
//	auto val1 = "1111111111111111111111";
//	auto val2 = { 1,2,3,4 };
//	auto val3 = strcpy;
//	auto val4 = main;
//	cout << typeid(val1).name() << endl;
//	cout << typeid(val2).name() << endl;
//	cout << typeid(val3).name() << endl;
//	cout << typeid(val4).name() << endl;
//	map<string, string> dict = { {"sort", "����"}, {"insert", "����"} };
//	//map<string, string>::iterator it = dict.begin();
//	auto it = dict.begin();
//	cout << typeid(it).name() << endl;
//	return 0;
//}


// decltype��һЩʹ��ʹ�ó���
template<class T1, class T2>
void F(T1 t1, T2 t2)
{
	decltype(t1 * t2) ret;
	cout << typeid(ret).name() << endl;
}
//int main()
//{
//	const int x = 1;
//	double y = 2.2;
//	decltype(x * y) ret; // ret��������double
//	decltype(&x) p; // p��������int*
//	cout << typeid(ret).name() << endl;
//	cout << typeid(p).name() << endl;
//	F(1, 'a');
//	return 0;
//}

//
//����C++��NULL�������������0�������Ϳ��ܻش���һЩ���⣬��Ϊ0����ָ�볣�������ܱ�ʾ
//���γ��������Գ��������Ͱ�ȫ�ĽǶȿ��ǣ�C++11��������nullptr�����ڱ�ʾ��ָ��
//#ifndef NULL
//#ifdef __cplusplus
//#define NULL 0
//#else
//#define NULL ((void *)0)
//#endif
//#endif
// 
//int main()
//{
//	NULL;
//	nullptr;
//	return 0;
//}


