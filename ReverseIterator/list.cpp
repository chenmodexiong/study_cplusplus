#include "list.h"
void test_reverse_iterator1() {
	lzb::list<int> lt;
	for (size_t i = 20; i < 30; ++i) {
		lt.push_back((int)i);
	}
	lzb::list<int>::reverse_iterator rit = lt.rbegin();
	while (rit != lt.rend()) {
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}

int main()
{
	//test_list1();
	//test_list2();
	//test_list3();
	//test_list4();
	test_reverse_iterator1();


	return 0;
}

