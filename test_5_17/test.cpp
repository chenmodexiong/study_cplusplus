#include <iostream>
using namespace std;

//template<class T>
//T Add(const T& left, /*const*/ T& right)
//{
//	return left + right;
//}
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	Add(a1, a2);
//	Add(d1, d2);
//	Add(a1, (int)d1);
//	Add<int>(a1, d1);
//}


// ר�Ŵ���int�ļӷ�����
int Add(int left, int right)
{
	return left + right;
}
// ͨ�üӷ�����
template<class T>
T Add(T left, T right)
{
	return left + right;
}
void Test()
{
	Add(1, 2); // ���ģ�庯��ƥ�䣬����������Ҫ�ػ�
	Add<int>(1, 2); // ���ñ������ػ���Add�汾
}








