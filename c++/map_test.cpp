#include <map>
#include <iostream>

using namespace std;

int main()
{
	// map 访问不存储元素的行为定义
	map<string, int> test;
	// 打印结果为 0
	cout << test["1"] << endl;
	return 0;
}
