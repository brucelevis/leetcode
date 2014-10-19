/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ret;
        if(matrix.size()<1)	return ret;
        for(int i = 0;i<(min(matrix.size(),matrix[0].size())+1)/2;i++)
        	spiralOrder(ret,matrix,i);
        return ret;
    }
    void spiralOrder(vector<int> &ret,vector<vector<int> > &matrix,int start)
    {//左上到右上 
    	int m =  matrix.size(), n = matrix[0].size();
    	for(int i = start;i<n-start;i++)
    		ret.push_back(matrix[start][i]);
   		if(m - start*2 == 1) return;
   	//右上到右下	
   		for(int i = start+1;i<m-start;i++)
    		ret.push_back(matrix[i][n-start-1]);
   		if(n - start*2 == 1) return;
	//右下到左下
        for(int i = n-start-2;i>= start;i--)
    		ret.push_back(matrix[m-start-1][i]);
	//右下到左上
		for(int i = m-start-2;i> start;i--)
    		ret.push_back(matrix[i][start]);
	}
};
void printvec(vector<int > A)
{
	for(int i = 0;i<A.size();i++)
	{
		printf("%d,",A[i]);
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
	int G[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
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
	vector<int> out = so.spiralOrder(grid);
	printvec(out);
	if(1)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
void test1()
{
	int G[1][3] = {{1,2,3}};
	int m = 1,n = 3;
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
	vector<int> out = so.spiralOrder(grid);
	printvec(out);
	if(1)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
void test2()
{
	int G[3][1] = {{1},{4},{7}};
	int m = 3,n = 1;
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
	vector<int> out = so.spiralOrder(grid);
	printvec(out);
	if(1)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	test0();
	test1();
	test2();
	return 0;
}