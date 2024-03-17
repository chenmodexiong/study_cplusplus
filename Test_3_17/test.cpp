#include <iostream>
#include <string>
#include <windows.h>

//#define __TEST_CODE1__
#ifdef __TEST_CODE1__
double Division(const double& d1, const double& d2)
{
	if (d2 == 0) {
		std::string s("Division by zero condtion");
		throw s;
	}
	else
		return d1 / d2;
}
void func()
{
	int len, time;
	std::cout << "Please Enter a & b:" << std::endl;
	std::cin >> len >> time;
	std::cout << Division(len, time) << std::endl;
}
int main()
{
	try {
		func();
	}
	catch (const std::string& errmsg) {
		std::cout << errmsg << std::endl;
	}
	catch (...) { //�������������쳣
		//��Ҫ���ڲ��淶�쳣����ֹ������ֹ
		std::cout << "δ֪�쳣" << std::endl;
	}
	std::cout << "you can see me!!!" << std::endl;
	return 0;
}
#endif

#define __TEST_CODE__ 1
#ifdef __TEST_CODE__
// ������������ͨ��ʹ�õ��쳣�̳���ϵ
class Exception
{
public:
	Exception(const std::string& errmsg, int id)
		:_errmsg(errmsg)
		, _id(id)
	{}
	virtual std::string what() const
	{
		return _errmsg;
	}
protected:
	std::string _errmsg;
	int _id;
};

class SqlException : public Exception
{
public:
	SqlException(const std::string& errmsg, int id, const std::string& sql)
		:Exception(errmsg, id)
		, _sql(sql)
	{}
	virtual std::string what() const
	{
		std::string str = "SqlException:";
		str += _errmsg;
		str += "->";
		str += _sql;
		return str;
	}
private:
	const std::string _sql;
};
class CacheException : public Exception
{
public:
	CacheException(const std::string& errmsg, int id)
		:Exception(errmsg, id)
	{}
	virtual std::string what() const
	{
		std::string str = "CacheException:";
		str += _errmsg;
		return str;
	}
};
class HttpServerException : public Exception
{
public:
	HttpServerException(const std::string& errmsg, int id, const std::string& type)
		:Exception(errmsg, id)
		, _type(type)
	{}
	virtual std::string what() const
	{
		std::string str = "HttpServerException:";
		str += _type;
		str += ":";
		str += _errmsg; return str;
	}
private:
	const std::string _type;
};
void SQLMgr()
{
	srand(time(0));
	if (rand() % 7 == 0)
	{
		throw SqlException("Ȩ�޲���", 100, "select * from name = '����'");
	}
	//throw "xxxxxx";
}
void CacheMgr()
{
	srand(time(0));
	if (rand() % 5 == 0)
	{
		throw CacheException("Ȩ�޲���", 100);
	}
	else if (rand() % 6 == 0)
	{
		throw CacheException("���ݲ�����", 101);
	}
	SQLMgr();
}
void HttpServer()
{
	// ...
	srand(time(0));
	if (rand() % 3 == 0)
	{
		throw HttpServerException("������Դ������", 100, "get");
	}
	else if (rand() % 4 == 0)
	{
		throw HttpServerException("Ȩ�޲���", 101, "post");
	}
	CacheMgr();
}
int main()
{
	while (1)
	{
		Sleep(1000);
		try {
			HttpServer();
		}
		catch (const Exception& e) // ���ﲶ�������Ϳ���
		{
			// ��̬
			std::cout << e.what() << std::endl;
		}
		catch (...)
		{
			std::cout << "Unkown Exception" << std::endl;
		}
	}
	return 0;
}
#endif