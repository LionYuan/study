#include <stdio.h>

/// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- 根据步长序列的不同而不同。已知最好的为O(n(logn)^2)
// 最优时间复杂度 ---- O(n)
// 平均时间复杂度 ---- 根据步长序列的不同而不同。
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 不稳定

void shellsort(int *a, int n)
{
	int i = 0, j = 0;
	int dk = n/2;
	int get = 0;

	while(dk >= 1)
	{
		for(i = dk; i < n; ++i)
		{
			//内部实现，插入排序
			get = a[i];
			j = i - dk;
			while(j >= 0 && a[j] > get)
			{
				a[j + dk] = a[j];//记录后移
				j = j - dk;
			}
			a[j + dk] = get;
		}

		dk /= 2;
	}
}

int main()
{
	int a[] = {6,5,3,1,8,7,2,4};
	int n = sizeof(a)/sizeof(int);
	
	shellsort(a, n);
	
	int i;
	printf("选择排序的结果是：\n");
	for(i=0;i<n;++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
