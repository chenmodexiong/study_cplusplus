#include "vector.h"
#include <iostream>
using namespace std;

void TestMemcpy()
{
	int* p = new int[10];
	int ch[5] = { 1,2,3,4,5 };
	memcpy(p, ch, sizeof(int) * 5);

	cout << p << endl;
	cout << ch << endl;
	for (int i = 0; i < 10; ++i)
		cout << p[i] << " ";
}
int main()
{
	//lzb::test_vector1();
	//lzb::test_vector2();
	//lzb::test_vector3(); 
	TestMemcpy();

	

	return 0;
}

