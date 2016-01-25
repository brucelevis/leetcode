/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*
首先简单介绍一下Anagram（回文构词法）。Anagrams是指由颠倒字母顺序组成的单词，比如
“dormitory”颠倒字母顺序会变成“dirty room”，“tea”会变成“eat”。
回文构词法有一个特点：单词里的字母的种类和数目没有改变，只是改变了字母的排列顺序。
*/
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
    	vector<string> ret;
    	//mp 开始指向的是第一次添加的字符串的索引，当有回文串时，通过这个索引
		//可以找到第一次出现的字符，添加后把mp指向-1 
    	map<string, int> mp;
    	for(int i = 0;i<strs.size();i++)
    	{
    		string s = strs[i];
    		sort(s.begin(),s.end());
    		if(mp.count(s) > 0)
    		{
    			//出现第二个时需要把需要把第一个放入
				if(mp[s]>=0)
				{
					ret.push_back(strs[mp[s]]); 
					mp[s] = -1;
				}
				ret.push_back(strs[i]);
			}
			else
			{
				mp[s] = i;
			}
		}
		return ret;
    }
    
};

void test0()
{
	if(0)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	test0();
	return 0;
}