/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret;
		int start = 0, end = n-1,mid = 0;
        while(start <= end)
        {
        	mid = (start+end)/2;
        	if(A[mid] == target)
        	{
        		if(mid > 0 && A[mid - 1] != target || mid == 0)
       		 		break;
   		 		else
   		 			end = mid - 1;
			}
        	else if(A[mid] < target)
        		start = mid+1;
       		else
       			end = mid - 1;
		}
		if(start <= end)	ret.push_back(mid);
		else
		{
			ret.push_back(-1);
			ret.push_back(-1);
			return ret;
		}
		start = 0, end = n-1;
        while(start <= end)
        {
        	mid = (start+end)/2;
        	if(A[mid] == target)
        	{
        		if(mid < n-1 && A[mid + 1] != target || mid == n-1)
       		 		break;
   		 		else
   		 			start = mid + 1;
			}
        	else if(A[mid] < target)
        		start = mid+1;
       		else
       			end = mid - 1;
		}
		ret.push_back(mid);
		return ret;
    }
};
void test0()
{
	if(1)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	test0();
	return 0;
}