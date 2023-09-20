#include <queue>
#include <iostream>
#include <vector>
using namespace std;

void test_priority_queue1()
{
	//priority_queue<int> p;
	priority_queue<int, vector<int>, greater<int>> p;
	for (size_t i = 10; i < 20; ++i) {
		p.push((int)i);
	}
	while (!p.empty()) {
		cout << p.top() << " ";
		p.pop();
	}
	cout << endl;
}


int main()
{
	test_priority_queue1();

	return 0;
}

