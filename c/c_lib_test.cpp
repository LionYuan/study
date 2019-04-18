/*
c 标准库
*/
#include <stdlib.h>
#include <iostream>
// unistd.h是unix std的意思，是POSIX标准定义的unix类系统定义符号常量的头文件，
// 包含了许多UNIX系统服务的函数原型，例如read函数、write函数和getpid函数
#include <unistd.h>

using namespace std;

// assert.h
#include <assert.h>
void assert_test()
{
    // void assert(int expression);
    // 这实际上是一个宏，不是一个函数，可用于在 C 程序中添加诊断
    // expression -- 这可以是一个变量或任何 C 表达式。如果 expression 为 TRUE，assert() 不执行任何动作。
    // 如果 expression 为 FALSE，assert() 会在标准错误 stderr 上显示错误消息，并中止程序执行。
    char *p = NULL;
    assert(p == NULL);
    printf("hello world.\n");
}

// ctype.h
// 用于测试和映射字符
// 这些函数接受 int 作为参数，它的值必须是 EOF 或表示为一个无符号字符。
// 如果参数 c 满足描述的条件，则这些函数返回非零（true）。如果参数 c 不满足描述的条件，则这些函数返回零。
#include <ctype.h>
void ctype_test()
{
    cout << "isalnum(5):" << isalnum(5) << endl;

    cout << "tolower(A):"<< tolower('A') << endl;
    cout << "toupper(a):"<< toupper('a') << endl;
}

// math.h 
// 头文件定义了各种数学函数和一个宏。在这个库中所有可用的功能都带有一个 double 类型的参数，且都返回 double 类型的结果。
#include <math.h>
void math_test()
{
}

// signal.h 
// 头文件定义了一个变量类型 sig_atomic_t、两个函数调用和一些宏来处理程序执行期间报告的不同信号。
#include <signal.h>
void sighandler(int signum)
{
    printf("捕获信号 %d，跳出...\n", signum);
    if (signum == SIGINT)
    {
        cout << "用户终端行为" << endl;
    }
    exit(1);
}
void signal_test()
{
    // 1. 设置一个函数来处理信号，即带有 sig 参数的信号处理程序
    // void (*signal(int sig, void (*func)(int)))(int)
    signal(SIGINT, sighandler);

    while(1) 
    {
        printf("开始休眠一秒钟...\n");
        sleep(1);
    }

    // 2. int raise(int sig) 
    // 会促使生成信号 sig。sig 参数与 SIG 宏兼容。

    // 3. 常见信号举例
    // 	SIGABRT 程序异常终止。
    //  SIGINT 中断信号，如 ctrl-C
    // 	SIGTERM  发送给本程序的终止请求信号。
}

// stdarg.h 
// 头文件定义了一个变量类型 va_list 和三个宏，这三个宏可用于在参数个数未知（即参数个数可变）时获取函数中的参数。
// 可变参数的函数通在参数列表的末尾是使用省略号(,...)定义的。
void stdarg_test(char *sInfo, ...)
{
    char *str   = NULL;
    char *str1 = NULL;
    char *str2 = NULL;
    va_list sArgv;          // 申请参数列表变量
    // 开始
    va_start(sArgv, sInfo); // 申明最后一个传递给函数的已知的固定参数
    /* 依次读取固定参数 sInfo 后的 参数 */
    str   = va_arg(sArgv, char*);
    str1 = va_arg(sArgv, char*);
    str2 = va_arg(sArgv, char*);
    // 结束
    va_end(sArgv);
    printf("运行输出：[%s,%s%s%s]\n",sInfo,str,str1,str2);
}

// stddef .h 
// 头文件定义了各种变量类型和宏。这些定义中的大部分也出现在其它头文件中。
#include <stddef.h>
void stddef_test()
{
    // 库变量
    ptrdiff_t p = 0; // 这是有符号整数类型，它是两个指针相减的结果。
    size_t i = sizeof(int); //这是无符号整数类型，它是 sizeof 关键字的结果。
    wchar_t wc;  // 这是一个宽字符常量大小的整数类型。
    // 库宏
    // 	NULL 这个宏是一个空指针常量的值。
}

// stdio .h 
// 头文件定义了三个变量类型、一些宏和各种函数来执行输入和输出。
#include <stdio.h>
void stdio_test()
{
    // 库变量
    // size_t 这是无符号整数类型，它是 sizeof 关键字的结果。
    // FILE 这是一个适合存储文件流信息的对象类型。
    // fpos_t 这是一个适合存储文件中任何位置的对象类型。

    // 库宏
    // 	EOF 这个宏是一个表示已经到达文件结束的负整数。
    // FOPEN_MAX 这个宏是一个整数，该整数代表了系统可以同时打开的文件数量。
    cout << "FOPEN_MAX:" << FOPEN_MAX << endl; // 20
    cout << "FILENAME_MAX:" << FILENAME_MAX << endl; // 1024
    // SEEK_CUR、SEEK_END 和 SEEK_SET  这些宏是在 fseek 函数中使用，用于在一个文件中定位不同的位置。

    // 库函数
}
void file_test()
{
    // 定义文件描述符
    FILE *fp;

    char c[] = "This is runoob";
    char buffer[20];
    
    // 打开文件
    fp = fopen("file.txt", "w+");
    /* 写入数据到文件 */
    fwrite(c, strlen(c) + 1, 1, fp);
    
    // 设置流 stream 的文件位置为给定的偏移 offset，参数 offset 意味着从给定的 whence 位置查找的字节数。
    fseek(fp, 0, SEEK_SET);
 
    /* 读取并显示数据 */
    fread(buffer, strlen(c)+1, 1, fp);

    // 写入文件
    //fprintf(fp, "%s", "这里是 runoob.com");

    // 获取文件大小
    // long int ftell(FILE *stream) 返回给定流 stream 的当前文件位置。
    fseek(fp, 0, SEEK_END);
    int len = ftell(fp);
    printf("file.txt 的总大小 = %d 字节\n", len);
    
    // 关闭文件
    fclose(fp);
}

