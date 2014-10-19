/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;
void printvec(vector<string > A, char *name)
{
	printf("%s:\n",name);
	for(int i = 0;i<A.size();i++)
	{
		printf("%13d:",i);
		cout<<A[i]<<"|"<<endl;
	}
	printf("\n");
}

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ret;
		int size = words.size();
        if(size < 1)	return ret;
		int sum = 0, start = 0, end = 0;
        
        for(end = 0;end<size;end++)
        {
        	sum = sum + words[end].size()+1;//加一个空格的空间 
        	if(sum < L+1)	continue;
        	
			if(sum > L+1)
			{
				sum -= (words[end].size()+1);	
				end--;			
			}
			int wordnum = end-start+1;
			sum =L + wordnum - sum;//算出一共要添多少个空格 
			wordnum -= 1;//间隔数为单词数-1 
			string tmpstr = "";
			if(wordnum>0)////////////////////////////////////////
			{
				int slots = sum/wordnum;
				int tmpnum = sum%wordnum;//计算出需要多一个空格的数目
				
				while(tmpnum>0)
				{
					wordnum--;
					tmpnum--;
					string s(slots+1,' ');
					tmpstr+=words[start++] + s;
				} 
				while(wordnum>0)
				{
					wordnum--;
					string s(slots,' ');
					tmpstr+=words[start++] + s;
				} 
			}			
			tmpstr += words[start++];
			string s(L-tmpstr.size(),' ');//////////////////////////////////////////////////
			tmpstr += s;
			ret.push_back(tmpstr);
			sum = 0;/////////////////////////////////////////////////
		}
		
		if(sum >0)
		{
			int wordnum = end-start;
			string tmpstr = "";
			//wordnum -= 1;//间隔数为单词数-1 
			while(wordnum>0)
			{
				wordnum--;
				tmpstr+=words[start++] + " ";
			} 
			//printf("l=%d sum=%d\n",L,sum);
			string s(L-sum,' ');
			tmpstr += s;
			ret.push_back(tmpstr);
		}
		
        return ret;
    }
};


void createStringVec(vector<string> &words,char in[][100], int n)
{
	for(int i=0;i<n;i++)
	{
		string str(in[i]);
		words.push_back(str);
	}	
}
void test(char in[][100],int n,int L)
{	
	vector<string> words;	
	createStringVec(words,in,n);
	printvec(words,"words0");
	Solution so;
	vector<string> out = so.fullJustify(words,L);
	printvec(out,"out0");
}
void test0()
{
	char in[][100] = {"This", "is", "an", "example", "of", "text", "justification."};
	test(in,3,16);
}
void test1()
{
	char in[][100] = {"This", "is", "an", "example", "of", "text", "justification."};
	test(in,4,16);
}
void test2()
{
	char in[][100] = {"This", "is", "an", "example", "of", "text", "justification."};
	test(in,7,16);
}
void test3()
{
	char in[][100] = {"This", "is", "an", "example", "of", "text", "justification."};
	test(in,7,18);
}
void test4()
{
	char in[][100] = {"This", "is", "an", "example", "of", "text", "justification."};
	test(in,7,14);
}
void test5()
{
	char in[][100] = {};
	test(in,0,0);
}


int main()
{	
	//test0();
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}