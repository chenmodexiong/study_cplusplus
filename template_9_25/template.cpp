#include <iostream>
#include <vector>
#include <list>
#include <array>
using namespace std;
//void Print(const vector<int>& v) {
//	vector<int>::const_iterator it = v.begin();
//	while (it != v.end()) {
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//template<class Container>
template<class Container>
void Print(const Container& v) {
	//Container::const_iterator不确定是类型还是对象,例如,静态变量
	//所以用typename修饰,明确是类型,等模板实例化后去找
	typename Container::const_iterator it = v.begin();
	//auto it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
//非类型模板参数
template<class T,size_t N>
class Stack {
public:
	void func() {
		//N = 0;//常量,不能修改
	}
private:
	T _st[N];
	int _top;
};
int main() {
	/*vector<int> v;
	for (size_t i = 10; i < 20; ++i) {
		v.push_back((int)i);
	}
	Print(v);
	list<double> lt;
	for (double i = 1.5; i < 10.0; ++i) {
		lt.push_back(i);
	}
	Print(lt);*/
	/*Stack<int, 10> st1;
	Stack<double, 20> st2;
	st1.func();*/
	//
	//array对比原生数组优势,检查越界
	array<int, 10> a;
	int b[10];
	b[0] = 0, a[0] = 0;
	for (auto e : a) {
		cout << e << " ";
	}
	cout << endl;
	for (auto e : b) {
		cout << e << " ";
	}
	cout << endl;
	//a[10] = 10;
	//b[10] = 10;
	return 0;
}