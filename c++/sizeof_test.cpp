#include <iostream>

// linux 编译器默认的对齐规则，32 位系统4， 64位系统为8
// 手动设置编译器对齐字节数
//#pragma pack(4)

using namespace std;

/*
sizeof说明：
sizeof计算数据所占内存空间，用字节数表示。
数据类型举例：
1. 变量：int，char，cstring, string, point
2. 数组：
3. 类型：
4. 结构体
5. 类：

    先来看四个重要的基本概念：
     1) 数据类型自身的对齐值：char型数据自身对齐值为1字节，short型数据为2字节，int/float型为4字节，double型为8字节。
     2) 结构体或类的自身对齐值：其成员中自身对齐值最大的那个值。
     3) 指定对齐值：#pragma pack (value)时的指定对齐值value。
     4) 数据成员、结构体和类的有效对齐值：自身对齐值和指定对齐值中较小者，即有效对齐值=min{自身对齐值，当前指定的pack值}。

     基于上面这些值，就可以方便地讨论具体数据结构的成员和其自身的对齐方式。
     其中，有效对齐值N是最终用来决定数据存放地址方式的值。有效对齐N表示“对齐在N上”，即该数据的“存放起始地址%N=0”。
     而数据结构中的数据变量都是按定义的先后顺序存放。第一个数据变量的起始地址就是数据结构的起始地址。
     结构体的成员变量要对齐存放，结构体本身也要根据自身的有效对齐值圆整(即结构体成员变量占用总长度为结构体有效对齐值的整数倍)。
    
    结构体字节对齐的细节和具体编译器实现相关，但一般而言满足三个准则：
     1) 结构体变量的首地址能够被其最宽基本类型成员的大小所整除；
     2) 结构体每个成员相对结构体首地址的偏移量(offset)都是成员大小的整数倍，如有需要编译器会在成员之间加上填充字节(internal adding)；
     3) 结构体的总大小为结构体最宽基本类型成员大小的整数倍，如有需要编译器会在最末一个成员之后加上填充字节{trailing padding}。

     对于以上规则的说明如下：
     第一条：编译器在给结构体开辟空间时，首先找到结构体中最宽的基本数据类型，然后寻找内存地址能被该基本数据类型所整除的位置，作为结构体的首地址。将这个最宽的基本数据类型的大小作为上面介绍的对齐模数。
     第二条：为结构体的一个成员开辟空间之前，编译器首先检查预开辟空间的首地址相对于结构体首地址的偏移是否是本成员大小的整数倍，若是，则存放本成员，反之，则在本成员和上一个成员之间填充一定的字节，以达到整数倍的要求，也就是将预开辟空间的首地址后移几个字节。
     第三条：结构体总大小是包括填充字节，最后一个成员满足上面两条以外，还必须满足第三条，否则就必须在最后填充几个字节以达到本条要求。

    个人总结：
    对齐原则
    1. 成员对齐：offset%N=0 
        offset:成员相对结构体起点偏移量，
        N: 数据成员、结构体和类的有效对齐值：自身对齐值和指定对齐值中较小者，即有效对齐值=min{自身对齐值，当前指定的pack值}。
    2. 结构体对齐
        结构体起点：结构体变量的首地址能够被其最宽基本类型成员的大小所整除
        结构体终点：结构体的总大小为结构体最宽基本类型成员大小的整数倍

    总结注意点：
    1. 结构体中有结构体成员变量时，计算大小时，本身结构体内部已经对齐。但结构体成员的对齐起点，要按照结构体成员内最宽变量的占位来进行计算
    2. 网络程序中，需要进行设置 #pragma pack(1)
*/

#define OFFSET(st, field)     (size_t)&(((st*)0)->field)

void sizeof_test()
{
    char a;
    cout << "char size:" << sizeof(a) << endl; // 1
    int *p;
    cout << "point size:" << sizeof(p) << endl;  // 32 位机器4，64位机器8

    // string
    string s = "123456";
    cout << "string s=123456" << endl;
    cout << "string sizeof(s):" << sizeof(s) << endl; // string 类的大小 24
    // string 类的大小
    cout << "sizeof(string):" << sizeof(string) << endl;
    // string 字符串的长度
    cout << "string char size sizeof(s.c_str()):" << sizeof(s.c_str()) << endl;
    cout << "string strlen(s)" << strlen(s.c_str()) << endl;

}

