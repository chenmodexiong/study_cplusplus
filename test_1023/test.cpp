#include <iostream>
using namespace std;
int calNumber(int n)
{
    int sum = 0;
    while (n > 1)
    {
        int res = n / 3;//����ƿ��
        int lef = n % 3;//ʣ��ƿ����
        sum += res;
        n = lef + res;
        if (n == 2) {
            sum++;
            break;
        }
    }
    return sum;
}
int main() {
    int n, ret;
    while (cin >> n)
    {
        if (n == 0) break;
        ret = calNumber(n);
        cout << ret << endl;
    }

    return 0;
}
// 64 λ������� printf("%lld")