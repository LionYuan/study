#include <stdio.h>

/*
名称：快速排序
数据结构：数组
最差时间复杂度：o(n^2) n的平方
最优时间复杂度：o(nlogn)
平均时间复杂度：o(nlogn)
所需辅助空间：o(logn)~o(n)
稳定性：不稳定
*/

int partition(int *a, int left, int right)
{
	int pivot = a[left];
	
	while(left < right)
	{
		// 注意 >= ，如果不加等于的情况，遇到相同的数字会陷入死循环
		while(left < right && a[right] >= pivot) --right;
		a[left] = a[right];
		while(left < right && a[left] <= pivot) ++left;
		a[right] = a[left];
	}
	a[left] = pivot;
	return left;
}

void quicksort(int* a, int left, int right)
{
	// 退出递归的判断条件
	if(left < right)
	{
		int pivot_index = partition(a, left, right);
		quicksort(a, left, pivot_index - 1);
		quicksort(a, pivot_index + 1, right);
	}
}

int main()
{
	int a[] = {6,5,3,1,8,7,2,4};
	//int a[] = {1, 1, 1};
	int n = sizeof(a)/sizeof(int);

	quicksort(a, 0, n - 1);	

	printf("选择排序的结果是：\n");
	for(int i=0;i<n;++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
