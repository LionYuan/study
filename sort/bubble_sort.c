#include <stdio.h>

/*
名称：冒泡排序
数据结构：数组
最差时间复杂度：o(n^2) n的平方
最优时间复杂度：o(n)
平均时间复杂度：o(n^2)
所需辅助空间：o(1)
稳定性：稳定
*/

void bubblesort(int *a, int n)
{
	int i=0, j=0, tmp=0;

	for(i = 0; i < n - 1; ++i)//遍历0到n-1个元素
	{
		for(j=0; j < n - 1 - i; ++j)//进行交换
		{
			if(a[j]>a[j+1])
			{
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}	
		}
	}
}

int main()
{
	int a[] = {6,5,3,1,8,7,2,4};
	int n = sizeof(a)/sizeof(int);
	
	bubblesort(a, n);

	int i;
	for(i=0;i<n;++i)
	{
		printf("%d ", a[i]);
	}
	return 0;
}