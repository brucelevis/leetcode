#include <iostream>
using namespace std;

class Solution {
public:
    bool search(int A[], int n, int target) {
        int low = 0, high = n-1;
        while(low <= high)
        {
        	int mid = (low+high)/2;
        	if(A[mid] == target)	return true;
        	if(A[mid]>A[low])
        	{
        		if(target >= A[low] && target <= A[mid])/////////////////target >= A[low]这里需要加等号 
        			high = mid-1;
       			else
       				low = mid+1;
			}
			else if(A[mid]<A[low])
			{
				if(target >= A[mid] && target <= A[high])
        			low = mid+1;
       			else
       				high = mid-1;
			}
			else
			{
				if(A[high]<A[low])	low = mid+1;///////////////////这里不是high = mid-1 
				else
				{
					for(mid = low;mid<=high;mid++)
						if(A[mid] == target)	return true;
					if(mid>high)	return false;//////////////////////////这句不写会死循环 
				}
			}
		}
		return false;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}