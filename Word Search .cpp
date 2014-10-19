/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;


#if 1
class Solution {

public:

    bool exist(vector<vector<char> > &board, string word) {

        if (board.size() < 1) return false;

        if (board[0].size() < 1) return false;

        for (int i = 0; i < board.size(); i++) {

            for (int j = 0; j < board[0].size(); j++) {

                if (existHelper(board, i, j, word, 0)) {

                    return true;

                }

            }

        }

        return false;

    }

    bool existHelper(vector<vector<char> > &board, int x, int y, const string &word, int index) {

        if (index == word.size()) return true;

        if (x < 0 || x > board.size()) return false;

        if (y < 0 || y > board[0].size()) return false;

        if (board[x][y] != word[index]) return false;

        if (board[x][y] == '#') return false;

        board[x][y] = '#';

        if (existHelper(board, x + 1, y, word, index + 1) ||

            existHelper(board, x - 1, y, word, index + 1) ||

            existHelper(board, x, y - 1, word, index + 1) ||

            existHelper(board, x, y + 1, word, index + 1)) {

            board[x][y] = word[index];

            return true;

        }

        board[x][y] = word[index];

        return false;

    }

};
#elif 1
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        int m = board.size();
        if(m<1)	return false;
        int n = board[0].size();
        if(n<1)	return false;
        
        for(int i = 0;i<m;i++)
        {
        	for(int j = 0;j<n;j++)
        	{
        		if(board[i][j] != word[0])	continue;
        		if(existCore(i,j,board,word,0))
        			return true;
			}
		}
		return false;
    }
    
    bool existCore(int i,int j,vector<vector<char> > &board, string &word,int index)
    {
    	if(index == word.size())
    		return true;
    	
    	if(i < 0 || i >= board.size() || j < 0 || j>= board[0].size())
    		return false;
    		
   		//printf("i = %d,j = %d, index = %d,b = %c, w = %c\n",i,j,index,board[i][j],word[index]);
			
    	if(board[i][j] == '#' || board[i][j] != word[index])	
    		return false;
    		
   		bool flag = false;
    		
    	board[i][j] = '#';
    	if(existCore(i,j+1,board,word,index+1))	flag = true;//不能中途退出，否则board不能还原 
    	else if(existCore(i+1,j,board,word,index+1))	flag = true;
    	else if(existCore(i,j-1,board,word,index+1))	flag = true;
    	else if(existCore(i-1,j,board,word,index+1))	flag = true;
    	board[i][j] = word[index];
    	return flag;
	}
};
#elif 1
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        int m = board.size();
        if(m<1)	return false;
        int n = board[0].size();
        if(n<1)	return false;
        
        vector<vector<bool> > used(m, vector<bool>(n,false));
        for(int i = 0;i<m;i++)
        {
        	for(int j = 0;j<n;j++)
        	{
        		if(board[i][j] != word[0])	continue;
        		if(existCore(i,j,board,word,0,used))
        			return true;
			}
		}
		return false;
    }
    
    bool existCore(int i,int j,vector<vector<char> > &board, string &word,int index, vector<vector<bool> > &used)
    {
    	if(index == word.size())
    		return true;
    	
    	if(i < 0 || i >= board.size() || j < 0 || j>= board[0].size())
    		return false;
    		
   		//printf("i = %d,j = %d, index = %d,b = %c, w = %c\n",i,j,index,board[i][j],word[index]);
			
    	if(used[i][j] || board[i][j] != word[index])	
    		return false;
    		
    	used[i][j] = true;
    	if(existCore(i,j+1,board,word,index+1,used))	return true;
    	if(existCore(i+1,j,board,word,index+1,used))	return true;
    	if(existCore(i,j-1,board,word,index+1,used))	return true;
    	if(existCore(i-1,j,board,word,index+1,used))	return true;
    	used[i][j] = false;
    	return false;
	}
};
#endif

void test0()
{
	
	char boardc[3][5] = {"ABCE","SFCS","ADEE"}; 
  	vector<vector<char> > board(3,vector<char> (4));
  	
  	for(int i = 0;i<3;i++)
  	{
  		for(int j = 0;j<4;j++)
  		{
  			board[i][j] = boardc[i][j];
	  	}
 	}
  	
  	Solution so;
  	
  	
	if(so.exist(board,"ABCCED") == true)
		printf("------------------------passed\n");
	else
		printf("------------------------failed\n");
		
	if(so.exist(board,"SEE") == true)
		printf("------------------------passed\n");
	else
		printf("------------------------failed\n");
	/**/	
	if(so.exist(board,"ABCB") == false)
		printf("------------------------passed\n");
	else
		printf("------------------------failed\n");
}
int main()
{
	test0();
	return 0;
}