#include <iostream>
using namespace std;
int calNumber(int n)
{
    int sum = 0;
    while (n > 1)
    {
        int res = n / 3;//换的瓶数
        int lef = n % 3;//剩余瓶盖数
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
// 64 位输出请用 printf("%lld")