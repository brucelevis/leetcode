/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;

void printvecvec(vector<string > A)
{
	for(int i = 0;i<A.size();i++)
	{
		printf("%13d:",i);
		cout<<A[i]<<endl;
	}
	printf("\n");
}

void printvecvec(vector<vector<string > > A, char *name)
{
	printf("%s\n",name);
	for(int i = 0;i<A.size();i++)
	{
		printf("%3d:\n",i);
		printvecvec(A[i]);
	}
	printf("\n");
}

#if 1
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ret;
        vector<int> A(n,-1);          
        int row = 0;
        while(row >= 0)
        {
        	A[row]++;
        	//printf("row = %d,Q= %d\n",row,A[row]);
        	while(A[row]<n && !check(A,row))A[row]++;
        	//printf("2row = %d,Q= %d\n",row,A[row]);
        	if(A[row]<n)
        	{
        		if(row == n-1)
        		{
        			vector<string> tmp(n,string(n,'.'));
		    		for(int i = 0;i<n;i++)
		    		{
		    			tmp[i][A[i]] = 'Q';
		    			//printf("i = %d,Q= %d\n",row,A[i]);
					}
					//printvecvec(tmp);
		    		ret.push_back(tmp);
				}
				else
				{
					row++;
					A[row] = -1;
				}
			}
			else
				row--;
		}
        
        return ret;
    }
    
	bool check(vector<int> &A,int k)
	{
		for(int i = 0;i<k;i++)
			if(abs(k-i) == abs(A[k] - A[i]) || A[k] == A[i])	return false;
		return true;
	}
};
#elif 1
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ret;
        vector<int> A(n,0);          
        solveNQueensCore(ret,A,0);
        return ret;
    }
    void solveNQueensCore(vector<vector<string> > &ret,vector<int> &A,int row)
    {
    	if(row == A.size())
    	{
    		vector<string> tmp(row,string(row,'.'));
    		for(int i = 0;i<row;i++)
    		{
    			tmp[i][A[i]] = 'Q';
			}
			//printvecvec(tmp);
    		ret.push_back(tmp);
    		return;
		}
		for(int i = 0;i<A.size();i++)
		{
			A[row] = i;
			//printf("row = %d,Q= %d\n",row,i);
			if(check(A,row))
				solveNQueensCore(ret,A,row+1);
		}
	}
	bool check(vector<int> &A,int k)
	{
		for(int i = 0;i<k;i++)
			if(abs(k-i) == abs(A[k] - A[i]) || A[k] == A[i])	return false;
		return true;
	}
};
#endif


void test0()
{
	Solution so;
	vector<vector<string> > out = so.solveNQueens(4);
	printvecvec(out,"out");
	
}
int main()
{
	test0();
	return 0;
}


