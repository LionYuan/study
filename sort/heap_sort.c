#include <stdio.h>

// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(nlogn)
// 最优时间复杂度 ---- O(nlogn)
// 平均时间复杂度 ---- O(nlogn)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 不稳定

/*堆排序对n较大的*/

int heapsize = 0;

void exchange(int a[], int i, int j)
{
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}
//递归调整
void heapify(int a[], int i)
{
	int leftchild = 2 * i + 1;//i的左孩子节点
	int rightchild = 2 * i + 2;//跌右孩子节点
	int largest = 0;
	
	//在父节点，左右孩子节点之间选出最的节点
	if(leftchild < heapsize && a[leftchild] > a[i])
	{
		largest = leftchild;
	}
	else
	{
		largest = i;
	}

	if (rightchild < heapsize && a[rightchild] > a[largest])
	{
		largest = rightchild;
	}
	
	if(largest != i)
	{
		exchange(a, i, largest);
		heapify(a, largest);
	}
}

//非递归调整
/*
void heapify1(int a[], int n)
{
	for(int i = 0; i < n )
}
*/

void buildheap(int a[], int n)
{
	heapsize = n;
	for(int i = heapsize / 2 - 1; i >= 0; --i)
	{
		heapify(a, i);
	}
}

//堆排序
void heapsort(int a[], int n)
{
	buildheap(a, n);//创建大顶堆
	for(int i = n - 1; i >= 1; i --)
	{
		exchange(a, 0, i);//将堆顶元素和堆的最后一个元素互换

		heapsize--;//调整当前堆大小
		heapify(a, 0);//调整堆，重新生成大顶堆
	}
}

int main()
{
	int a[] = {6,5,3,1,8,7,2,4};
	int n = sizeof(a)/sizeof(int);
	int i = 0, j = 0;

	heapsort(a, n);
	
	printf("选择排序的结果是：\n");
	for(i=0;i<n;++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
