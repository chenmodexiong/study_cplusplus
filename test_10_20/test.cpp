#include <iostream>
using namespace std;

//HJ53 杨辉三角的变形
//以上三角形的数阵，第一行只有一个数1，
//以下每行的每个数，是恰好是它上面的数、左上角数和右上角的数，
//3个数之和（如果不存在某个数，认为该数就是0）。
//求第n行第一个偶数出现的位置。如果没有偶数，则输出 - 1。
//例如输入3, 则输出2，输入4则输出3，输入2则输出 - 1。
//输入描述：
//输入一个int整数
//输出描述：
//输出返回的int值
//示例1
//输入：
//4
//复制
//输出：
//3
int main() {
	// int n;
	// while(cin >> n)
	// {
	//     代码有点捞，写的高级点
	//     if(n <= 2)
	//         cout << -1 << endl;
	//     else if(n % 4 == 1 || n % 4 == 3)
	//         cout << 2 << endl;
	//     else if (n % 4 == 2)
	//         cout << 4 << endl;
	//     else
	//         cout << 3 << endl;

	// }
	//     高级点
	int n;

	int Index[] = { 4, 2, 3, 2 };
	while (cin >> n) {
		int res = -1;
		if (n > 2)
			res = Index[(n - 2) % 4];
		cout << res << endl;
	}

	return 0;
}
//链接：https://www.nowcoder.com/questionTerminal/a35ce98431874e3a820dbe4b2d0508b1
//来源：牛客网
//计算某字符出现次数
//热度指数：1236521时间限制：C / C++ 1秒，其他语言2秒空间限制：C / C++ 32M，其他语言64M
//算法知识视频讲解
//写出一个程序，接受一个由字母、数字和空格组成的字符串，和一个字符，然后输出输入字符串中该字符的出现次数。
// （不区分大小写字母）
//输入描述 :
//第一行输入一个由字母、数字和空格组成的字符串，第二行输入一个字符（保证该字符不为空格）。
//输出描述 :
//输出输入字符串中含有该字符的个数。（不区分大小写字母）

#include<iostream>
using namespace std;
int main() {
	char ch;
	string s;
	getline(cin, s);
	cin >> ch;
	int count = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			if (s[i] == ch || s[i] + 32 == ch)
				count++;
		}
		else if (s[i] >= 'a' && s[i] <= 'z') {
			if (s[i] == ch || s[i] - 32 == ch)
				count++;
		}
		else if (s[i] == ch)
			count++;
	}
	cout << count;
	return 0;
}

