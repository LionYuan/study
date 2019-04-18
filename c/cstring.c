#include <stdio.h>

int main()
{
	char a[10];//未初始化
	for(int i = 0; i < 10; ++i)
	{
		printf("%d=%c\n", i, a[i]);
	}

}
