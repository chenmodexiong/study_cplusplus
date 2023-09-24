#pragma once
#include <iostream>
#include <cassert>
#include <cstring>
#include <string>
using std::cout;
using std::endl;
#include "ReverseIterator.h"
namespace lzb
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef ReverseIterator<iterator, T&, T*> reverse_iterator;
		typedef ReverseIterator<const_iterator, const T&, const T*> const_reverse_iterator;
	public:
		vector() : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {}
		vector(size_t n,const T& x=T())
			:_start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
		{
			resize(n, x);
		}
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		vector(const vector<T>& v)
			:_start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
		{
			_start = new T[v.capacity()];
			memmove(_start, v._start, sizeof(T) * v.size());
			_finish = _start + v.size();
			_end_of_storage = _start + v.capacity();
		}

		//拷贝构造的另一种写法
		/*vector(const vector<T>& v)
			:_start(nullptr),_finish(nullptr),_end_of_storage(nullptr)
		{
			reserve(v.capacity());
			for (auto e : v)
			{
				push_back(e);
			}
		}*/
		
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish ;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}
		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}
		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					//不管memcpy或者memmove都是浅拷贝，涉及到自定义类型都会崩溃
					//memmove(tmp, _start, sizeof(T) * sz);
					
					for (size_t i = 0; i < sz; ++i)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}
		void push_back(const T& x)
		{
			/*if (_finish == _end_of_storage)
			  {
				  size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				  reserve(newcapacity);
			  }
			  *_finish = x;
			  ++_finish;*/
			insert(end(), x);
		}
		void pop_back()
		{
			erase(--end());
		}
		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish);
			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start;
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
				//迭代器失效问题
				pos = _start + len;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
			return pos;
		}

		size_t capacity()
		{
			return _end_of_storage - _start;
		}
		size_t size()
		{
			return _finish - _start;
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}
		const T& operator[](size_t pos) const
		{
			assert(pos < size());
			return _start[pos]; 
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);
			iterator it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				++it;
			}
			--_finish;
			return pos;
		}

		void resize(size_t n,const T& val=T())//匿名对象
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};

	void print(const vector<int>& v)
	{
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << "\n=======================================" << endl;
	}

	void test_vector2()
	{
		//vector<int> v2;
		//v2.push_back(1);
		//v2.push_back(2);
		//v2.push_back(3);
		//v2.push_back(4);
		//v2.push_back(5);
		//v2.insert(v2.begin(), 100);
		//print(v2);
		//v2.insert(v2.begin()+2, 200);
		//print(v2);
		//v2.insert(v2.end(), 500);
		//print(v2);

		//insert后迭代器可能失效,原因:扩容
		vector<int> v3;
		v3.push_back(1);
		v3.push_back(2);
		v3.push_back(3);
		v3.push_back(4);
		v3.push_back(5);
		v3.push_back(6);
		v3.push_back(7);
		//v3.push_back(8);
		vector<int>::iterator p = v3.begin();
		v3.insert(p+1, 100);
		print(v3);
		*p+=10;//迭代器失效
		print(v3);

	}

	void test_vector1()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(6);
		v1.push_back(7);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << "\n=======================================" << endl;
		lzb::vector<int>::iterator it = v1.begin();
		while (it != v1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << "\n=======================================" << endl;
		for (size_t i = 0; i < v1.size(); ++i)
		{
			v1[i]++;
		}
		print(v1);

	}
	void test_vector3()
	{
		//vector<int> v1;
		//v1.push_back(1);
		//v1.push_back(2);
		//v1.push_back(3);
		//v1.push_back(4);
		//v1.push_back(5);
		//print(v1);
		//v1.erase(v1.begin());
		//print(v1);

		vector<std::string> v;
		v.push_back("11111111111111111111111");
		v.push_back("22222222222222222222222");
		v.push_back("33333333333333333333333");
		v.push_back("44444444444444444444444");
		v.push_back("55555555555555555555555");
		for (auto& e : v)
		{
			cout << e << " ";
		}

	}

}
