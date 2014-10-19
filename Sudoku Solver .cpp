/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;
void printvec(vector<char > A)
{
	for(int i = 0;i<A.size();i++)
	{
		printf("%c ",A[i]);
		if(i%3==2)
			printf("   ");
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
		if(i%3==2)
			printf("\n");
	}
	printf("\n");
}
class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
     	   solveSudokuCore(board,0);
    }
    bool solveSudokuCore(vector<vector<char> > &board,int index)
    {
    	if(index == 81) return true;/////////////////////////////////////////81
    	
    	int m = index / 9, n = index%9;
    	if(board[m][n] != '.')
    	{
    		return solveSudokuCore(board,index+1);
		}
    //	printvecvec(board,"board");	
    //	system("pause");
    	set<char> leftnum;
    	for(int i = 1;i<10;i++)
    		leftnum.insert((char)(i+'0'));
   		
   		for(int i = 0;i<9;i++)
   		{
   			if(board[m][i] != '.')
    			leftnum.erase(board[m][i]);
   		}
   		
   		for(int i = 0;i<9;i++)
   		{
   			if(board[i][n] != '.')
    			leftnum.erase(board[i][n]);
   		}
   		int r = (m/3)*3;
   		int c = (n/3)*3;
   		for(int i = 0;i<3;i++)
   			for(int j = 0;j<3;j++)
   			{
   				if(r+i != m && c+j != n && board[r+i][c+j] != '.')
   					leftnum.erase(board[r+i][c+j]);
		   	}
	   	set<char>::iterator it;
	   /*	printf("++%d,%d :",m,n);
	   	for (it=leftnum.begin(); it!=leftnum.end(); ++it)
   		{
				printf("%c  ", *it);
	   	}
	   	printf("\n");
   		*/
   		
   		for (it=leftnum.begin(); it!=leftnum.end(); ++it)
   		{
   			board[m][n] = *it;
   			//printf("%d,%d %c test\n",m,n,*it);
   			if(solveSudokuCore(board,index+1))
   				return true;
		//	else
		//		printf("%d,%d %c not ok\n",m,n,*it);
	   	}
	   	board[m][n] = '.';//////////////////////////////////////////////////////////////////
	   	return false;
    		
	}
};


void test0()
{
	/*
	char G[9][9] = {{'5','3','.',  '.','7','.',  '.','.','.'},
					{'6','.','.',  '1','9','5',  '.','.','.'},
					{'.','9','8',  '.','.','.',  '.','6','.'},
					
					{'8','.','.',  '.','6','.',  '.','.','3'},
					{'4','.','.',  '8','.','3',  '.','.','1'},
					{'7','.','.',  '.','2','.',  '.','.','6'},
					
					{'.','6','.',  '.','.','.',  '2','8','.'},
					{'.','.','.',  '4','1','9',  '.','.','5'},
					{'.','.','.',  '.','8','.',  '.','7','9'},
					};
	*/
	
	char G[9][9] = {{'5','3','.',  '.','7','.',  '.','.','.'},
					{'6','.','.',  '1','9','5',  '.','.','.'},
					{'.','9','8',  '.','.','.',  '.','6','.'},
					
					{'8','.','.',  '.','6','.',  '.','.','3'},
					{'4','.','.',  '8','.','3',  '.','.','1'},
					{'7','.','.',  '.','2','.',  '.','.','6'},
					
					{'.','6','.',  '.','.','.',  '2','8','.'},
					{'.','.','.',  '4','1','9',  '.','.','5'},
					{'.','.','.',  '.','8','.',  '.','7','.'},
					};
	/**/
	int m = 9,n = 9;
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
	so.solveSudoku(grid);
	printvecvec(grid,"ret");
}

int main()
{
	test0();
	return 0;
}