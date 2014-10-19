#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    	int m = obstacleGrid.size();
    	if(m<1)	return 0;
    	int n = obstacleGrid[0].size();
		vector<vector<int> > f(m, vector<int>(n));
		
		if(obstacleGrid[0][0] == 1) return 0;
		f[0][0] = 1;
		for(int i = 1; i < n; i++)
		{	
			if(obstacleGrid[0][i])
				f[0][i] = 0;
			else
            	f[0][i] = f[0][i-1];
		}
            
        for(int i = 1; i < m; i++)
       	{	
			if(obstacleGrid[i][0])
				f[i][0] = 0;
			else
            	f[i][0] = f[i-1][0];
		}
            
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
            {
            	if(obstacleGrid[i][j])	
					f[i][j] = 0;
            	else
                f[i][j] = f[i-1][j]+f[i][j-1];
            }
                
        return f[m-1][n-1];
    }
};
/*
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
            {
                f[i][j] = f[i-1][j]!=1?f[i-1][j]:0 + f[i][j-1]!=1?f[i][j-1]:0;
            }
                
        return f[m-1][n-1];
    }
};
*/
int main(int argc, char *argv[])
{
	
	return 0;
}