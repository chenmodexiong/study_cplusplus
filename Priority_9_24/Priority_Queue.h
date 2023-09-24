#pragma once
#include <vector>
#include <iostream>
using namespace std;

namespace lzb
{
	template<class T>
	class Less {
	public:
		bool operator()(const T& val1, const T& val2) {
			return val1 < val2;
		}
	};
	template<class T, class Container = vector<T>,class compare=Less<int>>
	class priority_queue {
	private:
		void AdjustDown(int parent) {
			compare compare;
			int child = parent * 2 + 1;
			while (child < _con.size()) {
				//if (child + 1 < _con.size() && _con[child] < _con[child + 1]) {
				if (child + 1 < _con.size() && compare(_con[child],_con[child + 1])) {
					++child;
				}
				if (compare(_con[parent],_con[child])) {
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				} 
				else break;
			}
		}
		void AdjustUp(int child) {
			compare compare;
			int parent = (child - 1) / 2;
			while (child > 0) {
				if (compare(_con[parent],_con[child])) {
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else break;
			}
		}
	public:
		priority_queue() {}
		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last) {
			while (first != last) {
				_con.push_back(*first);
				++first;
			}
			for (size_t i = (_con.size() - 1 - 1) / 2; i >= 0; --i) {
				AdjustDown(i);
			}
		}
		void pop() {
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}
		void push(const T& x) {
			_con.push_back(x);
			AdjustUp((int)_con.size() - 1);
		}
		const T& top() { return _con[0]; }
		size_t size() { return _con.size(); }
		bool empty() { return _con.empty(); }
	private:
		Container _con;
	};
}
