#include <iostream>
#include <stdio.h>
#include <stdarg.h>
using namespace std;

// 枚举用法
enum enum_test
{
    input, // 默认从0开始，后面比前面大1
    output,
    append
};

//const 定义
int b = 3;
const int a = 3; 

/* 
c++ 数组测试
总结：
对于字符数组：
1. 用字符初始化，必须在尾部加 '\0'.
2. 字符串常量初始化，尾部会自动追加 '\0'
3. strlen 计算 c字符串时，通过检测 '\0' 为字符串结尾
*/

void array_test()
{
    // 定义
    char ca1[] = {'1', '2', '3'};
    // strlen 计算，依赖于 null， len 未知，计算会出错
    cout << "ca1 len:" << strlen(ca1) << endl;
    // 字符数组初始化为3个。 len 3
    cout << "ca1 len:" << sizeof(ca1)/sizeof(ca1[0]) << endl;
    ca1[0] = '5';
    for(int i = 0; i < sizeof(ca1)/sizeof(ca1[0]); ++i)
        cout << i << ":" << ca1[i] << endl;
    
    char ca2[] = {'1', '2', '3', '\0'};
    // len 3
    cout << "ca2 len:" << strlen(ca2) << endl;
    // len 4
    cout << "ca2 len:" << sizeof(ca2)/sizeof(ca2[0]) << endl;

    // 字符串常量赋值会自动加 '\0'
    char ca3[] = "123";
    // len 3
    cout << "ca3 len:" << strlen(ca3) << endl;
    // len 4
    cout << "ca3 len:" << sizeof(ca3)/sizeof(ca3[0]) << endl;
}

/*
指针测试
*/
void point_test()
{
    int value = 1;
    const int *a;
    a = &value;
    int *b = &value;
}

/*
申请空间测试
*/
void new_test()
{
    // new 数组与释放数组空间
    char *p = new char[5];
    delete [] p;
}

/*
含有可变形参的函数
原理blog地址：https://www.cnblogs.com/clover-toeic/p/3736748.html
*/
void foo(int param_num, ...)
{
    //定义va_list类型的指针pArgs，用于存储参数地址
    va_list pArgs;  

    //初始化pArgs指针，使其指向第一个可变参数。该宏第二个参数是变参列表的前一个参数，即最后一个固定参数
    va_start(pArgs, param_num); 

    //若函数有多个可变参数，则依次调用va_arg宏获取各个变参
    for(int i = 0; i < param_num; ++i)
    {
        //该宏返回变参列表中的当前变参值并使pArgs指向列表中的下个变参。该宏第二个参数是要返回的当前变参类型
        int dwVarArg = va_arg(pArgs, int); 
        cout << i << ":" << dwVarArg << endl;
    }
    
    //将指针pArgs置为无效，结束变参的获取
    va_end(pArgs);  
}

/*
数组传参
1. 函数数组传参不能复制数组
2. 使用数组名会退化为指针
3. 编译器会忽略数组的长度
4. 通过引用传递数组不会退化为指针，编译器会检查数组大小
*/
void test1(char a[10])
{
    // 返回数组长度：实际是判断 null 前有几个字符
    cout << "array len:" << strlen(a) << endl;
    // 返回指针长度：64位机器，为8 
    cout << "array size:" << sizeof(a)/sizeof(char) << endl;
}
// 不要改变数组内容的话，要设置为 const
void test2(const char *a)
{

}
// 通过引用传递数组不会退化为指针，编译器会检查数组大小
void tese3(char (&a)[10])
{
}

/*
重载函数
*/
// 重载函数时，形参于 const 行参的等价性仅适用于非引用形参
// 正确的重载：指针与 const 指针不等价
void reload_test(char *p){}
void reload_test(const char *p){}
// 正确的重载：引用与 const 引用不等价
void reload_test(int &a){}
void reload_test(const int &a){}
// 错误的重载：参数与 const 参数等价
//void reload_test(int a){}
//void reload_test(const int a){}

/*
函数指针
注意：函数指针定义必须要用()括起来
*/
typedef int (*pfunc)(int);
int func(int a)
{
    cout << a << endl;
    return 0;
}
void pfunc_test()
{   
    // 一、函数指针的赋值：可以通过函数名，函数指针，及0进行赋值
    pfunc p = 0;        // 0:该指针不指向任何函数
    pfunc p1 = func;    // 赋值函数名和函数名取地址均可
    p1 = &func;

    // 二、函数指针调用: 函数名和函数指针是等价的
    p1(5);
    (*p1)(5);
}
// 三、函数指针作为函数返回值 必须以指针形式返回，不能以函数名返回
int (*ff(int))(int*, int);  // 阅读方式，从声明的名字开始由里及外。说明：ff为一个函数，带有一个 int 型形参，该函数返回值是一个函数指针。
// 将函数指针作为函数返回值的更好方式是用 typedef
typedef int (*PF)(int*, int);
PF ff(int);
// 四、函数指针作为函数形参: 传递函数等价于传递函数指针
void ff(int, bool (int));
void ff(int , bool (*)(int));

/*
main 函数，argc 参数个数， argv 参数列表。首个参数是程序名称
*/
int main(int argc, char **argv)
{
    //array_test();
    //point_test();
    //cout << "input:" << enum_test::input << endl;

    //new_test();

    //foo(3, 1, 2, 3);

    //test1("1234");

    pfunc_test();
}