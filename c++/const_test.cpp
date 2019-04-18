/*
具体参考：https://www.cnblogs.com/azbane/p/7266747.html
说明
1. 定义 const 对象：把对象转换为常量，在定义时必须初始化
2. const 对象默认为文件的局部变量。文件中全局非 const 变量默认为 extern, 其他文件可以使用。
3. const 修饰类成员函数，表示该函数不可修改类的成员变量。 int a() const;
*/
#include <iostream>

using namespace std;

// 非 const 变量，其他文件使用 extern 可以访问
// file1.cpp 
// extern int extern_mem;
int extern_mem = 1;

// const 变量，其他文件不可访问
const int const_mem_only_access_in_this_file = 1;

// extern 修身 const 变量，其他文件可以访问
extern const int extern_const_mem = 1;

class test
{
public:
    // const 成员函数
    void print(int b) const
    {
        b = 3;

        // 函数用 const 修饰后，不可改变类成员变量
        //a = 3;
        cout << "a:" << a << endl;
    }

    // const 返回值成员函数
    const string print()
    {
        return "hello";
    }

private:
    int a;
};

int main()
{
    test t;
    t.print(3);
}