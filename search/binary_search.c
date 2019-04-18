#include <stdio.h>

int binary_search(int a[], int value, int n)
{
	int begin, end = n - 1;

	while(begin <= end)
	{
		int middle = (begin + end) / 2;

		if(a[middle] == value)
			return middle;
		else if(a[middle] > value)
			end = middle - 1;
		else
			begin = middle + 1;
	}

	return -1;
}

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	printf("%d\n", binary_search(a, 10, 10));
}

