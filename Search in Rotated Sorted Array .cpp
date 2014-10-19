#include <iostream>
using namespace std;

#if 0
class Solution {
public:
    int search(int A[], int n, int target) {
        int low = 0, high = n-1 , mid = 0;
        while(low <= high)
        {
        	mid = (low + high)/2;
        	if(A[mid] == target)
				return mid;
        	if(A[mid] > A[low])
        	{
        		if(target >= A[low] && target < A[mid])
        			high = mid - 1;
       			else
        			low = mid+1;
        	}
        	else if(A[mid] < A[low])
        	{
        		if(A[mid] < target && target <= A[high])
					low = mid+1;
				else
					high = mid - 1;
			}
			else
			{
				if(A[high] < A[low])
					low = mid+1; 
				else 
				{
					for(mid = low;mid<=high;mid++)
					{
						if(A[mid] == target)	return mid;
					}
					if(mid > high)
						return -1;
				}
			}					
		}
		return -1;
    }
};
#elif 1
class Solution {
public:
    int search(int A[], int n, int target) {
        int low = 0, high = n-1 , mid = 0;
        while(low <= high)
        {
        	mid = (low + high)/2;
        	//printf("%d--%d--%d\n",low,mid,high);
        	if(A[mid] == target)
				return mid;
        	if(A[mid] >= A[low])
        	{
        		if(target >= A[low] && target < A[mid])
        			high = mid - 1;
       			else
        			low = mid+1;
        	}
        	else 
        	{
        		if(A[mid] < target && target <= A[high])
					low = mid+1;
				else
					high = mid - 1;
			}			
		}
		return -1;
    }
};
#endif
void test0()
{
	int A[] = {4,5,6,7,0,1,2,3};
	Solution so;
	if(so.search(A,8,7) != 3)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
} 
void test1()
{
	int A[] = {3,4,5,1,2,3,3,3,3,3,3,3,3};
	Solution so;
	if(so.search(A,13,5) != 2)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
} 
int main(int argc, char *argv[])
{
	test1();
	return 0;
}