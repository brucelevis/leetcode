/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;

void printvec(vector<char > A)
{
	for(int i = 0;i<A.size();i++)
	{
		printf("%c,",A[i]);
	}
	printf("\n");
}

void printvecvec(vector<vector<char > > A, char *name)
{
	printf("%s\n",name);
	for(int i = 0;i<A.size();i++)
	{
		printf("%3d:",i);
		printvec(A[i]);
	}
	printf("\n");
}
#if 1//深度优先遍历，超时 

class Solution {
public:
    void solve(vector<vector<char> > &board) {
    	int m = board.size();
		if(m < 1)	return;
		int n = board[0].size();
		//把与四边上的O相连的所有O换为# 
		for(int i = 0;i<m;i++)//左 
			solveCore(board,i,0);
		for(int i = 0;i<m;i++)//右 
			solveCore(board,i,n-1);
			
		for(int j = 1;j<n-1;j++)//上 
			solveCore(board,0,j);
		for(int j = 1;j<n-1;j++)//下 
			solveCore(board,m-1,j);
		
		//把所有O换为X 
		for(int i = 0;i<m;i++)
		{
			for(int j = 0;j<n;j++)
			{
				if(board[i][j] == 'O')
					board[i][j] = 'X';
			}
		}
		//把所有#换为O 
		for(int i = 0;i<m;i++)
		{
			for(int j = 0;j<n;j++)
			{
				if(board[i][j] == '#')
					board[i][j] = 'O';
			}
		}
		    
    }
    void solveCore(vector<vector<char> > &board,int i, int j)
    {
    	if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'O')
			return;
	
		//printf("%d-%d:\n",i,j);
		//printvecvec(board,"core");	
		//system("pause");
		board[i][j] = '#';
		
		solveCore(board,i,j-1);
		solveCore(board,i+1,j);
		solveCore(board,i,j+1);		
		solveCore(board,i-1,j);
	}
};
#elif 0//广度优先遍历，通过 

class Solution {
public:
    queue<int> q;
    int m, n;
    
    void add(int x, int y, vector<vector<char>> &board) {
        if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O') {
            board[x][y] = 'Z';
            q.push(x * n + y);
        }    
    }
    
    void traversal(int x, int y, vector<vector<char>> &board) {
        add(x, y, board);
        while (!q.empty()) {
            int p = q.front();
            q.pop();            
            int px = p / n, py = p % n;
            add(px - 1, py, board);
            add(px + 1, py, board);
            add(px, py - 1, board);
            add(px, py + 1, board);
        }
    }
    
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (board.empty() || board.size() == 0 || board[0].size() == 0) {
            return;
        }
        m = board.size(), n = board[0].size();
        for (int i = 0; i < n; i++) {
            traversal(0, i, board);
            traversal(m - 1, i, board);
        }
        for (int i = 0; i < m; i++) {
            traversal(i, 0, board);
            traversal(i, n - 1, board);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = board[i][j] == 'Z' ? 'O' : 'X';
            }
        }
    }
};
#endif

void test0()
{
	char G[4][4] = {{'X','X','X','X'},
					{'X','O','O','X'},
					{'X','O','O','X'},
					{'X','O','X','X'}};
	int m = 4,n = 4;
	vector<vector<char> > grid;
	vector<char> tmp;
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
	so.solve(grid);
	printvecvec(grid,"ret");
}
void test1()
{
	char G[4][4] = {{'X','X','X','X'},
					{'X','X','O','X'},
					{'X','O','O','X'},
					{'X','O','X','X'}};
	int m = 4,n = 4;
	vector<vector<char> > grid;
	vector<char> tmp;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			tmp.push_back(G[i][j]);
		}
		grid.push_back(tmp);
		tmp.clear();
	}
	printvecvec(grid,"\n\n\n\ngrid");
	Solution so;
	so.solve(grid);
	printvecvec(grid,"ret");
}


int main()
{
	test0();
	test1();
	test2();
	return 0;
}