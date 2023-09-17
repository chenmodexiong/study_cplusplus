#pragma once


namespace lzb
{
	//库里面并没有支持vector，pop_front效率太低，而是用list
	//template<class T, class Container = vector<T>>
	//template<class T, class Container = list<T>>
	template<class T, class Container = deque<T>>
	class queue
	{
	public:
		void push(const T& x) { _con.push_back(x); }
		void pop() { 
			//_con.pop_front(); 
			_con.erase(_con.begin());
		}
		T& front() { return _con.front(); }
		T& back() { return _con.back(); }
		size_t size() { return _con.size(); }
		bool empty() { return _con.empty(); }
	private:
		Container _con;
	};
}

void test_queue1()
{
	lzb::queue<int> q;
	for (size_t i = 20; i < 30; ++i) {
		q.push((int)i);
	}
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}