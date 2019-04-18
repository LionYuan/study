#include <stdio.h>
#include <stdlib.h>

bool IsLittleEndian()
{
    // 利用特定值，取低位的值可以判断出来
    int x = 0x1;
    return *(char *) &x != 0;
}

int GetLongBit()
{
    // 通过判断指针的大小来判断
    return sizeof(void *) * 8;
}

int main()
{
    printf("IsLittleEndian:%d\n", IsLittleEndian());

    return 0;
}
