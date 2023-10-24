#include <iostream>

#include <list>
using namespace std;

//Args��һ��ģ���������args��һ�������ββ�����
//����һ��������Args..args������������п��԰�����0�������ģ�����
template<class ...Args>
void ShowList1(Args... args)
{}

//�����޷�ֱ�ӻ�ȡ������args�е�ÿ�������ģ�
//ֻ��ͨ��չ���������ķ�ʽ����ȡ�������е�ÿ��������
//����ʹ�ÿɱ�ģ�������һ����Ҫ�ص㣬Ҳ�������ѵ㣬
//�����չ���ɱ�ģ�����

//1.�ݹ麯����ʽչ��
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

//2.���ű��ʽչ��������

//���ű��ʽ�ᰴ˳��ִ�ж���ǰ��ı��ʽ
//ͬʱ���õ���C++11������һ�����ԡ�����ʼ���б�ͨ����ʼ���б�����ʼ��һ���䳤����
//���ջᴴ��һ��Ԫ��ֵ��Ϊ0������int arr
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
// emplaceϵ�еĽӿڣ�֧��ģ��Ŀɱ������������������
//template <class... Args>
//void emplace_back(Args&&... args);
//int main()
//{
//	std::list< std::pair<int, char> > mylist;
//	// emplace_back֧�ֿɱ�������õ�����pair����Ĳ������Լ�ȥ��������
//	// ��ô���������ǿ��Կ��������÷��ϣ���push_backûʲô̫�������
//
//	mylist.emplace_back(10, 'a');
//	mylist.emplace_back(20, 'b');
//	mylist.emplace_back(make_pair(30, 'c'));
//	mylist.push_back(make_pair(40, 'd'));
//	mylist.push_back({ 50, 'e' });
//	for (auto e : mylist)
//		cout << e.first << ":" << e.second << endl;
//
//	// ���п���������ƶ������string����������
//	// ���ǻᷢ����ʵ���Ҳ������emplace_back��ֱ�ӹ����ˣ�push_back
//	// ���ȹ��죬���ƶ����죬��ʵҲ���á�
//
//	return 0;
//}

//����Ĭ�ϳ�Ա����
//C++11 �������������ƶ����캯�����ƶ���ֵ���������

//û���Լ�ʵ���ƶ����캯������û��ʵ���������� ���������졢������ֵ�����е���
//��һ������ô���������Զ�����һ��Ĭ���ƶ����졣Ĭ�����ɵ��ƶ����캯��������������
//�ͳ�Ա��ִ�����Ա���ֽڿ������Զ������ͳ�Ա������Ҫ�������Ա�Ƿ�ʵ���ƶ����죬
//���ʵ���˾͵����ƶ����죬û��ʵ�־͵��ÿ�������
// 
//������ṩ���ƶ���������ƶ���ֵ�������������Զ��ṩ��������Ϳ�����ֵ

// ���´�����vs2013�в������֣���vs2019�²�����ʾ������������ԡ�

namespace lzb
{
	//ģ��ʵ��string
	class string
	{
	public:
		//Ĭ�Ϲ���--����ʼ����
		string(const char* str = "") //ע������Ŀ��ַ���,��ʵ�С�\0��
		{							//Ϊ�˽��"δ��ʼ������"��Ĭ�Ϲ��캯��������
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			//strcpy(_str, str);
			memcpy(_str, str, _size + 1);
		}
		//����
		/*~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}*/
		//��������
		//string(const string& s)
		//{
		//	_str = new char[s._capacity + 1];
		//	//strcpy(_str, s._str);
		//	memcpy(_str, s._str, s._size + 1);
		//	_size = s._size;
		//	_capacity = s._capacity;
		//}
		//�ƶ�����
		string(string&& s)
		{
			cout << "�����ƶ�����" << endl;
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
			cout << "�����ƶ���ֵ" << endl;
			swap(s);
			return *this;
		}
		//��ֵ
		//void swap(string& s)
		//{
		//	std::swap(_str, s._str);
		//	std::swap(_size, s._size);
		//	std::swap(_capacity, s._capacity);
		//}
		////ȫ�Զ���ֵ
		//string& operator=(string tmp)
		//{
		//	swap(tmp);
		//	return *this;
		//}
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		/* ������д�� */
		//		string tmp(s);
		//		swap(tmp);
		//		/*std::swap(_str, tmp._str);
		//		std::swap(_size, tmp._size);
		//		std::swap(_capacity,tmp._capacity);*/

		//		/* ������ͳд�� */
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

