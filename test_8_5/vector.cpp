#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void test_vector1()
{
	//vector<char> v1;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector2()
{
	vector<string> v;
	
	string s1("张三");
	v.push_back(s1);

	v.push_back(string("张三"));

	v.push_back("张三");

}

void test_vector3()
{
	vector<int> v1(10, 1);
	vector<string> v2(10, "*****");

	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << "============================================================" << endl;
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << "============================================================" << endl;
	vector<int> v3(v1.begin(), v1.end());
	for (auto e : v3)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << "============================================================" << endl;
	string s("hello world");
	vector<char> v4(s.begin(), s.end());
	for (auto e : v4)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << "============================================================" << endl;
	int a[] = { 10,20,30,40,50 };
	vector<int> v5(a, a + 4);
	for (auto e : v5)
	{
		cout << e << " ";
	}
	cout << endl;

}

void test_vector4()
{
	int a[] = { 10,2,3,40,0 };
	vector<int> v5(a, a + 4);
	for (auto e : v5)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << "============================================================" << endl;
	//升序
	sort(v5.begin(), v5.end());
	for (auto e : v5)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << "============================================================" << endl;
	//降序
	sort(v5.rbegin(), v5.rend());
	for (auto e : v5)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << "============================================================" << endl;
	//降序
	/*greater<int> gt;
	sort(v5.begin(), v5.end(), gt);*/
	sort(v5.begin(), v5.end(), greater<int>());
	for (auto e : v5)
	{
		cout << e << " ";
	}
	cout << endl;

}

void test_vector5()
{
	vector<int> v1;
	v1.resize(10);
	for (int i = 0; i < 10; ++i)
	{
		v1[i] = i;
	}
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int> v2;
	v2.reserve(10);
	for (int i = 0; i < 10; ++i)
	{
		//v2[i] = i;//错误
		v2.push_back(i);
	}
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;

}

void test_vector6()
{
	int a[] = { 10,20,3,40,3,50,3,60,61,99 };
	vector<int> v1(a, a + sizeof(a) / sizeof(a[0]));
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << "=======================================================================" << endl;
	//头插
	v1.insert(v1.begin(), 1);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << "=======================================================================" << endl;
	//头删
	v1.erase(v1.begin() + 1);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << "=======================================================================" << endl;
	//没有find,怎么删除3
	/*vector<int>::iterator pos = std::find(v1.begin(), v1.end(), 3);
	v1.erase(pos);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;*/
	//如何删除全部的3
	//迭代器失效问题
	vector<int>::iterator pos = std::find(v1.begin(), v1.end(), 3);
	while (pos != v1.end())
	{
		v1.erase(pos);
		//pos = std::find(pos + 1, v1.end(), 3);
		pos = std::find(v1.begin(), v1.end(), 3);
	}
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << "=======================================================================" << endl;
	v1.assign(10,1);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << "=======================================================================" << endl;
}

void test_vector_expand()
{
	vector<int> v1;
	size_t sz;
	sz = v1.capacity();
	for (size_t i = 0; i < 200; ++i)
	{
		v1.push_back(i);
		if (sz != v1.capacity())
		{
			sz = v1.capacity();
			cout << "v capacity is " << sz << endl;
		}
	}
}

int main()
{
	//test_vector1();
	//test_vector2();
	//test_vector3();
	//test_vector4();
	//test_vector5();
	//test_vector6();
	test_vector_expand();
	return 0;
}

//给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
//你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。

class Solution {
public:
	int singleNumber(vector<int>& nums)
	{
		int value = 0;
		for (auto e : nums)
		{
			value ^= e;
		}
		return value;
	}
};

//给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
//在「杨辉三角」中，每个数是它左上方和右上方的数的和。

class Solution {
public:
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> vv;
		vv.resize(numRows);
		for (size_t i = 0; i < vv.size(); ++i)
		{
			vv[i].resize(i + 1, 0);
			vv[i][0] = vv[i][i] = 1;
		}
		for (size_t i = 0; i < vv.size(); ++i)
		{
			for (size_t j = 0; j < vv[i].size(); ++j)
			{
				if (vv[i][j] == 0)
				{
					vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
				}
			}
		}
		return vv;
	}
};