/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
    	if(matrix.size() < 1)	return;
        vector<int > col(matrix[0].size(),0);
        vector<int > row(matrix.size());
        for(int i = 0;i<matrix.size();i++)
        {
        	for(int j = 0;j<matrix[0].size();j++)
        	{
        		if(matrix[i][j] == 0)
        		{
        			row[i] = 1;
        			col[j] = 1;
				}
			}
		}
		for(int i = 0;i<matrix.size();i++)
        	for(int j = 0;j<matrix[0].size();j++)
        		if(row[i] == 1 || col[j] == 1)
        			matrix[i][j] = 0;
    }
};
void printvec(vector<int > A)
{
	for(int i = 0;i<A.size();i++)
	{
		printf("%3d,",A[i]);
	}
	printf("\n");
}

void printvecvec(vector<vector<int > > A, char *name)
{
	printf("%s\n",name);
	for(int i = 0;i<A.size();i++)
	{
		printf("%3d:",i);
		printvec(A[i]);
	}
	printf("\n");
}
void test0()
{
	int G[3][3] = {{1,2,3},{4,0,6},{7,8,9}};
	int m = 3,n = 3;
	vector<vector<int> > grid;
	vector<int> tmp;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			tmp.push_back(G[i][j]);
		}
		grid.push_back(tmp);
		tmp.clear();
	}
	
	printvecvec(grid,"grid");
	
	Solution so;
	so.setZeroes(grid);
	printvecvec(grid,"grid");
	if(1)
	
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