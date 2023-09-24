#include "Priority_Queue.h"
void test_priority_queue1() {
	lzb::priority_queue<int> p;
	for (size_t i = 10; i < 20; ++i) {
		p.push((int)i);
	}
	while (!p.empty()) {
		cout << p.top() << " ";
		p.pop();
	}
}
template<class T>
class Less {
public:
	bool operator()(const T& val1, const T& val2) {
		return val1 < val2;
	}
};
void test_less() {
	Less<int> less;
	cout << boolalpha << less(1, 2) << endl;
}

int main() {
	test_priority_queue1();
	//test_less();
	return 0;
}
