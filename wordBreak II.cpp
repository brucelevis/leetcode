/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

void printvec(vector<string > A, char *name)
{
	printf("%s:\n",name);
	for(int i = 0;i<A.size();i++)
	{
		printf("%13d:",i);
		cout<<A[i]<<endl;
	}
	printf("\n");
}

class Solution {
public:
    //vector<string> wordBreak(string s, unordered_set<string> &dict) {
   	vector<string> wordBreak(string s, set<string> &dict) {
   		int size = s.size();
   		vector<string> ret;
       vector<vector<string> > vec(size,vector<string>());
	   vector<bool> dp(s.size()+1,false);
	   
	   //printf("%d\n",vec.size());
	   
       dp[0] = true;
       for(int i = 1;i<=s.size();i++)
       {
       		//printf("%d-%d\n",i-1,(int)dp[i-1]);
       		if(dp[i-1])
       		{
       			int idx = i-1;
       			for(int j = idx;j<s.size();j++)
       			{
       				string str = s.substr(idx,j-idx+1);
       				if(dict.find(str) != dict.end())
       				{
       					dp[j+1] = true;
  						vec[idx].push_back(str);//////////////////////////////
       				}
	   			}	   			
       		}
	   }
	   //printf("%d-%d\n",s.size(),(int)dp[s.size()]);
	   if(dp[s.size()])
	   {
	   		string tmp;
	   		DFS(ret,vec,0,"",s);
	   }
	   
	   return ret;
	}
	void DFS(vector<string> &ret,vector<vector<string> > &vec,int idx,string tmp,const string &s)//tmp不能使用引用 
	{
		//printf("idx = %d-------------%d\n",idx,s.size());
		if(idx == s.size())
		{
			//cout<<"tmp = "<<tmp<<endl;
			tmp.erase(tmp.size()-1,1);//去除最后一个空格 
			//cout<<"tmp = "<<tmp<<endl;
			ret.push_back(tmp);///////////////////tmp不能使用引用 
			return;
		}
		else if(idx > s.size())
			return;
		
		for(int i = 0;i<vec[idx].size();i++)
		{
			//cout<<vec[idx][i]<<endl;
			int len = vec[idx][i].size(); 
			tmp = tmp + vec[idx][i] + " ";
			DFS(ret,vec,idx+len,tmp,s);
			tmp.erase(tmp.size()-len-1,len+1);
		}
	}
};


void test0()
{
	set<string> dict;
	dict.insert("cat");
	dict.insert("cats");
	dict.insert("and");
	dict.insert("sand");
	dict.insert("dog");
	
	Solution so;
	
	vector<string> out = so.wordBreak("catsanddog",dict);
	printvec(out,"out");
	if( !true)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	test0();
	return 0;
}