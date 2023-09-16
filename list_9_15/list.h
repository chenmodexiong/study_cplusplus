#pragma once
#pragma once
#include <iostream>
using namespace std;
#include <cassert>
namespace lzb
{
	template<class T>
	struct list_node //C++中struct就是public的class
	{  
		list_node<T>* _prev;
		list_node<T>* _next;
		T _val;
		list_node(const T& val = T()) :_prev(nullptr), _next(nullptr), _val(val) {}
	};
	template<class T,class Ref,class Ptr>
	struct __list_iterator 
	{
		typedef list_node<T> Node;
		typedef __list_iterator<T,Ref,Ptr> self;
		Node* _node;
		__list_iterator(Node* node) : _node(node) {}
		Ref& operator*() const 
		{ 
			return _node->_val; 
		}
		Ptr operator->() const 
		{ 
			return &_node->_val; 
		}
		self& operator++() 
		{
			_node = _node->_next;
			return *this;
		}
		self operator++(int) 
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		self& operator--() 
		{
			_node = _node->_prev;
			return *this;
		}
		self operator--(int) 
		{
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}
		bool operator!=(const self& it) const 
		{
			return _node != it._node;
		}
		bool operator==(const self& it) const 
		{
			return _node == it._node;
		}
	};

	template<class T>
	class list
	{
	private:
		typedef list_node<T> Node;
	public:
		typedef __list_iterator<T,T&,T*> iterator;
		typedef __list_iterator<T,const T&,const T*> const_iterator;
		void empty_init()
		{
			_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;
			_size = 0;
		}
		list() 
		{ 
			empty_init();
		}
		list<T>(const list<T>& lt)
		{
			empty_init();
			for (auto& e : lt) {
				push_back(e);
			}
		}
		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}
		//list& operator=(const list<T>& lt)
		list<T>& operator=(const list<T>& lt) 
		{
			swap(lt);
			return *this;
		}
		iterator begin() 
		{ 
			//return iterator(_head->_next); 
			return _head->_next; 
		}
		iterator end() 
		{ 
			return _head; 
		}
		const_iterator begin() const
		{
			return _head->_next;
		}
		const_iterator end() const
		{
			return _head;
		}
		void push_back(const T& x) 
		{
			insert(end(), x);
			/*Node* newnode = new Node(x);
			Node* tail = _head->_prev;
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;*/
		}
		void push_front(const T& x) 
		{
			insert(begin(), x);
		}
		void pop_back() 
		{
			erase(--end());
		}
		void pop_front() 
		{
			erase(begin());
		}
		size_t size() 
		{
			return _size;
		}
		iterator insert(iterator pos, const T& x) 
		{
			Node* newnode = new Node(x);
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			prev->_next = newnode;
			newnode->_next = cur;
			cur->_prev = newnode;
			newnode->_prev = prev;
			++_size;
			return newnode;
		}
		iterator erase(iterator pos) 
		{
			assert(pos != end());
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;
			prev->_next = next;
			next->_prev = prev;
			delete cur;
			--_size;
			return next;
		}
		void clear() 
		{
			iterator it = begin();
			while (it != end()) {
				it = erase(it);
			}
			_size = 0;
		}
		~list() 
		{
			clear();
			delete _head;
			_head = nullptr;
		}
	private:
		Node* _head;
		size_t _size;
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

void Print(const lzb::list<int>& lt)
{
	lzb::list<int>::const_iterator it = lt.begin();
	while (it != lt.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

void test_list3()
{
	lzb::list<int> lt;
	lt.push_back(1);
	lt.push_back(1);
	lt.push_back(1);
	lt.push_back(1);
	lt.push_front(2);
	lt.push_front(2);
	lt.push_front(2);
	lt.push_front(2);
	Print(lt);
	cout << "==========================================" << endl;
	lt.pop_back();
	Print(lt);
	cout << "==========================================" << endl;
	lt.pop_front();
	Print(lt);
	cout << "==========================================" << endl;
	lt.clear();
	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);
	lt.push_back(40);
	for (auto& e : lt) {
		cout << e << " ";
	}
	cout << endl;
	cout << "size():" << lt.size() << endl;
}


void test_list4()
{
	lzb::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lzb::list<int> lt2(lt);
	for (auto& e : lt2) {
		cout << e << " ";
	}
	cout << endl;
}











