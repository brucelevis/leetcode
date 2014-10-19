/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/
#include <iostream>
#include <vector>
using namespace std;

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


class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int size = grid.size();        
		if(size == 0)	return 0;
		vector<vector<int> > minPath(size,vector<int>(grid[0].size()));
		minPath[0][0] = grid[0][0];
		for(int i = 1;i<grid[0].size();i++)
			minPath[0][i] = minPath[0][i-1] + grid[0][i];
		for(int j = 1;j<grid.size();j++)
			minPath[j][0] = minPath[j-1][0] + grid[j][0];
			
		for(int i = 1;i<grid[0].size();i++)
			for(int j = 1;j<grid.size();j++)
				minPath[j][i] = min(minPath[j][i-1],minPath[j-1][i]) + grid[j][i];
		//printvecvec(minPath,"minPath");
		return minPath[grid.size()-1][grid[0].size()-1];	
    }
};




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
	so.minPathSum(grid);
}
int main(int argc, char *argv[])
{
	test0();
	return 0;
}

