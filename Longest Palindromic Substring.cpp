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
	string convertString(string s)
	{
		string t;
		for(int i = 0;i<s.size();i++)
			t = t + "#" + (char)s[i];
		t = t + "#";
		return t; 
	} 
    string longestPalindrome(string s) {
  		string t = convertString(s);
  		int tsize = t.size();
  		vector<int> vec(tsize,0);
  		int C = 0, R = 0;
  		
  		for(int i = 0;i<tsize;i++)
  		{
  			int tmplen = 1;
  			int j = 0;
  			if(2*C > i)
  			{
  				j = 2*C - i;
  				tmplen = min(vec[j],R-i+1);
  			}  			
  			while(i-tmplen >= 0 && i+ tmplen < tsize && t[i-tmplen] == t[i+tmplen])
  			{
  				tmplen++;
		  	}
		  	
		  	vec[i] = tmplen;
		  	if(i+tmplen-1>R)
		  	{
		  		R = i+tmplen-1;
		  		C = i;
		  	}
			
 		}
 		
 		 /*
 		for(int i = 0;i<tsize;i++)
 		{
 			printf("%3c",t[i]);
 		}
 		cout<<endl;
 		for(int i = 0;i<tsize;i++)
 		{
 			printf("%3d",vec[i]);////vec[i] - 1是回文子串长度 
 		}
 		cout<<endl;
 		*/ 
 		
 		int maxIdx = 0, maxlen = 0;
 		for(int i = 0;i<tsize;i++)
 		{
 			if(vec[i]>maxlen)
			 {
			 	maxlen = vec[i];
			 	maxIdx = i;
			 }	
 		}
  		return s.substr((maxIdx + 1 - maxlen)/2 ,maxlen-1);//t中的索引 /2就是s中的索引 
    }
};
#elif 1 
class Solution {
public:
    string longestPalindrome(string s) {
  		int size = s.size();
  		int maxlen = 1, startIdx = 0;///////////////////////////////////初始值 一个 1一个0 
  		vector<vector<bool> > vec(size,vector<bool>(size,false));
  		for(int i = 0;i<size;i++)
  			vec[i][i] = true;
		for(int i = 1;i<size;i++)
		{
			if(s[i] == s[i-1])
			{
				vec[i-1][i] = true;
				maxlen = 2;///////////////////////////////////这里也要有判断 
				startIdx = i-1;//////////////////////////////// 
			}
		}
  		for(int len = 3;len<=size;len++)
  		{
  			for(int i = 0;i+len<=size;i++)
  			{
  				if(s[i] == s[i+len-1] && vec[i+1][i+len-2])
  				{
  					vec[i][i+len-1] = true;
  					maxlen = len;
  					startIdx = i;
			  	}
		  	}
  		}
  		string ret = s.substr(startIdx,maxlen);
  		return ret;
    }
};
#elif 0

class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
		if(size < 2)	return s;
		int maxlen = 0;
		int begin = 0;
		for(int i = 0;i<size;i++)
		{
			int tmplen = 0,tmpb = 0;
			for(int j = 0;j<size-i;j++)
			{
				if(s[j] == s[size- i - j -1])
				{
					if(tmplen == 0)	tmpb = j;
					tmplen++;
				}
				else
					tmplen = 0;
				if(tmplen > maxlen)
				{
					maxlen = tmplen;
					begin = tmpb;
				}
			}
			if(maxlen == size-i)
				break;
		} 
		for(int i = 1;i<size;i++)
		{
			int tmplen = 0,tmpb = 0;
			for(int j = i;j<size;j++)
			{
				if(s[j] == s[size-j+i-1])
				{
					if(tmplen == 0)	tmpb = j;
					tmplen++;
				}
				else
					tmplen = 0;
				if(tmplen > maxlen)
				{
					maxlen = tmplen;
					begin = tmpb;
				}
			}
			if(maxlen == size-i)
				break;
		} 
		string ret(s,begin,maxlen);
		return ret;
    }
};
#endif

void test0(string s,string ret)
{
	Solution so;
	string out = so.longestPalindrome(s);
	cout<<"input="<<s<<endl;
	cout<<"out = "<<out<<"   ret= "<<ret<<endl;
	if(out != ret)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	//test0("321012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210123210012321001232100123210123",
	//"321012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210123");
 
	test0("ccd","cc");
	test0("aba","aba");
	test0("abba","abba");
		/*/*
	test0("","");
	test0("a","a");
	test0("caba","aba");*/
	/*test0("aabcddcba","abcddcba");/*
	test0("abcddcbc","bcddcb");
	test0("aaaaab","aaaaa");
	test0("baaaaa","aaaaa");
	test0("baaadaa","aadaa");
	test0("asdfghjkjl","jkj");*/
	return 0;
}