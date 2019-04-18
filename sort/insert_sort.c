#include <stdio.h>

/*
名称：直接插入排序
数据结构：数组
最差时间复杂度：o(n^2) n的平方
最优时间复杂度：o(n)
平均时间复杂度：o(n^2)
所需辅助空间：o(1)
稳定性：稳定
*/

void insertsort(int *a, int n)
{
	int i = 0, j = 0, get=0;

	for(i = 1; i < n; ++i)
	{
		get = a[i];//哨兵，记录当前要比较的值
		for(j = i - 1; j >= 0 && a[j] > get; --j)//将记录向右移动
		{
			a[j+1] = a[j];
		}
		a[j+1]=get;//将记录写入
	}
}

int main()
{
	int a[] = {6,5,3,1,8,7,2,4};
	int n = sizeof(a)/sizeof(int);
	int i;

	insertsort(a, n);

	for(i=0;i<n;++i)
	{
		printf("%d ", a[i]);
	}
	return 0;
}