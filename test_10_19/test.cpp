//HJ56 ��ȫ������
//����
//��ȫ����Perfect number�����ֳ����������걸������һЩ�������Ȼ����
//�����е������ӣ����������������Լ�����ĺͣ������Ӻ�������ǡ�õ���������
//���磺28������Լ��1��2��4��7��14��28����ȥ������28�⣬����5������ӣ�1 + 2 + 4 + 7 + 14 = 28��
//����n�������n����(��n)��ȫ���ĸ�����
//����������
//����һ������n
//���������
//���������n����ȫ���ĸ���
#include <iostream>
using namespace std;
int FindNum(int n) {
    int sum, count;
    for (int i = 2; i <= n; ++i) {
        sum = 0;
        for (int j = 1; j < i; ++j) {
            if (i % j == 0) {
                sum += j;
            }
        }
        if (sum == i) count++;
    }
    return count;
}
int main() {
    int n;
    while (cin >> n) {
        cout << FindNum(n) << endl;
    }
    return 0;
}
// 64 λ������� printf("%lld")
// 

//OR44 �˿��ƴ�С
//����
//�˿�����Ϸ���Ӧ�ö��Ƚ���Ϥ�ˣ�һ������54����ɣ���3~A��2��4�ţ�С��1�ţ�����1�š������С�����������ַ����ַ�����ʾ�����У�Сдjoker��ʾС������дJOKER��ʾ������:)
//3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
//���������ƣ�������֮���á� - �����ӣ�ÿ���Ƶ�ÿ�����Կո�ָ����� - ������û�пո��磺4 4 4 4 - joker JOKER
//��Ƚ������ƴ�С������ϴ���ƣ���������ڱȽϹ�ϵ�����ERROR
//
//��������
//��1������ÿ���ƿ����Ǹ��ӣ����ӣ�˳�ӣ�����5�ţ���������ը�����ĸ����Ͷ����е�һ�֣���������������������뱣֤�����ƶ��ǺϷ��ģ�˳���Ѿ���С�������У�
//��2������ը���Ͷ������Ժ������ƱȽ�֮�⣬�������͵���ֻ�ܸ���ͬ���͵Ĵ��ڱȽϹ�ϵ���磬���Ӹ����ӱȽϣ������������Ƚϣ��������ǲ���������磺�����Ӳ�ֳɸ��ӣ�
//��3����С��������ƽʱ�˽�ĳ���������ͬ�����ӣ����ӣ������Ƚ������С��˳�ӱȽ���С�ƴ�С��ը������ǰ�����е��ƣ�ը��֮��Ƚ������С�������������ƣ�
//��4������������Ʋ��������ȵ������
//
//����ʾ��
//��1������ը���Ͷ���֮�⣬��������ͬ���ͱȽϡ�
//��2�������Ѿ���֤�Ϸ��ԣ����ü�������Ƿ��ǺϷ����ơ�
//��3�������˳���Ѿ�������С����������˲�����������.
//
//���ݷ�Χ����֤����Ϸ�
//����������
//���������ƣ�������֮���á� - �����ӣ�ÿ���Ƶ�ÿ�����Կո�ָ����� - ������û�пո���4 4 4 4 - joker JOKER��
//���������
//����������нϴ�����֣��������ӷ����˿���˳�򲻱䣬���Կո��������������ڱȽϹ�ϵ�����ERROR��
//ʾ��1
//���룺
//4 4 4 4 - joker JOKER
//����
//�����
//joker JOKER


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string FindMax(const string& brand)
{
    if (brand.find("joker JOKER") != string::npos)
        return "joker JOKER";

    int dash = brand.find('-');
    //�ֿ�������
    string car1 = brand.substr(0, dash);
    string car2 = brand.substr(dash + 1);

    //��ȡ�����Ƶ��������ж��Ƿ�����ͬ����
    int car1_cnt = count(car1.begin(), car1.end(), ' ') + 1;
    int car2_cnt = count(car2.begin(), car2.end(), ' ') + 1;

    //��ȡ�����Ƶĸ��Ե�һ����
    string car1_first = car1.substr(0, car1.find(' '));
    string car2_first = car2.substr(0, car2.find(' '));

    if (car1_cnt == car2_cnt) //�����Ƶ�������ͬ
    {
        string str = "345678910JQKA2jokerJOKER";
        if (str.find(car1_first) > str.find(car2_first))
            return car1;
        return car2;
    }

    if (car1_cnt == 4) //˵����ը��
        return car1;
    else if (car2_cnt == 4)
        return car2;

    return "ERROR";
}

int main()
{
    string brand, res;
    while (getline(cin, brand))
    {
        res = FindMax(brand);
        cout << res << endl;
    }
}







