/*
实现 c标准库的 string.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int	 memcmp(const void *__s1, const void *__s2, size_t __n);
void	*memcpy(void *__dst, const void *__src, size_t __n);
void	*memmove(void *__dst, const void *__src, size_t __len);

char	*strcat(char *__s1, const char *__s2);
int	 strcmp(const char *__s1, const char *__s2);
char	*strcpy(char *__dst, const char *__src);
char	*strncpy(char *__dst, const char *__src, size_t __n);
//size_t	 strlen(const char *__s);
char	*strncat(char *__s1, const char *__s2, size_t __n);
int	 strncmp(const char *__s1, const char *__s2, size_t __n);

// 掌握手写
char* _strcpy(char* dst, const char* src)
{
    assert(dst != NULL && src != NULL);
    char* p = dst;
    while(*p++ = *src++);
    return dst;
}

// 掌握手写
char* _strncpy(char* dst, const char* src, int n)
{
    assert(dst != NULL && src != NULL);

    char *p = dst;
    while(n-- && (*p++ = *src++));

    // 注意这里赋值的巧妙之处。且一定要注意收尾
    if(*p != '\0')
        *p = '\0';        

    return dst;
}

// 掌握手写
char* _strcat(char* dst, const char* src)
{
    assert(dst != NULL);
    char* p = dst;
    // 不能直接这样计算，判断 0 后会继续往下走一位，导致错误
    //while(*p++) ;
    while(*p) ++p;
    while(*p++ = *src++);
    return dst;
}

// 掌握手写
size_t _strlen(const char* src)
{
    assert(src != NULL);
    size_t i = 0;
    while(*src++) ++i;
    return i;
}

int main()
{
    //cout << "'\0':" << '\0' << endl;
    //cout << _strlen("123") << endl;
    char* dst = new char[100];
    dst[0] = '\0';
    char src[] = "01234567890123456789";
    //_strcat(dst, src);
    _strncpy(dst, src, 14);
    cout << "strcat len:" << _strlen(dst) << " result:" << dst << endl;
}


