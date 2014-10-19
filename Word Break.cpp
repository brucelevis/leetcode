/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

#if 1
class Solution {
public:
    //bool wordBreak(string s, unordered_set<string> &dict) {
   	bool wordBreak(string s, set<string> &dict) {
		int size = s.size();
       vector<bool> dp(s.size()+1,false);
       dp[0] = true;
       for(int i = 1;i<=s.size();i++)
       {
       		if(dp[i-1])
       		{
       			int len = size - i + 1;       			
       			set<string>::iterator it_set;
       			//unordered_set<string>::iterator it_set;
       			for(it_set = dict.begin();it_set != dict.end();it_set++)
       			{
       				int len2 = it_set->size();//////////////////////->
       				if(len >= len2 && !dp[i-1+len2])///////////////////判断清楚索引应该是什么 
       				{
       					if(s.substr(i-1,len2) == *it_set)
       						dp[i-1+len2] = true;
	 				}
  				}
       		}
	   }
	   return dp[s.size()];
	}
};
#elif 0 
class Solution {
public:
    //bool wordBreak(string s, unordered_set<string> &dict) {
   	bool wordBreak(string s, set<string> &dict) {
       vector<bool> dp(s.size()+1,false);
       dp[0] = true;
       for(int i = 1;i<=s.size();i++)
       {
       		if(dp[i-1])
       		{
       			int idx = i-1;
       			for(int j = idx;j<s.size();j++)
       			{
       				string str = s.substr(idx,j-idx+1);
       				if(dict.find(str) != dict.end())
       					dp[j+1] = true;
	   			}
       		}
	   }
	   return dp[s.size()];
	}
};
#endif
void test0()
{
	set<string> dict;
	dict.insert("leet");
	dict.insert("code");
	dict.insert("hello");
	dict.insert("world");
	
	Solution so;
	
	if(so.wordBreak("leetcode",dict) != true)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	test0();
	return 0;
}

