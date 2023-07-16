#include <iostream>
using namespace std;

//int main(int argc, char* argv[])
//{
//	string a = "hello world";
//	string b = a;
//	if (a.c_str() == b.c_str())
//	{
//		cout << "true" << endl;
//	}
//	else cout << "false" << endl;
//	string c = b;
//	c = "";
//	if (a.c_str() == b.c_str())
//	{
//		cout << "true" << endl;
//	}
//	else cout << "false" << endl;
//	a = "";
//	if (a.c_str() == b.c_str())
//	{
//		cout << "true" << endl;
//	}
//	else cout << "false" << endl;
//	return 0;
//}

//int main()
//{
//	string str("Hello Bit.");
//	str.reserve(111);
//	str.resize(5);
//	str.reserve(50);
//	cout << str.size() << ":" << str.capacity() << endl;
//	return 0;
//}

//int main()
//{
//	string strText = "How are you?";
//	string strSeparator = " ";
//	string strResult;
//	int size_pos = 0;
//	int size_prev_pos = 0;
//	//注意是while不是if,只要strText后面有strSeparator就要截取
//	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)
//	{
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//		cout << strResult << " ";
//		size_prev_pos = ++size_pos;
//	}
//	if (size_prev_pos != strText.size())
//	{
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//		cout << strResult << " ";
//	}
//	cout << endl;
//	return 0;
//}

#include <iostream>
#include <string>

int main()
{
	std::string strText;
	std::string strResult;
	std::cin >> strText;
	string strSeparator = " ";
	size_t size_pos = 0;
	size_t size_prev_pos = 0;
	while ((size_pos = strText.find(strSeparator, size_pos)) != std::string::npos)
	{
		size_pos = ++size_prev_pos;
	}
	if (size_prev_pos != strText.size())  
	{
		strResult = strText.substr(size_prev_pos, size_pos);
		std::cout << strResult.size() << std::endl;
	}

	//size_t rightPos = str.rfind(" ", str.size());
	//cout << rightPos << endl;
	//cout << str.substr(rightPos) << endl;
	return 0;
}