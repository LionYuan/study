#include <stdio.h>

/*
名称：选择排序
数据结构：数组
最差时间复杂度：o(n^2) n的平方
最优时间复杂度：o(n^2)
平均时间复杂度：o(n^2)
所需辅助空间：o(1)
稳定性：不稳定
*/

void selectionsort(int *a, int n)
{
	int i = 0, j = 0, min=0;

	for(i = 0; i < n; ++i)
	{
		min = i;
		for(j = i + 1; j < n; ++j)
		{
			if(a[j] < a[min])
			{
				min = j;
			}
		}
		if(min != i)//在这儿有可能把顺序打乱
		{
			int tmp = a[min];
			a[min] = a[i];
			a[i] = tmp;
		}
	}
}

int main()
{
	int a[] = {6,5,3,1,8,7,2,4};
	int n = sizeof(a)/sizeof(int);
	
	selectionsort(a, n);

	int i;
	printf("选择排序的结果是：\n");
	for(i=0;i<n;++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}