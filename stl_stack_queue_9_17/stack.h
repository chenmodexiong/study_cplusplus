#pragma once

namespace lzb
{
	//template<class T, class Container = vector<T>>
	template<class T, class Container=deque<T>>
	class stack
	{
	public:
		void push(const T& x) { _con.push_back(x); }
		void pop() { _con.pop_back(); }
		T& top() { return _con.back(); }
		size_t size() { return _con.size(); }
		bool empty() { return _con.empty(); }
	private:
		Container _con;
	};
}

void test_stack1()
{
	lzb::stack<int, vector<int>> st1;
	for (size_t i = 0; i < 10; ++i) {
		st1.push((int)i);
	}

	while (!st1.empty()) {
		cout << st1.top() << " ";
		st1.pop();
	}
	cout << endl;
}
void test_stack2()
{
	lzb::stack<int> st1;
	for (size_t i = 0; i < 10; ++i) {
		st1.push((int)i);
	}

	while (!st1.empty()) {
		cout << st1.top() << " ";
		st1.pop();
	}
	cout << endl;
}
void test_stack3()
{
	lzb::stack<int, list<int>> st1;
	for (size_t i = 10; i < 20; ++i) {
		st1.push((int)i);
	}

	while (!st1.empty()) {
		cout << st1.top() << " ";
		st1.pop();
	}
	cout << endl;
}
