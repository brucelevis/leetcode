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

//dp[i][j] 表示i~j是不是回文串 
class Solution {
public:
    int minCut(string s) {
    	vector<vector<string> > ret;
        int size = s.size();
        if(size == 0)	return 0;
		vector<vector<bool> > dp(size,vector<bool>(size,false));
		//vector<vector<bool> > dp(size,vector<bool>(false)); 这里第一遍竟写错了。 
		
		for(int i = 0;i<size;i++)
		{
			dp[i][i] = true;
			if(i<(size-1) && s[i]==s[i+1])
				dp[i][i+1] = true;
		} 
		//长度逐渐增加 
		for(int len = 3;len<=size;len++)
		{
			for(int i = 0;i+len<=size;i++)
			{
				int j = i+len-1;
				if(dp[i+1][j-1] && s[i]==s[j])
					dp[i][j] = true;
			}		
		} 
		//递归
		vector<int> cut(size,0);
		cut[0] = 0;
		//cut[i]表示前面i个字母最小的切割次数 
		for(int i = 1;i<size;i++)
		{
			if(dp[0][i])
			{
			 	cut[i] = 0;
			 	//printf("a%d:%d\n",i,cut[i]);
			}
		 	else
		 	{
				cut[i] = i;
				for(int j = 1;j<=i;j++)
				{
					if(dp[j][i])
						cut[i] = min(cut[i],cut[j-1]+1);
					///printf("b%d %d:%d\n",j,i,cut[i]);	
				}
			}
		}
		return cut[size-1];
    }
};




void test0(string str,int ret)
{
	Solution so;
	if(so.minCut(str) != ret)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	test0("aaba",1);
	return 0;
}