#include <iostream>
#include <map>
#include <set>
using namespace std;

void test_set1()
{
	//排序+去重
	set<int> s;
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(4);
	s.insert(5);
	s.insert(7);
	s.insert(5);
	/*auto it=s.find(5);
	if (it != s.end())
	{
		cout << "找到了" << endl;
	}*/
	/*if (s.count(5))
	{
		cout << "找到了" << endl;
	}*/
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_set2()
{
	std::set<int> myset;
	std::set<int>::iterator itlow, itup;

	for (int i = 1; i < 10; i++) myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90

	itlow = myset.lower_bound(25);  //  >=    
	itup = myset.upper_bound(60);  //   >  
	std::pair<std::set<int>::const_iterator, std::set<int>::const_iterator> ret;
	ret = myset.equal_range(30);
	cout << *ret.first << endl;
	cout << *ret.second << endl;
	cout << "===========================" << endl;
	cout << *itlow << endl;
	cout << *itup << endl;
	myset.erase(itlow, itup);  // 10 20 70 80 90

	std::cout << "myset contains:";
	for (std::set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void test_set3()
{
	//排序
	multiset<int> s;
	s.insert(1);
	s.insert(3);
	s.insert(8);
	s.insert(4);
	s.insert(5);
	s.insert(5);
	s.insert(5);
	s.insert(5);
	s.insert(5);
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	//查找5有几个
	cout << s.count(5) << endl;
	//find返回中序第一个5
	auto pos = s.find(5);
	while (pos!=s.end())
	{
		cout << *pos << " ";
		++pos;
	}
	cout << endl;
	//删除所有的5
	std::pair<std::set<int>::const_iterator, std::set<int>::const_iterator> ret;
	ret = s.equal_range(5);
	auto itlow = ret.first;
	auto itup = ret.second;
	s.erase(itlow, itup);
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}
/*template <class T1, class T2>
pair<T1, T2> make_pair(T1 x, T2 y);*/

//template < class Key,                            // map::key_type
//	class T,                                       // map::mapped_type
//	class Compare = less<Key>,                     // map::key_compare
//	class Alloc = allocator<pair<const Key, T> >   // map::allocator_type
//> class map;
void test_map1()
{
	std::map<string, string> dict;
	std::pair<string, string> kv1("insert", "插入");
	dict.insert(kv1);
	dict.insert(pair<string, string>("sort", "排序"));

	dict.insert(make_pair("string", "字符串"));
	//c++11支持多参数的构造函数隐式类型转换
	dict.insert({ "string", "字符串" });
	//相当于dict.insert(pair<string, string>("sort", "排序"));
}
void test_map2()
{
	std::map<string, string> map1;
	map1.insert(make_pair("string", "字符串"));
	map1.insert(make_pair("sort", "排序"));
	map1.insert(make_pair("insert", "插入"));
	//只比较key，key相同则不插入，不覆盖，与val相同与否无关
	map1.insert(make_pair("insert", "xxxxx"));
	std::map<std::string, std::string>::iterator it = map1.begin();
	//两张访问方式
	while (it != map1.end())
	{
		//it->first = "xxx";//first不可修改
		//it->second = "xxx";//second可修改
		// 
		//std::cout << (*it).first << "," << (*it).second << endl;
		std::cout << it->first << "," << it->second << endl;
		++it;
	}
	for (const auto& e : map1)
	{
		std::cout << e.first << e.second << endl;
	}
}
void test_map3()
{
	//统计次数
	string arr[] = { "西瓜","苹果","香蕉","橘子","西瓜","苹果","西瓜"};
	std::map<std::string, int> countMap;
	//version 1
	/*for (const auto& e : arr)
	{
		auto it = countMap.find(e);
		if(it == countMap.end())
			countMap.insert(make_pair(e,1));
		else
			it->second++;
	}*/
	//version 2
	for (const auto& e : arr)
	{
		//A call to this function is equivalent to :
		//(*((this->insert(make_pair(k, mapped_type()))).first)).second
		countMap[e]++;
	}
	for (const auto& e : countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}
}
void test_map4()
{
	std::map<string, string> map1;
	map1.insert(make_pair("string", "字符串"));
	map1.insert(make_pair("sort", "排序"));
	map1.insert(make_pair("insert", "插入"));

	cout << map1["sort"] << endl; //查找（读）
	map1["map"];				//插入
	map1["map"] = "映射，地图";	//插入+修改
	map1["insert"] = "xxxx";	//修改
	map1["set"] = "集合";		//插入+修改(新增)

}
int main()
{
	//test_set1();
	//test_set2();
	//test_set3();
	//test_map3();
	test_map4();
	return 0;
}