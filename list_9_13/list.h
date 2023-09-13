#pragma once
#include <iostream>
using namespace std;

namespace lzb
{
	template<class T>
	struct list_node {  //实际上是class，只是访问限定符都是public
		list_node<T>* _prev;
		list_node<T>* _next;
		T _val;
		list_node(const T& val = T()) :_prev(nullptr), _next(nullptr), _val(val) {}
	};
	template<class T>
	struct __list_iterator {
		typedef list_node<T> Node;
		Node* _node;
		__list_iterator(Node* node): _node(node) {}
		T& operator*() { return _node->_val; }
		__list_iterator<T>& operator++() {
			_node = _node->_next;
			return *this;
		}
		bool operator!=(const __list_iterator<T>& it) {
			return _node != it._node;
		}
	};
	template<class T>
	class list
	{
	private:
		typedef list_node<T> Node;
	public:
		typedef __list_iterator<T> iterator;
		list() :_head(new Node)  {
			_head->_prev = _head;
			_head->_next = _head;
		}
		iterator begin() { return _head->_next; }
		iterator end() { return _head; }
		void push_back(const T& x) {
			Node* newnode = new Node(x);
			Node* tail = _head->_prev;
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}

	private:
		Node* _head;
	};
}

void test_list1()
{
	lzb::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lzb::list<int>::iterator it = lt.begin();
	while (it != lt.end()) {
		cout << *it << " ";
		++it;
	}

}

