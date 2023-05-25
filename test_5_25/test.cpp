#include <iostream>
using namespace std;


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
//
//	return 0;
//}
//

//把字符串转换成整数
//描述
//将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为 0 或者字符串不是一个合法的数值则返回 0
//注意：
//①字符串中可能出现任意符号，出现除 + / -以外符号时直接输出 0
//②字符串中可能出现 + / -且仅可能出现在字符串首位。
//输入描述：
//输入一个字符串, 包括数字字母符号, 可以为空
//返回值描述：
//如果是合法的数值表达则返回该数字，否则返回0
//示例1
//输入：
//"+2147483647"
//复制
//返回值：
//2147483647
//复制
//示例2
//输入：
//"1a33"
//复制
//返回值：
//0

class Solution {
public:
    int StrToInt(string str)
    {
        if (str.size() == 0)
            return 0;
        int flag = 1;
        int index = 0;
        int num = 0;
        if (str[0] == '+' || str[0] == '-')
        {
            if (str[0] == '-')
            {
                flag = -1;
            }
            ++index;
        }
        while (index < str.size())
        {
            if (str[index] >= '0' && str[index] <= '9')
            {
                num = num * 10 + (str[index] - '0');
            }
            else
            {
                return 0;
            }
            ++index;
        }
        return num * flag;
    }
};


//力扣 415. 字符串相加
//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
//你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。
//示例 1：
//输入：num1 = "11", num2 = "123"
//输出："134"


class Solution {
public:
    string addStrings(string num1, string num2)
    {
        int end1 = num1.size() - 1, end2 = num2.size() - 1;
        string strRet;
        int carry = 0;//进位
        while (end1 >= 0 || end2 >= 0)
        {
            int val1 = end1 >= 0 ? num1[end1] - '0' : 0;
            int val2 = end2 >= 0 ? num2[end2] - '0' : 0;
            int ret = val1 + val2 + carry;
            carry = ret / 10;
            ret %= 10;
            strRet += ('0' + ret);
            --end1;
            --end2;
        }
        if (carry == 1)
        {
            strRet += '1';
        }
        reverse(strRet.begin(), strRet.end());
        return strRet;
    }
};