void struct_test()
{
    struct s7
    {
        char a;   // 1 + 7
        double b; // 8
        int c;    // 4
        char d;   // 1 + 3
    };
    cout << "s7:" << sizeof(s7) << ", expect:24" << endl; // 24

    struct s8
    {
        char a;   // 1
        char b;   // 1 + 2
        int c;    // 4
        double d; // 8
    };
    cout << "s8:" << sizeof(s8) << ", expect:16" << endl; // 16

    struct s1
    {
        char a[8];
    };
    cout << "s1:" << sizeof(s1) << ", expect:8" <<endl; // 8

    struct s2
    {
        double d;
    };
    cout << "s2:"<<sizeof(s2) << ", expect:8" <<endl; // 8

    struct s3
    {
        s1 s;
        char a;
    };
    cout << "s3:" << sizeof(s3) << ", expect:9" <<endl; // 9
    struct s4
    {
        s2 s;
        char a; 
    };
    cout << "s4:" <<sizeof(s4) << ", expect:16" <<endl; // 16;

    struct s5
    {
        char a[3]; // 3 + 5
        double c;  // 8
        char b[2]; // 2 + 6
    };
    cout << "s5:" << sizeof(s5)  << ", expect:24" << endl; //24

    struct s6{
        int a;  // 4 
        char b; // 1 
        // 结构体内部本身已经对齐，但
        struct c1{ // + 3 
            char a[3]; // 3 + 5 
            double b; // 8
        } c;
        double d; // 8
    };
    cout << "s6:" << sizeof(s6)  << ", expect:32" << endl; // 32

    // ??? 
    struct s9{
        int a;
        struct b{
            double c;
        };
        //b c;
    };
    cout << "s9:" << sizeof(s9) << ", expect:1" << endl;

    /*
    联合
    当一个共用体被声明时, 编译程序自动地产生一个变量, 其长度为联合中最大的变量长度的整数倍（特别注意数组）
    */
    union uni{
        char a[3];
        double b;
    };
    cout << "union size:" << sizeof(uni) << ", expect:8"<< endl;

    union A  
    {
        int a[5];    //20
        short b;     //2
        double c;    //8 最宽成员为8 需要进行对齐
        char p2;     //1
    };
    cout << "union1 size:" << sizeof(A) << ", expect:24" << endl;
    
    struct B { 
        int n; // 4字节 + 4
        // 结构体内部本身已经对齐，但要主要结构体成员对齐的起始位置是否要补齐字节
        A a; // 24字节 联合 A 中最宽成员为8,前后需要按照8进行对齐。
        char c[10]; // 10字节 + 6 
    };
    cout << "b size:" << sizeof(B) << ", expect:48" << endl;

}

class Base
{
public:
    Base();                
    virtual ~Base();         //  8 每个实例都有虚函数表
    void set_num(int num)    //普通成员函数，为各实例公有，不归入sizeof统计
    {
        a=num;
    }
private:
    int  a;                  // 4 + 4
    char *p;                 // 8
};
class Derive:public Base
{
public:
    Derive():Base(){};     
    ~Derive(){};
private:
    // static 对象不允许被定义在局部作用域中
    static int b;               //非实例独占
    int  d;                     // 4 + 4
    char *p;                    // 8
};

/*
关于c++类 sizeof 说明
1.类的大小为类的非静态成员数据的类型大小之和，也就是说静态成员数据不作考虑。
2.普通成员函数与sizeof无关。
3.虚函数由于要维护在虚函数表，所以要占据一个指针大小：32位机器4个字节，64位机器8个字节。
4.类的总大小也遵守类似class字节对齐的，调整规则。
*/
void class_test()
{
    // 因为一个空类也要实例化，所谓类的实例化就是在内存中分配一块地址，每个实例在内存中都有独一无二的地址。
    // 同样空类也会被实例化，所以编译器会给空类隐含的添加一个字节，这样空类实例化之后就有了独一无二的地址了。所以空类的sizeof为1。
	class c{};
    cout << "c:" << sizeof(c) << ", expect:1"<< endl;

    class c1
    {
        char a;
        double b; 
	    //virtual void f();
    };
    cout << "c1:" << sizeof(c1) << ", expect:16"<<endl;

    class c2
    {
	    virtual void f(); // 虚函数指针 8
    };
    cout << "c2:" << sizeof(c2) << ", expect:8"<<endl;

    class base1
    {
        virtual void f1();
    };
    class base2
    {
        virtual void f2();
    };
    class base3
    {
        virtual void f3();
    };
    // 多重继承虚函数，有多个虚函数指针
    // 虚函数指针存放位置说明：？多重继承的问题暂未解决
    class c3:public base1, base2, base3
    {
        virtual void f1(); // 8
        char a;            // 1 + 7  
        virtual void f2(); // 8
        char b;            // 1 + 7
        virtual void f3(); // 8
    };
    cout << "c3:" << sizeof(c3) << ", expect:32"<<endl;

    // 类定义见函数上部
    cout <<"base:" <<sizeof(Base)<< ", expect:24" << endl;
	cout <<"device:" <<sizeof(Derive) << ", expect: 40"<< endl;

};

int main()
{
    sizeof_test();
    struct_test();
    class_test();
    return 0;
}