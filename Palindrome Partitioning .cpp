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
    vector<vector<string> > partition(string s) {
    	vector<vector<string> > ret;
        int size = s.size();
        if(size == 0)	return ret;
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
		vector<string> tmp;
		BFS(ret,s,dp,0,tmp);
		return ret;
    }
    void BFS(vector<vector<string> > &ret,string s,vector<vector<bool> > &dp,int index,vector<string> &tmp)
    {
    	if(index == s.size())
    	{
    		ret.push_back(tmp);    		
    		return;
		}
		for(int i = index;i<s.size();i++)
		{
			if(dp[index][i])
			{
				string str = s.substr(index,i-index+1);
				//cout<<index<<","<<i<<":"<<str<<endl;
				tmp.push_back(str);
				BFS(ret,s,dp,i+1,tmp);
				tmp.pop_back();
			}
		}
	}
};




void test0(string str)
{
	Solution so;
	printvecvec(so.partition(str),"out");
}
int main()
{
	test0("aaba");
	return 0;
}