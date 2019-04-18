#include <iostream>

using namespace std;

/*
    分析 c++ 11 共享指针的实现方式
*/

class HasPtr
{
public:
    // 构造函数
    HasPtr(int *p, int i):ptr(new U_Ptr(p)), val(i){}
    // 复制构造函数
    HasPtr(const HasPtr &orig):ptr(orig.ptr), val(orig.val) { ++ptr->use; }
    // 重载赋值操作符
    HasPtr& operator=(const HasPtr& rhs)
    {
        ++rhs.ptr->use;
        if(--ptr->use == 0)
            delete ptr;
        ptr = rhs.ptr;
        val = rhs.val;
        return *this;
    }
    // 析构函数
    ~HasPtr() { if(--ptr->use == 0) delete ptr; }

    int* get_ptr() const { return ptr->ip; }
    int get_int() const { return val; }
    void set_ptr(int*p) { ptr->ip = p; }
    void set_int(int i) { val = i; }
    int get_ptr_val() const { return *ptr->ip; }
    void set_ptr_val(int val) const {*ptr->ip = val; }
private:
    U_Ptr *ptr;
    int val;
};

// 计数类
class U_Ptr
{
    friend class HasPtr;    
    U_Ptr(int *p):ip(p), use(1) {}
    ~U_Ptr(){ delete ip; } 
    int *ip;
    size_t use;
};

int main()
{
    int obj = 0;
    HasPtr ptr1(&obj, 42);
    HasPtr ptr2(ptr1);
    return 0;
}