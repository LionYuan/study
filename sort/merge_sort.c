#include <stdio.h>

/// 分类 -------------- 合并排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(nlogn)
// 最优时间复杂度 ---- O(nlogn)
// 平均时间复杂度 ---- O(nlogn)
// 所需辅助空间 ------ O(n)
// 稳定性 ------------ 稳定

#define INT_MAX 100

//合并两个已经排好序的子数组
void merge(int a[], int left, int middle, int right)
{
	int i, j, k;
	int n1 = middle - left + 1;
	int n2 = right - middle;
	int L[10];
	int R[10];

	//先将两个排好序的数字放到数组中
	for(i = 0; i < n1; ++i)
		L[i] = a[left + i];
	for(i = 0; i < n2; ++i)
		R[i] = a[middle + 1 + i];
	
	//尾部设置最大值作为哨兵
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;

	//合并两个排好序的数组，
	for(i = 0, j = 0, k = left; k <= right; ++k)
	{
		if(L[i] <= R[j])
		{
			a[k] = L[i];
			++i;
		}
		else
		{
			a[k] = R[j];
			++j;
		}
	}
}

//递归实现归并
void mergesort_recursion(int *a, int left, int right)
{
	int middle = (left + right) / 2;
	if(left < right)
	{
		mergesort_recursion(a, left, middle);
		mergesort_recursion(a, middle + 1, right);
		merge(a, left, middle,right);
	}
}

//非递归，迭代实现归并
void mergesort_iteration(int *a, int left, int right)
{
	int low, middle, high;
	int size;
	//按照步长，进行合并
	for(size = 1; size <= right - left; size *= 2)
	{
		low = left;
		while(low + size - 1 <= right - 1)
		{
			middle = low + size - 1;
			high = middle + size;
			if(high > right)
				high = right;
			merge(a, low, middle, high);
			low = high + 1;
		}
	}
}

int main()
{
	int a[] = {6,5,3,1,8,7,2,4};
	int a1[] = {6,5,3,1,8,7,2,4};
	int n = sizeof(a)/sizeof(int);
	int i = 0, j = 0;

	mergesort_iteration(a, 0, n - 1);
	mergesort_recursion(a1, 0, n - 1);
	
	printf("选择排序的结果是：\n");
	for(i=0;i<n;++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	printf("选择排序的结果是：\n");
	for(i=0;i<n;++i)
	{
		printf("%d ", a1[i]);
	}
	printf("\n");

	return 0;
}
