#include <iostream>

using namespace std;

/*
	快速写出来一个String类的完整实现
*/
class String
{
public:
	//构造函数
	String(const char *str = NULL);

	//拷贝构造函数
	String(String &other);

	//析构函数
	~String();

	//赋值函数
	String& operator = (const String &rhs);

private:
	char *m_data;
};

// 构造函数
String::String(const char *str)
{
	//默认初始化，加上字符串结束符
	if (str == NULL)
	{
		m_data = new char[1];
		m_data[0] = '\0';
	}
	else
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
}

// 拷贝构造函数
String::String(String &other)
{
	//外部传进来的类对象，已完成初始化工作
	m_data = new char[strlen(other.m_data) + 1];
	strcpy(m_data, other.m_data);

}

// 赋值操作符
String& String::operator=(const String &rhs)
{
	if (this == &rhs)
	{
		return *this;
	}

	char *tmp = new char[strlen(rhs.m_data) + 1];
	strcpy(tmp, rhs.m_data);

	delete [] m_data;

	m_data = tmp;

	return *this;
}

String::~String()
{
	delete [] m_data;
}


