#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

template<class type>
void Print(const type& T)
{
	auto it = T.begin();
	while (it != T.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_list1()
{
	list<int> lt;
	for (size_t i = 0; i < 10; ++i)
	{
		lt.push_back((int)i);
	}
	lt.push_front(250);

	list<int>::iterator it = lt.begin();
	Print(lt);

	list<int>::iterator pos = std::find(lt.begin(), lt.end(), 5);
	lt.insert(pos, 100);
	Print(lt);

	auto pos2 = std::find(lt.begin(), lt.end(), 3);
	lt.erase(pos2);
	//erase后迭代器必然失效
	//*pos2++;
	Print(lt);

	cout << "reverse<contents>::=================================================" << endl;
	std::reverse(lt.begin(), lt.end());
	Print(lt);
	cout << "lt.reverse::========================================================" << endl;
	lt.reverse();
	Print(lt);

	lt.sort();
	Print(lt);
}

void test_op()
{
	list<int> lt;
	vector<int> v;
	int N = 10000000;
	v.reserve(N);
	for (size_t i = 0; i < N; ++i)
	{
		int x = rand();
		v.push_back(x);
		lt.push_back(x);
	}
	
	int begin1 = clock();
	lt.sort();
	int end1 = clock();

	int begin2 = clock();
	std::sort(v.begin(), v.end());
	int end2 = clock();
	
	cout << "lt.sort()::" << end1 - begin1 << endl;
	cout << "std::sort(v.begin(), v.end())::" << end2 - begin2 << endl;

}



int main()
{
	test_list1();
	//test_op();
	return 0;
}