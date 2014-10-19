/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        map<char,int> needmp;
        map<char,int> havemp;
        for(int i = 0;i<T.size();i++)
        {
        	havemp[T[i]] = 0;
        	needmp[T[i]] = 0;
        }
        for(int i = 0;i<T.size();i++)
        	needmp[T[i]]++;
        	
       	int count = T.size();
       	int start = -1, minstart = -1;
       	int min_len = INT_MAX;
       	for(int i = 0;i<S.size();i++)
       	{
       		if(!needmp.count(S[i]))	continue;
       		if(start == -1)	start = i;
   			havemp[S[i]]++;
   			//printf("----1 %d--%c---%d\n",i,S[i],mp[S[i]]);
   			
   			if(havemp[S[i]] <= needmp[S[i]])
   				count --;
   		
			//printf("2 %d--%c---%d\n",i,S[i],mp[S[i]]);
			while(count == 0)
			{
				//printf("3 %d--%c---%d\n",i,S[i],mp[S[i]]);
				//printf("4 %d--%c---%d\n",start,S[start],mp[S[start]]);
				if(i-start+1 <min_len)
			   {	
			   		//printf("5 %d--%c---%d\n",start,S[start],mp[S[start]]);
			   		min_len = i-start+1;
					minstart =  start;							
			   }
			   havemp[S[start]]--;
				if(havemp[S[start]] < needmp[S[start]])	count++;
				//printf("count = %d\n",count);
				if(start<i)////////////////////////////////////////////////////////////////////////
				{
					start++;
					while(!needmp.count(S[start]))	start++;
				}
				else
					break;
			   //system("pause");
			}
	   	}
	   	if(min_len == INT_MAX)	return "";///////////////////////////////////////////////////////////////////////
	   	string ret(S,minstart,min_len);
	   	return ret;
    }
};


void check(string S,string T,string ret)
{
	Solution so;
	string out = so.minWindow(S,T);
	cout<<out<<endl;
	if(out != ret)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	check("ADOBECODEBANC","ABC","BANC"); 
	check("a","a","a"); 
	check("a","aa",""); 
	check("aa","aa","aa"); 
	check("acbbaca","aba","baca"); 
	return 0;
}