#include <iostream>

// 适配器头文件
#include <queue>
#include <stack>

// 顺序容器头文件
#include <vector>
#include <list>
#include <deque>

// 关联容器头文件
#include <map>
#include <set>

using namespace std;

/*
顺序容器包括： vector, list, deque(double-end-queue)

顺序容器的适配器包括：stack, queue, priority_que 包括容器适配器，迭代器适配器，函数适配器

// stack, queue 默认基于 deque 容器实现，priority_que 基于 vector 实现
// stack 可以建立在 vector, list, deque 上
// queue 只能建立在 list, deque 上，不能建立在 vector 上。因为其要求提供 push_front 函数。
// priority_que 可建立在 vector/ deque 上，不能建立在 list 上。因为其要求提供随机访问功能

*/

// vector 容器
void vector_test()
{
    vector<int> vec;

    // 添加元素

    // 迭代器操作

    // 关系操作符

    // 大小操作
    // stl 的最大尺寸
    cout << "max_size():" << vec.max_size() << endl;
    vec.size();
    vec.empty();
    // 调整容器的大小，使其能容下n个元素
    vec.resize(5);
    vec.resize(5, 1);

}

// list 容器
void list_test()
{

}

// deque double-end-queue
void deque_test()
{

}

void string_test()
{
    string s("hello world.");
    
}

// stack 适配器
void stack_test()
{
    // stack, queue 默认基于 deque 容器实现，priority_que 基于 vector 实现
    // stack 可以建立在 vector, list, deque 上
    stack<int> stk;
    stack<int, vector<int> > stk_vector;
    stack<int, list<int> > stk_list;
    stack<int,deque<int> > stk_deque;

    // 栈的所有操作
    stk.empty();
    stk.size();
    stk.push(1);
    cout << "stack top:" << stk.top() << endl;;
    stk.pop();
    cout << "stack size:" << stk.size() << endl;
}

// queue 适配器
void queue_test()
{
    // queue 只能建立在 list, deque 上，不能建立在 vector 上。因为其要求提供 push_front 函数。
    queue<int> que;
    queue<int, list<int> > que_list;
    queue<int, deque<int> > que_deque;

    // 用 vector 适配不会报错，但调用 pop 函数时会，编译会报错提示函数不存在：error: no member named 'pop_front' in 'std::__1::vector<int,std::__1::allocator<int> >'
    queue<int, vector<int> > que_vector;
    que_vector.push(1);
    cout << "front:" << que_vector.front() << endl;
    //que_vector.pop();
    cout << "que size:" << que_vector.size() << endl;

    // 操作
    que.empty();
    que.size();
    //que.push(1);
    que.front();    // queue 特有操作
    que.back();     // queue 特有操作、
    //cout << "front:" << que.front() << ", back:" << que.back() << endl;
    //que.pop();      // pop 空队列会报错
    cout << "queue size:" << que.size() << endl;
}

// priority_que 适配器
void priority_que_test()
{
    // 仿函数
    struct cmp
    {
        bool operator()(int a, int b)
        {
            return a < b ? false : true; 
        }
    };
    // 默认大顶堆输出
    priority_queue<int, vector<int>, cmp> pri_que;
    // 可以在容器设置比较函数，自定义优先级属性
    priority_queue<int, vector<int>, cmp> pri_que_test;

    pri_que.empty();
    pri_que.size();
    pri_que.push(1);
    pri_que.push(5);
    pri_que.push(3);

    while(!pri_que.empty())
    {
        cout << pri_que.top() << endl;
        pri_que.pop();
    }

}

/*
关联容器：通过键来高效查找读取元素。 map, set, multimap, multiset

*/

void pair_test()
{
    // 创建，初始化
    pair<int, string> p1;
    pair<int, string> p2(1, "hello world.");
    pair<int, string> p3 = make_pair(1, "hello world.");

    // 操作
    p1.first;
    p1.second;
}

void map_test()
{
    map<int, int> t;
    t.insert(make_pair(1,1));
    cout << "t.szie:" << t.size() << endl;
    // 用下标访问不存在的元素时，会自动用该键添加元素
    cout << "t[2]:" << t[2] << ", t.size:" 
        << t.size() 
        << ", t[2]:" << t[2]
        << endl;
}

void multimap_test()
{
    multimap<int, int> mm;
    mm.insert(make_pair(1,2));
    mm.insert(make_pair(1,3));
    cout << "key 1 count:" << mm.count(1) << endl; // 2

    // 遍历 multimap 的方式
    typedef multimap<int, int>::size_type sz_type;
    sz_type count = mm.count(1);
    multimap<int, int>::iterator it;
    it = mm.find(1);
    for(sz_type i = 0; i < count; ++it, ++i)
        cout << "key:" << it->first << ", value:" << it->second << endl;
}

int main()
{
    //stack_test();
    //queue_test();
    priority_que_test();
    //vector_test();
    //map_test();
    //multimap_test();
}