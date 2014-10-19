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
   bool isValidSudoku(vector<vector<char> > &board) {
        // Note: The Solution object is instantiated only once.
		vector<vector<bool>> rows(9, vector<bool>(9,false));
		vector<vector<bool>> cols(9, vector<bool>(9,false));
		vector<vector<bool>> blocks(9, vector<bool>(9,false));

		for(int i = 0; i < 9; i++)
			for(int j = 0; j < 9; j++)
			{
				if(board[i][j] == '.')continue;
				int num = board[i][j] - '1';
				if(rows[i][num] || cols[j][num] || blocks[i - i%3 + j/3][num])
					return false;
				rows[i][num] = cols[j][num] = blocks[i - i%3 + j/3][num] = true;
			}
		return true;
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
	/*
	char G[9][9] = {{'.','.','.',  '.','.','.',  '.','.','.'},
					{'.','.','.',  '.','.','.',  '.','.','.'},
					{'.','.','.',  '.','.','.',  '.','.','.'},
					
					{'.','.','.',  '.','.','.',  '.','.','.'},
					{'.','.','.',  '.','.','.',  '.','.','.'},
					{'.','.','.',  '.','.','.',  '.','.','.'},
					
					{'.','.','.',  '.','.','.',  '.','.','.'},
					{'.','.','.',  '.','.','.',  '.','.','.'},
					{'.','.','.',  '.','.','.',  '.','.','.'},					
					};
					
					*/
	char G[9][9] = {{'.','.','4',  '.','.','.',  '.','6','3'},
					{'.','.','.',  '.','.','.',  '.','.','.'},
					{'5','.','.',  '.','.','.',  '.','.','9'},
					
					{'.','.','.',  '5','6','.',  '.','.','.'},
					{'4','.','3',  '.','.','.',  '.','.','1'},
					{'.','.','.',  '7','.','.',  '.','.','.'},
					
					{'.','.','.',  '5','.','.',  '.','.','.'},
					{'.','.','.',  '.','.','.',  '.','.','.'},
					{'.','.','.',  '.','.','.',  '.','.','.'},
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
	if(!so.isValidSudoku(grid))
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
	printvecvec(grid,"ret");
}

int main()
{
	test0();
	return 0;
}