#include <iostream>

using namespace std;

// cstring 函数实现
char* _strcpy(char* s1, char* s2)
{
    assert(s1 != NULL && s2 != NULL);
    char* ret = s1;
    while(*s1++ = *s2++);
    return ret;
}

char* _strncpy(char* s1, char* s2, int n)
{
    assert(s1 != NULL && s2 != NULL);
    char *ret = s1;
    while(n-- && (*s1++ = *s2++));

    while(n-- > 0)
        *s1++ = '\0';

    return ret;
}

size_t _strlen(char* s1)
{
    size_t i = 0;
    while(*s1++ != NULL)
        i++;
    return i;
}

void func_test()
{
    char *p = new char[10];
    cout << "p len:" << strlen(p) << endl;
    char *p1 = "abcde";
    //_strcpy(p, p1);
    _strncpy(p, p1, 10);
    cout << "p len:" << strlen(p) << endl;

    cout << "p1 len:" << _strlen(p1) << endl;
}

void cstring_func_test()
{
    char *p = new char[10];
    char *p1 = "abcde";
    char *p2 = "abcdef";

    // 标准库函数 strlen, strcmp, strcat, strcpy, strncat, strncpy
    
    // strlen
    // 5
    cout << "p len:" << strlen(p1) << endl;

    // strcmp(s1, s2) 
    // if s1 == s2, return 0
    int n = strcmp(p1, p2);
    // result <
    if (n == 0)
        cout << "p1 == p2" << endl;
    else if (n > 0)
        cout << "p1 > p2" << endl;
    else 
        cout << "p1 < p2" << endl;

    // strcat(s1, s2) s2 -> s1, return s1
    char *p3 = strcat(p, p1);
    cout << "strcat result:" << *p3 << endl;

    // strcpy(s1, s2) s2 -> s1, return s1
    p3 = strcpy(p, p1);
    cout << "p len:" << strlen(p) << endl;

    // strncat(s1, s2) s2 -> s1 n, return s1
    p3 = strncat(p, p1, 1);
    cout << "p len:" << strlen(p3) <<  endl;

}

int main()
{
    //cstring_func_test();
    func_test();
    return 0;
}