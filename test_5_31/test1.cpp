#include <iostream>
using namespace std;
#include <string>

//int main()
//{
//    string s1;
//    size_t size = s1.capacity();
//    s1.reserve(100);
//    for (int i = 0; i < 100; ++i)
//    {
//        s1.push_back('x');
//        if (size != s1.capacity())
//        {
//            size = s1.capacity();
//            cout << "容量:" << s1.capacity() << endl;
//        }
//    }
//    s1.reserve(10);
//    cout << "容量:" << s1.capacity() << endl;
//}

//容量是否缩容与clear有关
//int main()
//{
//    string s1;
//    size_t size = s1.capacity();
//    s1.reserve(100);
//    for (int i = 0; i < 100; ++i)
//    {
//        s1.push_back('x');
//        if (size != s1.capacity())
//        {
//            size = s1.capacity();
//            cout << "容量:" << s1.capacity() << endl;
//        }
//    }
//    s1.clear();
//    s1.reserve(10);
//    cout << "容量:" << s1.capacity() << endl;
//}

//void TestPushBackReserve()
//{
//	string s;
//	s.reserve(100);
//	size_t sz = s.capacity();
//	cout << "capacity changed: " << sz << '\n';
//	cout << "making s grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		s.push_back('c');
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//	s.clear();
//	cout << "capacity changed: " << sz << '\n';
//	s.reserve(10);
//	sz = s.capacity();
//	cout << "capacity changed: " << sz << '\n';
//}
//
//int main()
//{
//	TestPushBackReserve();
//	return 0;
//}
 
//int main()
//{
//	string s1("hello world");
//	cout << s1 << endl;
//	cout << s1.capacity() << endl;
//	//s1.clear();
//	//cout << s1.max_size() << endl;
//	size_t old = s1.capacity();
//	for (size_t i = 0; i < 100; ++i)
//	{
//		s1 += 'x';
//		if (old != s1.capacity())
//		{
//			cout << "扩容:" << s1.capacity() << endl;
//			old = s1.capacity();
//		}
//	}
//	return 0;
//}


//int main()
//{
//	string s1("hello world");
//	s1.at(0) = 'x';
//	cout << s1 << endl;
//	//s1.at(15) = 'm';
//	//s1[15] = 'x';
//
//	s1.append("123445");
//	cout << s1 << endl;
//	cout << "capacity::" << s1.capacity() << endl;
//	s1.assign("abcdef");
//	cout << s1 << endl;
//	cout<<"capacity::"<<s1.capacity();
//
//	return 0;
//}

//
//int main()
//{
//	string s1("hello world");
//	s1.insert(0, "xxxxx");
//	s1.insert(10,3,'m');
//	cout << s1 << endl;
//	s1.erase(0, 5);
//	cout << s1 << endl;
//	s1.erase(5);
//	cout << s1 << endl;
//	cout << "=================" << endl;
//
//	string s2("hello world");
//	s2.replace(5,1,10,'x');
//	cout << s2 << endl;
//	s2.replace(5, 10, "hahahaha");
//	cout << s2 << endl;
//	cout << "======================" << endl;
//	//replace 应用
//	//将空格替换成20%
//	string s3 = "hello world haha lzb";
//	cout << s3 << endl;
//	string s4;
//	for (auto ch : s3)
//	{
//		if (ch != ' ')
//			s4 += ch;
//		else
//			s4 += "20%";
//	}
//	cout << s4 << endl;
//
//	//c_str是直接指向的字符数组的空间
//	//cout << s2.c_str();
//	
//	//使用场景一般是为了兼容C语言的一套接口
//	//string filename = "test.cpp";
//	//FILE* fout1 = fopen(filename.c_str(), "r");
//	//FILE* fout2 = fopen(s2.c_str(), "r");
//	
//	return 0;
//}



int main()
{
	//string s1("hello world");
	//string s2 = s1.substr(0, 5);
	//cout << s2 << endl;

	//substr切割字符串
	//配合find完成切割的功能 
	// 
	//string s1 = "https://legacy.cplusplus.com/reference/string/string/substr/";
	//string s2;
	//s2=s1.substr(0,s1.find("://"));
	//cout << s2 << endl;

	string url = "https://legacy.cplusplus.com/reference/string/string/substr/";
	// 协议 域名 资源名
	string agreement;
	size_t pos1 = url.find("://");
	if (pos1 != string::npos)
	{
		agreement = url.substr(0, pos1);
	}
	cout << agreement << endl;

	string domain;
	size_t pos2 = url.find("/", pos1 + 3);
	if (pos2 != string::npos)
	{
		domain = url.substr(pos1 + 3, pos2 - (pos1 + 3));
	}
	cout << domain << endl;

	string uri;
	size_t pos3 = pos2 + 1;
	uri = url.substr(pos3);
	cout << uri << endl;

	return 0;
}