// stdlib.h 头文件定义了四个变量类型、一些宏和各种通用工具函数。
#include <stdlib.h>
void at_exit_func ()
{
    cout << "at exit func." << endl;
}
void stdlib_test()
{
    // 1. int atoi(const char *str)
    // 把参数 str 所指向的字符串转换为一个整数（类型为 int 型）。
    // 函数实现*****

    // void *malloc(size_t size)
    // 分配所需的内存空间，并返回一个指向它的指针。
    // 内存块的大小，以字节为单位。
    // 该函数返回一个指针 ，指向已分配大小的内存。如果请求失败，则返回 NULL。

    // void *calloc(size_t nitems, size_t size)
    // 分配所需的内存空间，并返回一个指向它的指针。
    // malloc 和 calloc 之间的不同点是，malloc 不会设置内存为零，而 calloc 会设置分配的内存为零。

    // void *realloc(void *ptr, size_t size)
    // 尝试重新调整之前调用 malloc 或 calloc 所分配的 ptr 所指向的内存块的大小。

    // 	void free(void *ptr)
    // 释放之前调用 calloc、malloc 或 realloc 所分配的内存空间。

    // calloc、malloc 或 realloc 的区别是什么
    // 1. 

    // void abort(void)
    // 使一个异常程序终止。

    //int atexit(void (*func)(void)) 
    // 当程序正常终止时，调用指定的函数 func。您可以在任何地方注册你的终止函数，但它会在程序终止的时候被调用。
    /* 注册终止函数 */
    atexit(at_exit_func);

    // void exit(int status) 
    // 立即终止调用进程。任何属于该进程的打开的文件描述符都会被关闭，该进程的子进程由进程 1 继承，初始化，且会向父进程发送一个 SIGCHLD 信号。
    
    // int system(const char *command) 
    // 把 command 指定的命令名称或程序名称传给要被命令处理器执行的主机环境，并在命令完成后返
    system("ls -l");
}

// string .h 
// 头文件定义了一个变量类型、一个宏和各种操作字符数组的函数。
// 注意：掌握 string.h 下所有函数的实现方式
#include <string.h>
void string_test()
{
    // 1. void *memchr(const void *str, int c, size_t n) 
    // 在参数 str 所指向的字符串的前 n 个字节中搜索第一次出现字符 c（一个无符号字符）的位置。
    const char buf[] = "hello, wolrd.";
    char *pos = (char*)memchr(buf, ',', 10);
    
    // 2. int memcmp(const void *str1, const void *str2, size_t n)) 
    // 把存储区 str1 和存储区 str2 的前 n 个字节进行比较。
    char str1[15];
    char str2[15];
    int ret;

    memcpy(str1, "abcdef", 6);
    memcpy(str2, "ABCDEF", 6);

    ret = memcmp(str1, str2, 5);
    if (ret > 0)
        cout << "str1 > str2." << endl;

    // 3. void *memcpy(void *str1, const void *str2, size_t n) 
    // 从存储区 str2 复制 n 个字符到存储区 str1
    // 该函数返回一个指向目标存储区 str1 的指针。
    const char src[50] = "http://www.runoob.com";
    char dest[50];
    memcpy(dest, src, strlen(src)+1);
    printf("dest = %s\n", dest);

    // 4. void *memmove(void *str1, const void *str2, size_t n) 
    // 从 str2 复制 n 个字符到 str1，但是在重叠内存块这方面，memmove() 是比 memcpy() 更安全的方法。
    // 如果目标区域和源区域有重叠的话，memmove() 能够保证源串在被覆盖之前将重叠区域的字节拷贝到目标区域中，
    // 复制后源区域的内容会被更改。如果目标区域与源区域没有重叠，则和 memcpy() 函数功能相同。

    // 5. void *memset(void *str, int c, size_t n) 
    // 复制字符 c（一个无符号字符）到参数 str 所指向的字符串的前 n 个字符。

}


// time.h 头文件定义了四个变量类型、两个宏和各种操作日期和时间的函数。
#include <time.h>
void time_test()
{

}

int main()
{
    //assert_test();
    //ctype_test();
    //signal_test();
    //stdio_test();
    //file_test();
    //stdlib_test();
    string_test();

    return 0;
}