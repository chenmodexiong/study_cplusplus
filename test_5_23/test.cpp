#include <iostream>
using namespace std;

int main()
{
	string s1;
	string s2("hello world");
	string s3(s2);
	string s4(10, '*');
	string s5(s2, 6);
	string s6(s2, 6,10);
	//cout << s5 << endl;
	//cout << s6 << endl;

	s2 += " you can see me";
	cout << s2 << endl;
	//s3.append(" you can see me");
	//s3.append(10, '*');

	cout << s3 << endl;
	


	return 0;
}

