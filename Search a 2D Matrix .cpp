/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        if(m < 1)	return false;
        int n = matrix[0].size();
        int low = 0, high = m*n-1;
        while(low<=high)
        {
        	int mid = (low+high)/2;
        	int row = mid/n;
        	int col = mid%n;
        	if(target == matrix[row][col])	return true;
        	if(target > matrix[row][col])	low = mid + 1;
        	else 							high = mid - 1;
		}
		return false;
    }
};

void test0()
{
	if(i != len)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	test0();
	return 0;
}