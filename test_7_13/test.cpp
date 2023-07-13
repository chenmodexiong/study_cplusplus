#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include "string.h"
void TestString1()
{
	lzb::string s1 = "hello world";
	std::cout << s1.c_str() << std::endl;
	std::cout << s1.size() << std::endl;

	//未初始化对象的问题
	//lzb::string s2 ;  
	//std::cout << s2.c_str() << std::endl;
	//std::string s2;
	//std::cout << s2.c_str() << std::endl;
	
	/*lzb::string s3="";
	std::cout << s3.c_str() << std::endl;
	std::cout << s3.size() << std::endl;*/

	for (size_t i = 0; i < s1.size(); ++i)
	{
		std::cout << s1[i] << " ";
	}
	std::cout << std::endl;
}
void TestString2()
{
	lzb::string s1 = "hello world";
	lzb::string::iterator it = s1.begin();
	while (it != s1.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	for (auto e: s1)//本质就是迭代器,简单替换，与上面代码含义相同
	{
		std::cout << e ;
	}
	std::cout << std::endl;
}

int main()
{
	TestString1();
	//TestString2();
	return 0;
}