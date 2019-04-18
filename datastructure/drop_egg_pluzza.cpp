#include <iostream>

using namespace std;

// 关于扔鸡蛋问题：https://blog.csdn.net/joylnwang/article/details/6769160

// 在计算W(2,36)之前，我们需先计算出所有W(1,0),……，W(1,36),W(2,0),……,W(2,35)这些的值，可以用递推的方法实现
// 该算法的空间复杂度是O(nk)，时间复杂度是O(nk^2)
unsigned int DroppingEggsPuzzle(unsigned int eggs, unsigned int floors)
{
	unsigned int i, j, k, t, max;
	unsigned int temp[eggs + 1][floors + 1];
    
    // 初始化只有一个鸡蛋
	for(i = 0; i < floors + 1; ++i)
	{
		temp[0][i] = 0;
		temp[1][i] = i;
	}
    
    // 初始化有大于等于两个鸡蛋时，第一个鸡蛋的扔法
	for(i = 2; i < eggs + 1; ++i)
	{
		temp[i][0] = 0;
		temp[i][1] = 1;
	}
    
    // 
	for(i = 2; i < eggs + 1; ++i)
	{
		for(j = 2; j < floors + 1; ++j)
		{
			for(k = 1, max = UINT_MAX; k < j; ++k)
			{
				t = temp[i][j - k] > temp[i - 1][k -1] ?  temp[i][j - k] : temp[i - 1][k -1];
 
				if(max > t)
				{
					max = t;
				}
			}
 
			temp[i][j] = max + 1;
		}
	}
 
	return temp[eggs][floors];
}

int main()
{
    int num = DroppingEggsPuzzle(2, 36);
    cout << "2 egg, 36 floors need times:" << num << endl;
    return 0;
}