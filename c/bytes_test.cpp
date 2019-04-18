/*
位操作符
& 按位与 如果两个相应的二进制位都为1，则该位的结果值为1，否则为0
| 按位或 两个相应的二进制位中只要有一个为1，该位的结果值为1
^ 按位异或 若参加运算的两个二进制位值相同则为0，否则为1
~ 取反 ~是一元运算符，用来对一个二进制数按位取反，即将0变1，将1变0
<< 左移 用来将一个数的各二进制位全部左移N位，右补0
>> 右移 将一个数的各二进制位右移N位，移到右端的低位被舍弃，对于无符号数，高位补0
*/

#include <iostream>
using namespace std;

// 获得int最大值
int getMaxInt(){
	return ~(1 << 31);//2147483647
}

// 获取int最小值

// 获得long的最大值

// 

void test()
{
    // get max int
    cout << "max int:" << ~(1 << 31) << endl;
    cout << "test:" << ((unsigned)~0 >> 1) << endl;

    cout << "1*2=" << (1<<1) << endl;
    cout << "1/2=" << (1/2) << endl;
    cout << "1的奇偶性：" << (1&1 == 1) << endl;
}

void test1()
{
    // 班级中有30个学生，用一个二进制位代表一个学生在一次测验中是否通过
    unsigned long quitz = 0;
    // 考生27通过测验
    quitz |= 1ul << 27;
    bool status = quitz & (1ul << 27);
    cout << "status:" << status << endl;
    // 取消考生27的通过
    quitz &= ~(1ul << 27);
    // 检查考生27是否通过了考试
    status = quitz & (1ul << 27);
    cout << "status:" << status << endl;
}

int main()
{
    test();
    test1();
    return 0;
}