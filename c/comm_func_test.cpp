#include <stdio.h>
#include <iostream>

using namespace std;

/*
    如何在 main 函数之前和之后执行函数
    1. main 函数之前
        在gcc中，可以使用attribute关键字，声明constructor和destructor
        全局对象的构造函数会在main 函数之前执行
    2 main 函数之后
        用atexit注册的函数也会在main之后执行。
        全局对象的析构函数会在main函数之后执行；
        注意： atexit 先执行，后执行析构函数。atexit 函数执行顺序和调用顺序相反
          
*/

// 定义全局对象的构造函数和析构函数
class CBeforeMain
{
public:
    CBeforeMain()
    {
        cout << "全局对象的构造函数会在main 函数之前执行" << endl;
    }
    ~CBeforeMain()
    {
        cout << "全局对象的析构函数会在main函数之后执行" << endl;
    }    
};
CBeforeMain b;

/*
GNU C的一大特色就是__attribute__机制
__attribute__关键字主要是用来在函数或数据声明中设置其属性。给函数赋给属性的主要目的在于让编译器进行优化。

5 constructor/destructor属性
说明:主要用于对函数的初始化等，如果声明了constructor属性，则会在main函数之前执行，如果声明了destructor属性则会在main函数执行之后，或者exit被调用后自动执行。 
*/

__attribute((constructor)) void before_main()
{
    printf("%s/n",__FUNCTION__);
    cout << "befor main func run." << endl;
}
__attribute((destructor)) void after_main()
{
    printf("%s/n",__FUNCTION__);
    cout << "after main func run." << endl;
}

void at_exit_func1()
{
    cout << "at exit func1" << endl;
}

void at_exit_func2()
{
    cout << "at exit func2" << endl;
}

int main( int argc, char ** argv )
{
    atexit(at_exit_func1);
    atexit(at_exit_func2);

    printf("%s/n",__FUNCTION__);
    return 0;
}
