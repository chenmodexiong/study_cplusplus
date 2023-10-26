#include <iostream>
using namespace std;
//function��װ�� Ҳ������������C++�е�function������һ����ģ�壬Ҳ��һ����װ����
//ret = func(x);
// ����func������ʲô�أ���ôfunc�����Ǻ�����������ָ�룿��������(�º�������)��Ҳ�п���
//��lamber���ʽ����������Щ���ǿɵ��õ����ͣ���˷ḻ�����ͣ����ܻᵼ��ģ���Ч�ʵ��£�
template<class F, class T>
T useF(F f, T x)
{
	static int count = 0;
	cout << "count:" << ++count << endl;
	cout << "count:" << &count << endl;
	return f(x);
}
double f(double i)
{
	return i / 2;
}
struct Functor
{
	double operator()(double d)
	{
		return d / 3;
	}
};
int main()
{
	// ������
	cout << useF(f, 11.11) << endl;
	// ��������
	cout << useF(Functor(), 11.11) << endl;
	// lamber���ʽ
	cout << useF([](double d)->double { return d / 4; }, 11.11) << endl;
	return 0;
}



