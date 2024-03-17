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
	catch (...) { //捕获任意类型异常
		//主要用于不规范异常，防止程序终止
		std::cout << "未知异常" << std::endl;
	}
	std::cout << "you can see me!!!" << std::endl;
	return 0;
}
#endif

#define __TEST_CODE__ 1
#ifdef __TEST_CODE__
// 服务器开发中通常使用的异常继承体系
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
		throw SqlException("权限不足", 100, "select * from name = '张三'");
	}
	//throw "xxxxxx";
}
void CacheMgr()
{
	srand(time(0));
	if (rand() % 5 == 0)
	{
		throw CacheException("权限不足", 100);
	}
	else if (rand() % 6 == 0)
	{
		throw CacheException("数据不存在", 101);
	}
	SQLMgr();
}
void HttpServer()
{
	// ...
	srand(time(0));
	if (rand() % 3 == 0)
	{
		throw HttpServerException("请求资源不存在", 100, "get");
	}
	else if (rand() % 4 == 0)
	{
		throw HttpServerException("权限不足", 101, "post");
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
		catch (const Exception& e) // 这里捕获父类对象就可以
		{
			// 多态
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