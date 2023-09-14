#pragma once
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
	template<class T,class Ref,class Ptr>
	struct __list_iterator {
		typedef list_node<T> Node;
		typedef __list_iterator<T,Ref,Ptr> self;
		Node* _node;
		__list_iterator(Node* node) : _node(node) {}
		Ref& operator*() const { return _node->_val; }
		Ptr operator->() const { return &_node->_val; }
		self& operator++() {
			_node = _node->_next;
			return *this;
		}
		self& operator++(int) {
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		bool operator!=(const self& it) const {
			return _node != it._node;
		}
		bool operator==(const self& it) const {
			return _node == it._node;
		}
	};

	//为了一个const_iterator设计过于冗余
	/*template<class T>
	struct __list_const_iterator {
		typedef list_node<T> Node;
		Node* _node;
		__list_const_iterator(Node* node) : _node(node) {}
		const T& operator*() { return _node->_val; }
		__list_const_iterator<T>& operator++() {
			_node = _node->_next;
			return *this;
		}
		__list_const_iterator<T>& operator++(int) {
			__list_const_iterator<T> tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		bool operator!=(const __list_const_iterator<T>& it) {
			return _node != it._node;
		}
		bool operator==(const __list_const_iterator<T>& it) {
			return _node == it._node;
		}
	};*/

	template<class T>
	class list
	{
	private:
		typedef list_node<T> Node;
	public:
		typedef __list_iterator<T,T&,T*> iterator;
		typedef __list_iterator<T,const T&,const T*> const_iterator;
		list() :_head(new Node) {
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
	cout << endl;
	it = lt.begin();
	while (it != lt.end()) {
		cout << ((*it)+=1) << " ";
		++it;
	}
	cout << endl;
	for (auto e : lt) {
		cout << e << " ";
	}
	cout << endl;
}

struct A
{
	A(int val1=0,int val2=0):_a(val1),_b(val2) {}

	int _a;
	int _b;
};

void test_list2()
{
	lzb::list<A> lt;
	lt.push_back(A(1, 1));
	lt.push_back(A(2, 2));
	lt.push_back(A(3, 3));
	lt.push_back(A(4, 4));

	lzb::list<A>::iterator it = lt.begin();
	while (it != lt.end()) {
		cout << (*it)._a << " " << (*it)._b << endl;
		++it;
	}
	cout << "====================================" << endl;
	it = lt.begin();
	while (it != lt.end()) {
		cout << it->_a << " " << it->_b << endl;
		++it;
	}

}