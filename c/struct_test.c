/*
测试 redis 中操作结构体方法
*/
typedef char *sds;

struct sdshdr
{
    int len;
    int free;
    char buff[];
};

static inline int sdslen(const sds s) {
    struct sdshdr *sh = (void*)(s-(sizeof(struct sdshdr)));
    return sh->len;
}

int main()
{
    struct sdshdr test;
    test.len = 100;
    test.free = 50;
    char arr[] = "hello world.";
    printf("len:%d\n", sdslen(test.buff));
}

