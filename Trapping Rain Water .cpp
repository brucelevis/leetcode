#include <iostream>
#include <vector>
using namespace std;

#if 0
class Solution {
public:
    int trap(int A[], int n) {
    	int leftIndex = 0, rightIndex = n-1;
        
        int sumWater = 0;
        while(!A[leftIndex] && leftIndex<n)leftIndex++;	//找到左侧第一个非0 
        if(leftIndex == n)	return 0;	//全部为0 返回0 
        while(!A[rightIndex])rightIndex--;	//打到右边第一个非0 
        if(leftIndex == rightIndex || rightIndex == leftIndex+1)	
			return 0;//如果左右非0是同一个地方，或者相差一个位置，那个返回0 
        
        int maxLIndex = leftIndex, MaxRIndex = rightIndex;
        sumWater = 0;
        int tmpWater = 0;
        //printf("sumWater = %d\n",sumWater);
        //从左向右遍历一遍。 
        for(int i = leftIndex+1;i<=rightIndex;i++)
    	{
    		if(A[i] >= A[maxLIndex])//如果当前值超过之前记录的最大值，那个做一个总结 
    		{						// sumWater += (A[maxLIndex]*(i-maxLIndex-1) - tmpWater);
    			sumWater += (A[maxLIndex]*(i-maxLIndex-1) - tmpWater);
    			maxLIndex = i;
    			tmpWater = 0;
    			//printf("%d:sumWater = %d\n",i,sumWater);
			}
			else
			{
				tmpWater += A[i];//这里的A[i]肯定小于 A[maxLIndex]，所以A[i]代表的地方不能装水，后面需要减去 
				//printf("%d:tmpWater = %d\n",i,tmpWater);
			}
		}
		//同理需要从后再向左遍历一遍 
		tmpWater = 0;
		for(int i = rightIndex-1;i>=maxLIndex;i--)
    	{
    		if(A[i] >= A[MaxRIndex])
    		{
    			sumWater += (A[MaxRIndex]*(MaxRIndex-i-1) - tmpWater);
    			MaxRIndex = i;
    			tmpWater = 0;
    			//printf("%d:sumWater = %d\n",i,sumWater);
			}
			else
			{
				tmpWater += A[i];
				//printf("%d:tmpWater = %d\n",i,tmpWater);
			}
		}
		return sumWater;
    }
};
#elif 1
class Solution {
public:
    int trap(int A[], int n) {
        // Note: The Solution object is instantiated only once.
        if(A==NULL || n<1)return 0;
    	
		int maxheight = 0;
		vector<int> leftMostHeight(n);
		for(int i =0; i<n;i++)
		{
			leftMostHeight[i]=maxheight;
			maxheight = maxheight > A[i] ? maxheight : A[i];
		}

		maxheight = 0;
		vector<int> rightMostHeight(n);
		for(int i =n-1;i>=0;i--)
		{
			rightMostHeight[i] = maxheight;
			maxheight = maxheight > A[i] ? maxheight : A[i];
		}

		int water = 0;
		for(int i =0; i < n; i++)
		{
			int high = min(leftMostHeight[i],rightMostHeight[i])-A[i];
			if(high>0)
				water += high;
		}
		return water;
    }
};
#endif

void test0()
{
	int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	Solution so;
	if(so.trap(A,12) != 6)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
void test1()
{
	int A[] = {2,0,2};
	Solution so;
	if(so.trap(A,3) != 2)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main(int argc, char *argv[])
{
	test0();
	test1();
	return 0;
}