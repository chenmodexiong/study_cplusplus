
//����
//����һ���ַ���str������ַ���str�е�����������ִ�
//����������
//�������������1������������һ���ַ���str�����Ȳ�����255��
//���������
//��һ�������str��������������ִ���
//ʾ��1
//���룺
//abcd12345ed125ss123456789
//����
//�����
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
// 64 λ������� printf("%lld")

//����
//��һ������Ϊ n �����飬��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
//��������һ������Ϊ9������[1, 2, 3, 2, 2, 2, 5, 4, 2]����������2�������г�����5�Σ�
//�������鳤�ȵ�һ�룬������2��
//O(n)
//����������
//��֤��������ǿգ��ұ�֤�н�
//ʾ��1
//���룺
//[1, 2, 3, 2, 2, 2, 5, 4, 2]
//����
//����ֵ��
//2
//����
//ʾ��2
//���룺
//[3, 3, 3, 3, 2, 2, 2]
//����
//����ֵ��
//3

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param numbers int����vector
     * @return int����
     */
     //��һ��˼·
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
    //�ڶ���˼·,�����ͷ�����
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