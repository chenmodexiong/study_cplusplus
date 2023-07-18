#include <iostream>
#include <string>
using namespace std;
//����
//�����ַ������һ�����ʵĳ��ȣ������Կո�������ַ�������С��5000����ע���ַ���ĩβ���Կո�Ϊ��β��
//����������
//����һ�У�����Ҫ������ַ������ǿգ�����С��5000��
//���������
//���һ����������ʾ�����ַ������һ�����ʵĳ��ȡ�
//ʾ��1:
//���룺
//hello nowcoder
//�����
//8
//˵����
//���һ������Ϊnowcoder������Ϊ8

//int main()
//{
//    string str;
//    getline(cin, str);
//    size_t rightPos = str.rfind(" ", str.size());
//    cout << (str.size() - (rightPos + 1)) << endl;
//    return 0;
//}

//125. ��֤���Ĵ�
//����ڽ����д�д�ַ�ת��ΪСд�ַ������Ƴ����з���ĸ�����ַ�֮�󣬶������Ŷ��ͷ��Ŷ���һ����
//�������Ϊ�ö�����һ�� ���Ĵ� ��
//��ĸ�����ֶ�������ĸ�����ַ���
//����һ���ַ��� s��������� ���Ĵ� ������ true �����򣬷��� false ��
//ʾ�� 1��
//���� : s = "A man, a plan, a canal: Panama"
//�����true
//���ͣ�"amanaplanacanalpanama" �ǻ��Ĵ���

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



//541. ��ת�ַ��� II
//����һ���ַ��� s ��һ������ k�����ַ�����ͷ����ÿ������ 2k ���ַ����ͷ�ת�� 2k �ַ��е�ǰ k ���ַ���
//���ʣ���ַ����� k ������ʣ���ַ�ȫ����ת��
//���ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ��������ַ�����ԭ����
//ʾ�� 1��
//���룺s = "abcdefg", k = 2
//�����"bacdfeg"
//ʾ�� 2��
//���룺s = "abcd", k = 2
//�����"bacd"

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



//557. ��ת�ַ����еĵ��� III
//����һ���ַ��� s ������Ҫ��ת�ַ�����ÿ�����ʵ��ַ�˳��ͬʱ�Ա����ո�͵��ʵĳ�ʼ˳��
//ʾ�� 1��
//���룺s = "Let's take LeetCode contest"
//�����"s'teL ekat edoCteeL tsetnoc"
//ʾ�� 2:
//���룺 s = "God Ding"
//�����"doG gniD"

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


//43. �ַ������
//�����������ַ�����ʽ��ʾ�ķǸ����� num1 �� num2������ num1 �� num2 �ĳ˻������ǵĳ˻�Ҳ��ʾΪ�ַ�����ʽ��
//ע�⣺����ʹ���κ����õ� BigInteger ���ֱ�ӽ�����ת��Ϊ������
//ʾ�� 1:
//����: num1 = "2", num2 = "3"
//��� : "6"
//ʾ�� 2 :
//���� : num1 = "123", num2 = "456"
//��� : "56088"

#include <vector>
class Solution1 {
public:
    string multiply(string num1, string num2)
    {
        vector<int> numA, numB, numC;
        //ע�������ǵ��Ų���
        for (int i = num1.size(); i >= 0; --i)
            numA.push_back(num1[i]);
        for (int i = num2.size(); i >= 0; --i)
            numB.push_back(num2[i]);
        //�����ǽ�λ,�浽������
        for (int i = 0; i < num1.size(); ++i)
        {
            for (int j = 0; j < num2.size(); ++j)
                numC[i + j] += numA[i] * numB[j];
        }
        //��10��λ
        int t = 0;
        for (int i = 0; i < numC.size(); ++i)
        {
            t += numC[i];
            numC[i] %= 10;
            t /= 10;
        }

        int k = numC.size() - 1;
        while (k > 0 && !numC[k])
            k--;  //ȥ��ǰ��0
        //��ת��תΪ�ַ���
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
        for (int i = n - 1; i >= 0; i--) A.push_back(num1[i] - '0'); //�������
        for (int i = m - 1; i >= 0; i--) B.push_back(num2[i] - '0');
        vector<int> C(n + m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                C[i + j] += A[i] * B[j];
        int t = 0;  //������λ
        for (int i = 0; i < C.size(); i++) {
            t += C[i];
            C[i] = t % 10;
            t /= 10;
        }
        int k = C.size() - 1;
        while (k > 0 && !C[k]) k--;  //ȥ��ǰ��0
        string res;
        while (k >= 0) res += C[k--] + '0';  //��ת
        return res;
    }
};







