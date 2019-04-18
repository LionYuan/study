/*
memcpy的实现
*/
#include <stdio.h>
#include <iostream>

using namespace std;

/*
memcpy的实现
*/
void* _memcpy(void *dst, const void *src, size_t n)
{
	if(dst == NULL || src == NULL)
		return NULL;

	// 指针必须要做类型转换，否则编译报错
	char *pSrc = (char*)src;
	char *pDest = (char*)dst;

	while(n--) *pDest++ = *pSrc++;

	return dst;
}

/*
memmove
*/
void* _memmove(void *dst, const void *src, size_t n)
{
	if (dst == NULL || src == NULL)
		return NULL;

	char *pSrc = (char*)src;
	char *pDst = (char*)dst;

	//判断是否有内存重叠
	if (pDst > pSrc && pDst < pSrc + n)
	{
		pSrc += n - 1;
		pDst += n - 1;

		while(n--) *pDst-- = *pSrc--;
	}
	else
	{
		while(n--) *pDst++ = *pSrc++;
	}

	return dst;
}

/*
memset的实现
*/
void* _memset(void *dst, int c, size_t n)
{
	if (dst == NULL)
		return NULL;

	char *p = (char*)dst;

	while(n--) *p++= c;

	return dst;
}

int main()
{

	char src[] = "hello";
	char dst[20];
	
	_memcpy(dst, src, sizeof(src));
	cout << "dst:" << dst << endl;

	// 内存重叠拷贝测试
	char *p = src+3;
	_memmove(p, src, sizeof(src));
	cout << "p:" << p << endl;

	_memset(dst, 'a', 5);
	cout << "_memset dst:" << dst << endl;

	return 0;
}