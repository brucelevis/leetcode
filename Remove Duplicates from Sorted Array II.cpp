#include <iostream>
using namespace std;

class Solution {
public://举最简单的用例测试，尤其是0空之类 
    int removeDuplicates(int A[], int n) {
    	int num = 0;
    	if(n<=1) return n;//////////////////////////////////这里需要注意 
    	int preIndex = 1, pIndex = 1;
    	for(int i = 1;i<n;i++)
    	{
    		if(A[i] == A[i-1])
    		{
    			if(num<1)
    				A[preIndex++] = A[pIndex++];
   				else
   					pIndex++;
   				num++;/////////////////////////////++的位置 
			}
			else
			{
				A[preIndex++] = A[pIndex++];
				num = 0;
			}
		}
        return preIndex;
    }
};


int main(int argc, char *argv[])
{
	
	return 0;
}