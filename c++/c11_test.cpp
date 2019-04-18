#include <iostream>
#include <memory>
#include <unordered_map>

using namespace std;

void c11_test()
{
    // auto 类型指示符
    auto i = 1;
    cout << "auto i:" << i << endl;

    // decltype 类型指示符
    const int j = 0;
    decltype(j) k = 1;

    // 范围 for 语句
    string str = "hello world.";
    for(auto i: str)
        cout << "i" << endl;

    // 智能指针
    // 共享指针
    shared_ptr<int> p = make_shared<int>(5);
    // 独享指针 不支持普通拷贝和赋值操作
    unique_ptr<int> up = make_unique<int>(6);
    // 弱共享指针
    weak_ptr<int> wp(p);

    // 无序容器，允许有重复关键字版本
    unordered_map<int, int> map_test;
}

int main()
{
    c11_test();
    return 0;
}