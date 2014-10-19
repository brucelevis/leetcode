/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/
#include <iostream>
#include <vector>
using namespace std;
#if 0//超时 
class Solution {
public:
    int uniquePaths(int m, int n) {
    	int sum = 0;
        uniquePathsCore(m,n,0,0,sum);
        return sum;
    }
    void uniquePathsCore(int m, int n, int i, int j, int &sum)
    {
    	if(i == m-1 && j == n-1)
		{
			sum++;
			//printf("(%d,%d) ",i,j);
			//printf("end\n");
			return;
		}
    	if(j<n-1)
    		/*printf("(%d,%d) ",i,j),*/uniquePathsCore(m,n,i,j+1,sum);
   		if(i<m-1)
    		/*printf("(%d,%d) ",i,j),*/uniquePathsCore(m,n,i+1,j,sum);
	}
};
#elif 1
class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > f(m, vector<int>(n));
        
        for(int i = 0; i < n; i++)
            f[0][i] = 1;
            
        for(int i = 0; i < m; i++)
            f[i][0] = 1;
            
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                f[i][j] = f[i-1][j] + f[i][j-1];
                
        return f[m-1][n-1];
    }
};
#endif
void test0()
{
	Solution so;
	if(so.uniquePaths(1,1) != 1)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
	
	if(so.uniquePaths(1,2) != 1)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
		
	if(so.uniquePaths(1,3) != 1)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
		
	if(so.uniquePaths(2,1) != 1)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
		
	if(so.uniquePaths(2,2) != 2)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
	
	int out = so.uniquePaths(23,12) ;
	if(out != 193536720)
		printf("------------------------failed %d \n",out);
	else
		printf("------------------------passed\n");
}
int main(int argc, char *argv[])
{
	test0();
	return 0;
}
