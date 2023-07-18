#include <iostream>
#include <string>
using namespace std;
//描述
//计算字符串最后一个单词的长度，单词以空格隔开，字符串长度小于5000。（注：字符串末尾不以空格为结尾）
//输入描述：
//输入一行，代表要计算的字符串，非空，长度小于5000。
//输出描述：
//输出一个整数，表示输入字符串最后一个单词的长度。
//示例1:
//输入：
//hello nowcoder
//输出：
//8
//说明：
//最后一个单词为nowcoder，长度为8

//int main()
//{
//    string str;
//    getline(cin, str);
//    size_t rightPos = str.rfind(" ", str.size());
//    cout << (str.size() - (rightPos + 1)) << endl;
//    return 0;
//}

//125. 验证回文串
//如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。
//则可以认为该短语是一个 回文串 。
//字母和数字都属于字母数字字符。
//给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。
//示例 1：
//输入 : s = "A man, a plan, a canal: Panama"
//输出：true
//解释："amanaplanacanalpanama" 是回文串。

class Solution {
public:
    bool isPalindrome(string s)
    {
        string tmp;
        for (size_t i = 0; i < s.size(); ++i)
        {
            if (s[i] >= '0' && s[i] <= '9' || s[i] >= 'a' && s[i] <= 'z')
            {
                tmp.push_back(s[i]);
            }
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                tmp.push_back(s[i] += 32);
            }
        }
        for (size_t i = 0; i < tmp.size(); ++i)
        {
            if (tmp[i] != tmp[tmp.size() - i - 1])
            {
                return false;
            }
        }
        return true;
    }
};



//541. 反转字符串 II
//给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
//如果剩余字符少于 k 个，则将剩余字符全部反转。
//如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
//示例 1：
//输入：s = "abcdefg", k = 2
//输出："bacdfeg"
//示例 2：
//输入：s = "abcd", k = 2
//输出："bacd"

class Solution {
public:
    string reverseStr(string s, int k)
    {
        for (size_t i = 0; i < s.size(); i += 2 * k)
        {
            if (i + k < s.size())
                reverse(s.begin() + i, s.begin() + k + i);
            else
                reverse(s.begin() + i, s.end());
        }
        return s;
    }
};



//557. 反转字符串中的单词 III
//给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
//示例 1：
//输入：s = "Let's take LeetCode contest"
//输出："s'teL ekat edoCteeL tsetnoc"
//示例 2:
//输入： s = "God Ding"
//输出："doG gniD"

class Solution {
public:
    string reverseWords(string s)
    {
        int start = 0;
        for (size_t i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ')
            {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        reverse(s.begin() + start, s.end());
        return s;
    }
};


//43. 字符串相乘
//给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
//注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
//示例 1:
//输入: num1 = "2", num2 = "3"
//输出 : "6"
//示例 2 :
//输入 : num1 = "123", num2 = "456"
//输出 : "56088"

#include <vector>
class Solution1 {
public:
    string multiply(string num1, string num2)
    {
        vector<int> numA, numB, numC;
        //注意这里是倒着插入
        for (int i = num1.size(); i >= 0; --i)
            numA.push_back(num1[i]);
        for (int i = num2.size(); i >= 0; --i)
            numB.push_back(num2[i]);
        //不考虑进位,存到数组中
        for (int i = 0; i < num1.size(); ++i)
        {
            for (int j = 0; j < num2.size(); ++j)
                numC[i + j] += numA[i] * numB[j];
        }
        //满10进位
        int t = 0;
        for (int i = 0; i < numC.size(); ++i)
        {
            t += numC[i];
            numC[i] %= 10;
            t /= 10;
        }

        int k = numC.size() - 1;
        while (k > 0 && !numC[k])
            k--;  //去除前导0
        //反转且转为字符串
        string res;
        while (k >= 0)
            res += numC[k--] + '0';
        return res;
    }
};


class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> A, B;
        int n = num1.size(), m = num2.size();
        for (int i = n - 1; i >= 0; i--) A.push_back(num1[i] - '0'); //反向存贮
        for (int i = m - 1; i >= 0; i--) B.push_back(num2[i] - '0');
        vector<int> C(n + m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                C[i + j] += A[i] * B[j];
        int t = 0;  //存贮进位
        for (int i = 0; i < C.size(); i++) {
            t += C[i];
            C[i] = t % 10;
            t /= 10;
        }
        int k = C.size() - 1;
        while (k > 0 && !C[k]) k--;  //去除前导0
        string res;
        while (k >= 0) res += C[k--] + '0';  //反转
        return res;
    }
};







