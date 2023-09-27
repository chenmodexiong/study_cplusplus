
//描述
//读入一个字符串str，输出字符串str中的连续最长的数字串
//输入描述：
//个测试输入包含1个测试用例，一个字符串str，长度不超过255。
//输出描述：
//在一行内输出str中里连续最长的数字串。
//示例1
//输入：
//abcd12345ed125ss123456789
//复制
//输出：
//123456789

#include <iostream>
using namespace std;
int main() {
    string str, cur, ret;
    getline(cin, str);
    for (int i = 0; i <= str.size(); ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            cur.push_back(str[i]);
        }
        else {
            if (cur.size() > ret.size()) {
                ret = cur;
            }
            else {
                cur.clear();
            }
        }
    }
    cout << ret << endl;
}
// 64 位输出请用 printf("%lld")

//描述
//给一个长度为 n 的数组，数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//例如输入一个长度为9的数组[1, 2, 3, 2, 2, 2, 5, 4, 2]。由于数字2在数组中出现了5次，
//超过数组长度的一半，因此输出2。
//O(n)
//输入描述：
//保证数组输入非空，且保证有解
//示例1
//输入：
//[1, 2, 3, 2, 2, 2, 5, 4, 2]
//复制
//返回值：
//2
//复制
//示例2
//输入：
//[3, 3, 3, 3, 2, 2, 2]
//复制
//返回值：
//3

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numbers int整型vector
     * @return int整型
     */
     //第一种思路
    // int MoreThanHalfNum_Solution(vector<int>& numbers) {
    //     if(numbers.empty()) {return 0;}
    //     sort(numbers.begin(),numbers.end());
    //     int midNum=numbers[numbers.size()/2];
    //     int count=0;
    //     for(int i=0;i<numbers.size();++i) {
    //         count++;
    //     }
    //     if(count>numbers.size()/2){
    //         return midNum;
    //     }
    //     else return 0;
    // }
    //第二种思路,众数和非众数
    int MoreThanHalfNum_Solution(vector<int>& numbers) {
        if (numbers.empty()) { return 0; }
        int result = numbers[0];
        int times = 1;
        for (int i = 1; i < numbers.size(); ++i) {
            if (times != 0) {
                if (numbers[i] != result) {
                    --times;
                }
                else {
                    ++times;
                }
            }
            else {
                result = numbers[i];
                times = 1;
            }
        }
        int count = 0;
        for (int i = 0; i < numbers.size(); ++i) {
            if (numbers[i] == result) {
                count++;
            }
        }
        if (count > numbers.size() / 2) {
            return result;
        }
        else
            return 0;
    }
};