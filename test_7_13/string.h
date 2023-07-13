#include <iostream>
#include <cassert>

namespace lzb
{
	//模拟实现string
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator begin() const
		{
			return _str;
		}
		const_iterator end() const
		{
			return _str + _size;
		}

		string(const char* str = "") //注意这里的空字符串,其实有‘\0’
		{								 //为了解决未初始化对象的默认构造函数的问题
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity+1];
			strcpy(_str, str);
		}
		const char* c_str() const
		{
			return _str;
		}
		size_t size() const
		{
			return _size;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};

}


