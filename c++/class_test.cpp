#include <iostream>
using namespace std;

class Foo
{
    char cc;
    float f;

public:
    void print() { std::cout << "ADDR: " << this << std::endl; }
    void set_f( float _f ) { std::cout << "set f val : " << _f << std::endl; f = _f; }
    void get_f() { std::cout << "get f val : " << f << std::endl; }
};

// placement new 用法
// 
void placement_new()
{
    // 1) 分配内存
    char* buff = new char[ sizeof(Foo) * 5 ];
    memset( buff, 0, sizeof(Foo)*5 );

    // 2）构建对象
    Foo* pfoo = new (buff)Foo;

    // 3）使用对象
    pfoo->print();

    pfoo->set_f(1.0f);
    pfoo->get_f();

    // 4）析构对象，显式的调用类的析构函数。
    pfoo->~Foo();

    //5）销毁内存
    delete [] buff;
}

class FriendClassTest
{
public:
    void print()
    {

    }
};

class ClassTest
{
// 默认是 private:
public:
    // 构造函数
    // 含有单个形参的构造函数应该定义为 explicit(显式的)，除非有明显的理由想要定义隐式转换。
    // 当用户想要转换时，可以显式构造对象
    explicit ClassTest(string &s):const_int(0), mystr(s){}
    ~ClassTest(){}    

    void print() const
    {
        mutable_int = 1;
        cout << mutable_int << endl;
    }

    void explicitFuncTest(ClassTest ct)
    {
        cout << "explicitFuncTest test." << endl;
    }

    // this 隐含指针测试
    ClassTest& this_test()
    {
        this->print();
        // 1. 返回的 this 指针是常量，不可修改指针地址，但可以修改类内容
        return *this;
    }
    const ClassTest& const_this_test() const
    {
        // 2. const 函数返回的 *this 只能作为一个const引用
        return *this;
    }

    // static 成员
    // static 数据成员(const) 需要在类定义体外进行定义,常量表达式除外。该成员不是类的组成部分
    const static int const_static_int = 3;
    const static string const_static_string;
    // static 成员函数只能调用 static 成员
    static void static_print()
    {
        cout << "const_static_int:" << const_static_int << endl;
    }

    // 友元：函数或者类可以访问非共有成员
    friend class FriendClassTest;
    friend void FriendClassTest::print();

private:
    // const, 引用类型成员，及没有默认构造函数的类类型，必须要在构造函数初始化列表进行初始化
    const int const_int; 
    string &mystr;

    // const 成员函数需要访问成员变量的话，需要 mutable 关键字修饰
    mutable int mutable_int;
};

// static 成员要在类定义体外进行定义，不能再含有 static
//const static int ClassTest::const_static_int = 2;
const int ClassTest::const_static_int = 2;

// 实现复制控制的三个函数：复制构造函数，赋值操作符，析构函数
class ClassTest1
{
public:
    ClassTest1(){}
    ~ClassTest1(){}

    // 复制构造函数 
    // 1. 定义方式：函数形参为类的 const 引用
    // 2. 当定义一个新对象并用同类型对象对它进行初始化时，显式调用复制构造函数，
    //    当该类型对象传递给函数或者从函数返回该类型的对象时，将隐式调用复制构造函数
    ClassTest1(const ClassTest1& t){}
    // 2. 声明私有复制构造函数，可以禁止任何复制：用户代码编译错误，成员函数和友元会链接错误
//private:
//    ClassTest1(const ClassTest1& t);

};

void class_test()
{
    // 用于const对象的构造函数，不用使用const修饰构造函数
    string s("hello");
    const ClassTest ct(s);
    
    ct.print();

    // explicit 显示构造函数用法
    ClassTest ct1(s);
    // 含有单个形参的构造函数应该定义为 explicit(显式的)，除非有明显的理由想要定义隐式转换。
    // 当用户想要转换时，可以显式构造对象
    // 隐式调用会直接报错
    //ct.explicitFuncTest(s);
    ct1.explicitFuncTest(ClassTest(s));
}

int main()
{
    //placement_new();
    class_test();
}