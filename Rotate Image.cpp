#include <iostream>
#include <vector>
using namespace std;
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
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for(int i = 0;i<n/2;i++)
        {
        	for(int j = i;j<n-i-1;j++)
        	{
        		int tmp = matrix[i][j];//Ë³Ê±Õë90¶È¸´ÖÆ 
        		matrix[i][j] = matrix[n-j-1][i];
        		matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
        		matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
        		matrix[j][n-i-1] = tmp;
			}
		}
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
	so.rotate(grid);
	printvecvec(grid,"grid");
}

int main(int argc, char *argv[])
{
	test0();
	return 0;
}

