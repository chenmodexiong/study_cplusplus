#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

//int main()
//{
//	string s1;
//	string s2("hello world");
//	string s3(s2);
//	string s4(10, '*');
//	string s5(s2, 6);
//	string s6(s2, 6,10);
//	//cout << s5 << endl;
//	//cout << s6 << endl;
//
//	s2 += " you can see me";
//	cout << s2 << endl;
//	//s3.append(" you can see me");
//	//s3.append(10, '*');
//
//	cout << s3 << endl;
//	return 0;
//}

//#include <algorithm>
//int main()
//{
//	string s1("hello world");
//	for (size_t i = 0; i < s1.size(); ++i)
//	{
//		cout << s1[i] << " ";
//	}
//	cout << endl;
//	
//	string::iterator it = s1.begin();
//	for (it; it < s1.end(); it++)
//	{
//		//++(*it);
//		cout << *it;
//	}
//	/*for (auto& e : s1)
//	{
//		cout << e;
//	}*/
//	cout << endl;
//	reverse(s1.begin(), s1.end());
//	//sort(s1.begin(), s1.end());
//	for (auto& e : s1)
//	{
//		cout << e;
//	}
//	//char s3[] = "hello world";
//	//s3[1]++;
//	//s1[1];
//
//	return 0;
//}
//
//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	vector<int>::iterator vit = v.begin();
//	while (vit != v.end())
//	{
//		cout << *vit << ' ';
//		++vit;
//	}
//	reverse(v.begin(), v.end());
//	while (vit != v.end())
//	{
//		cout << *vit << ' ';
//		++vit;
//	}
//	cout << endl;
//	list<int> lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//	list<int>::iterator it = lt.begin();
//	for (it; it != lt.end(); ++it)
//	{
//		cout << *it << ' ';
//	}
//
//	return 0;
//}

int main()
{
	string s1("hello world");
	cout << s1.max_size() << endl;



	return 0;
}




