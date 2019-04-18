#include <iostream>

using namespace std;
// 手写字符串转整型
int StrToInt(const char* str)
{
    // 获取最大值与最小值
    static const int MAX_INT = (int)((unsigned)~0 >> 1);
    static const int MIN_INT = -(int)((unsigned)~0 >> 1) - 1;
    unsigned int n = 0;

    // 判断输入是否为空
    if(str == 0)
        return 0;

    // 处理空格
    while(isspace(*str))
        ++str;

    // 处理正负
    int sign = 1;
    if(*str == '+' || *str == '-')
    {
        if(*str == '-')
            sign = -1;
        ++str;
    }

    // 确定是数字后开始执行循环
    while(isdigit(*str))
    {
        // 处理溢出
        int c = *str - '0';
        if(sign > 0 && (n > MAX_INT / 10 || (n == MAX_INT / 10 && c > MAX_INT % 10)))
        {
            n = MAX_INT;
            break;
        }
        else if(sign < 0 && (n > (unsigned)MIN_INT / 10 || (n == (unsigned)MIN_INT / 10 && c > (unsigned)MIN_INT % 10)))
        {
            cout << "n:" << n << endl;
            cout << "min int:" << MIN_INT << endl;
            n = MIN_INT;
            cout << "get n:" << n << endl;
            cout << "min int:" << MIN_INT << endl;
            break;
        }

        // 把之前得到的数字乘以10，再加上当前字符表示的数字
        n = n * 10 + c;
        ++str;
    }
    return sign > 0 ? n : -n;
}

int main()
{
    cout << "-123456789101:" << StrToInt("-123456789101") << endl;
    //cout << "+123:" << StrToInt("+123") << endl;
    //cout << "-123:" << StrToInt("-123") << endl;
    return 0;
}