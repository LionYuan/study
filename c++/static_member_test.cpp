#include <iostream>

using namespace std;

class CTest
{
public:
	CTest(){}
	~CTest(){}
	int PrintNum()
	{
		static int num = 0;
		cout << "num:" << num++ << endl;
		return 0;
	}
};

int main()
{
	//测试类成员函数中 static 变量的存活期: 程序的生命周期, 和类成员函数的运行周期, 类的存活周期没关系
	CTest test1, test2;
	test1.PrintNum();
	test1.PrintNum();
	test2.PrintNum();
	test2.PrintNum();

	return 0;
}