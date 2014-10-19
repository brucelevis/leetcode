/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string str;
        vector<string> ret;
        generateParenthesisCore(ret,"",0,0,n);
        return ret;
    }
    void generateParenthesisCore(vector<string> &ret,string str,int lnum,int rnum,const int n)
    {
   		if(lnum > n)	return;
    	if(lnum + rnum == 2*n)
    		ret.push_back(str);
   		
		generateParenthesisCore(ret,str+'(',lnum + 1,rnum,n);
		if(lnum > rnum)
			generateParenthesisCore(ret,str+')',lnum,rnum+1,n);
	}
};

void printvecvec(vector<string > A)
{
	for(int i = 0;i<A.size();i++)
	{
		printf("%13d:",i);
		cout<<A[i]<<endl;
	}
	printf("\n");
}
void test0()
{
	Solution so;
	printvecvec(so.generateParenthesis(3));
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