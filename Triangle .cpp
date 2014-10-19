/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int m = triangle.size();
        if(m<1) return 0;
        vector<int> sum(m,0);
        for(int i = 0;i<m;i++)
        	sum[i] = triangle[m-1][i];
       	
       	for(int i = m-2;i>=0;i--)
       		for(int j = 0;j<=i;j++)
       			sum[j] = triangle[i][j]+(sum[j]>sum[j+1]?sum[j+1]:sum[j]);
	   	return sum[0];
    }
};


void test0()
{
	if(0)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	test0();
	return 0;
}