// c, c++ 字符串操作
#include <iostream>
using namespace std;

// sizeof/ strlen 用法
// sizeof 操作符
//  sizeof(...)是运算符，在头文件中typedef为unsigned int，其值在编译时即计算好了，参数可以是数组、指针、类型、对象、函数等。
//    它的功能是：获得保证能容纳实现所建立的最大对象的字节大小。
void len_test()
{   
    // sizeof:6 strlen:5
    char c_str[] = {"hello"};
    cout << "c sizeof:" << sizeof(c_str) << ", strlen:" << strlen(c_str) << endl;

    // sizeof:10 strlen:5
    char c_str1[10] = {"hello"};
    cout << "c sizeof:" << sizeof(c_str1) << ", strlen:" << strlen(c_str1) << endl;

    // 32bite 4, 64bite 8
    char *p;
    cout << "p sizeof:" << sizeof(p) << endl;

}

// c字符串定义方式
// 字符串定义方法
// 有两种方法:
// 1) 用字符数组；
// 2) 用字符指针；
void def_str()
{
    // 这种方法定义时，系统会自动在字符串的末尾加上字符串结束符，即 ‘\0’,
    char str[]="12345";
    char str1[]={"12345"};
    
    //这种方法定义时，系统会自动从未初始化的元素开始，将之后的元素赋为\0，如上面的数组str中的元素实际上是：'1','2','3','4','5','\0','\0','\0','\0','\0'
    char str2[10]={'1','2','3','4','5'};

    // 这种方法定义时，系统不会自动在字符串的末尾加上字符串结束符;
    // 此时用sizeof()函数可以正确求出其所占的内存大小；但用strlen()函数不能正确求出其长度，因为strlen是通过\0判断字符串结束的。
    // 所以，采用该方法定义时，一般人为地加上\0,即charstr[]={'1','2','3','4','5', '\0'};
    char str3[]={'1','2','3','4','5'};
    cout << "str3 strlen:" << strlen(str3) << ", sizeof:" << sizeof(str3) << endl; 
    char str4[]={'1','2','3','4','5', '\0'}; 
    cout << "str4 strlen:" << strlen(str4) << ", sizeof:" << sizeof(str4) << endl; 
    
}

int main()
{
    //len_test();
    def_str();
}