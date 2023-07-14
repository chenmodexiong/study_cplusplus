#include <iostream>
#include <cassert>

namespace lzb
{
	//ģ��ʵ��string
	class string
	{
	public:
		//Ĭ�Ϲ���--����ʼ����
		string(const char* str = "") //ע������Ŀ��ַ���,��ʵ�С�\0��
		{							//Ϊ�˽��"δ��ʼ������"��Ĭ�Ϲ��캯��������
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity+1];
			strcpy(_str, str);
		}
		//����
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
		//��������
		string(const string& s)
		{
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}
		//��������:��������,��ЧԪ�ظ���,֧���±����
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
		//������
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
		//��ɾ���
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size++] = ch;
			_str[_size] = '\0';
		}
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;
		}
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		void insert(size_t pos, size_t n, char ch)
		{
			assert(pos <= _size);
			if (_size + n > _capacity)
			{
				reserve(_size + n);
			}
			int end = (int)_size;
			//���posΪsize_t��end�Ƚ���������������,end����ʱΪ-1
			//while (end >= (int)pos)
			while(end >= pos && end != npos)
			{
				_str[end + n] = _str[end];
				--end;
			}
			for (size_t i = 0; i < n; ++i)
			{
				_str[pos + i] = ch;
			}
			_size += n;
		}
		void insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			int end = (int)_size;
			while (end >= pos && end != npos)
			{
				_str[end + len] = _str[end];
				--end;
			}
			for (size_t i = 0; i < len; ++i)
			{
				_str[pos + i] = str[i];
			}
			_size += len;
		}
		void erase(size_t pos, size_t len = npos)
		{
			assert(pos <= _size);
			if (len == npos || pos + len > _size) //��Ϊpos��������ȫ��ɾ��
			{
				//_str[pos] = '\0';
				_size = pos;
				_str[_size] = '\0';
			}
			else
			{
				size_t end = pos + len;
				while (end <= _size) //�Ⱥ���ͬ'\0'Ҳ�����ƹ���
				{
					_str[pos++] = _str[end++];
				}
				_size -= len;
			}
		}
		size_t find(const char* str, size_t pos = 0)
		{
			assert(pos < _size);
			const char* ptr = strstr(_str, str);
			if (ptr)
				return ptr - _str;
			else
				return npos;
		}
		size_t find(char ch, size_t pos = 0)
		{
			assert(pos < _size);
			for (size_t i = pos; i < _size; ++i)
			{
				if (_str[i] == ch)
					return i;
			}
			return npos;
		}
		string substr(size_t pos = 0, size_t len = npos)
		{
			assert(pos < _size);
			size_t n = len;
			if (len == npos || pos + len > _size)
			{
				n = _size - pos;
			}
			string tmp;
			for (size_t i = pos; i < pos + n; ++i)
			{
				tmp += _str[i];
			}
			return tmp;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	public:
		//static const size_t npos = -1;
		static const size_t npos;
	};
	const size_t string::npos = -1;
}


