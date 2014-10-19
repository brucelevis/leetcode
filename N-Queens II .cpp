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
		printvecvec(A[1]);
	}
	printf("\n");
}

#if 0
class Solution {
public:
    int totalNQueens(int n) {
        int ret = 0;
        vector<int> A(n,-1);          
        int row = 0;
        while(row >= 0)
        {
        	A[row]++;
        	while(A[row]<n && !check(A,row))A[row]++;
        	if(A[row]<n)
        	{
        		if(row == n-1)/////
        		{
        			ret++;
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
    int totalNQueens(int n) {
        int ret = 0;
        vector<int> A(n,0);          
        solveNQueensCore(ret,A,0);
        return ret;
    }
    void solveNQueensCore(int &ret,vector<int> &A,int row)
    {
    	if(row == A.size())
    	{
    		ret ++;
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
	int out = so.totalNQueens(4);
	cout<<out<<endl;
}
int main()
{
	test0();
	return 0;
}


