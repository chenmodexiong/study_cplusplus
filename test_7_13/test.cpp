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
		//*it += 1;//非const对象可读可写
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	for (auto e: s1)//本质就是迭代器,简单替换，与上面代码含义相同
	{
		std::cout << e ;
	}
	std::cout << std::endl;

	const lzb::string s2("testconststring");
	lzb::string::const_iterator cit = s2.begin();
	//auto cit = s2.begin();
	for (cit; cit != s2.end(); ++cit)
	{
		//*cit += 1; const对象只读
		std::cout << *cit ;
	}
	std::cout << std::endl;
}
void TestString3()
{
	lzb::string s1("TestString3");
	s1.push_back('#');
	std::cout << s1.c_str() << std::endl;
	s1.append("@you can see me");
	std::cout << s1.c_str() << std::endl;
	std::cout << "=========================================" << std::endl;

	lzb::string s2("");
	s2.push_back('$');
	std::cout << s2.c_str() << std::endl;
	s2.append("Test@you can see me");
	std::cout << s2.c_str() << std::endl;
	std::cout << "=========================================" << std::endl;

	lzb::string s3("TestString");
	s3 += '#';
	s3 += '@';
	std::cout << s3.c_str() << std::endl;
	s3 += "you can see me!!!";
	std::cout << s3.c_str() << std::endl;
}

void TestString4()
{
	lzb::string s1("TestStringInsert");
	s1.insert(4, 3, '#');
	std::cout << s1.c_str() << std::endl;
	s1.insert(0, 5, '$');
	std::cout << s1.c_str() << std::endl;
	std::cout << "====================================" << std::endl;
	lzb::string s2("TestStringInsertChar*");
	s2.insert(4, "you can see me!!!");
	std::cout << s2.c_str() << std::endl;
	s2.insert(0, "@@@@@@@@");
	std::cout << s2.c_str() << std::endl;
}

void TestString5()
{
	lzb::string s1("*****TestStringErase");
	std::cout << s1.c_str() << std::endl;
	s1.erase(0, 5);
	std::cout << s1.c_str() << std::endl;
	std::cout << "=======================================" << std::endl;
	lzb::string s2("*****TestStringErase");
	std::cout << s2.c_str() << std::endl;
	s2.erase(5);
	std::cout << s2.c_str() << std::endl;

}
void TestString6()
{
	//lzb::string s1("TestfindStringFind");
	//std::cout << s1.find('S', 0) << std::endl;
	//std::cout << s1.find('T', 0) << std::endl;
	//std::cout << s1.find('T', 1) << std::endl;
	//std::cout << "=========================================" << std::endl;
	//std::cout << s1.find("Findis", 1) << std::endl;
	//std::cout << s1.find("String", 1) << std::endl;
	//std::cout << s1.find("find", 1) << std::endl;
	// 
	//substr切割字符串
	//配合find完成切割的功能 
	using namespace std;
	lzb::string url = "https://legacy.cplusplus.com/reference/string/string/substr/";
	// 协议 域名 资源名
	size_t pos1 = url.find("://");
	if (pos1 != lzb::string::npos)
	{
		lzb::string agreement = url.substr(0, pos1);
		cout << agreement.c_str() << endl;
	}
	size_t pos2 = url.find('/', pos1 + 3);
	if (pos2 != lzb::string::npos)
	{
		lzb::string domain = url.substr(pos1 + 3, pos2 - (pos1 + 3));
		cout << domain.c_str() << endl;
	}
	lzb::string uri = url.substr(pos2 + 1);
	cout << uri.c_str() << endl;
}

void TestString7()
{
	std::string s1("TestStringResize");
	std::cout << s1.c_str() << std::endl;
	s1.resize(4);
	std::cout << s1.c_str() << std::endl;
	s1.resize(10,'#');
	std::cout << s1.c_str() << std::endl;
	s1.resize(20);
	std::cout << s1.c_str() << std::endl;
	std::cout << "==============================================" << std::endl;
	lzb::string s2("TestStringResize");
	std::cout << s2.c_str() << std::endl;
	s2.resize(4);
	std::cout << s2.c_str() << std::endl;
	s2.resize(10, '#');
	std::cout << s2.c_str() << std::endl;
	s2.resize(20);
	std::cout << s2.c_str() << std::endl;

}


int main()
{
	//TestString1();
	//TestString2();
	//TestString3();
	//TestString4();
	//TestString5();
	//TestString6();
	TestString7();
	return 0;
}