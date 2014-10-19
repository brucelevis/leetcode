/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void printvec(vector<int > A, char *name)
{
	printf("%s:",name);
	for(int i = 0;i<A.size();i++)
	{
		printf("%d",A[i]);
	}
	printf("\n");
}
#if 1//第3遍
class Solution {
public:
    int longestValidParentheses(string s) {
        int size = s.size();
        if(size < 2) return 0;///////////////////////////特殊处理 
        vector<int> longest(size,0);
        int maxl = 0;
        for(int i = size-2;i>=0;i--)////////////////从size-2开始 
        {
            if(s[i] == '(')
            {
                int j = i+1+longest[i+1];//去除本配好对的下一个符号
                if(j< size && s[j] == ')')
                {
                    longest[i] = longest[i+1] + 2;//////////////////////////////////////    i+1
                    if(j+1<size)
                     longest[i] += longest[j+1];//加上下一个段
                }
                maxl = max(maxl,longest[i]);///////////////////////////////////////////// 更新 
            }
            //printf("%c i = %d, lo = %d, max = %d\n",s[i],i,longest[i],maxl);
        }
        return maxl;
    }
};
#elif 1 //2
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;///////////////////////////////
        
        int maxlen = 0, lastleft = -1;
        int i = 0;
        while(i<s.size())
        {
            if(s[i] == '(')
            {
                stk.push(i);
            }
            else if(s[i] == ')' && !stk.empty())
            {
                stk.pop();
                if(stk.empty()) maxlen = max(maxlen,i-lastleft);///////////////////////////////// 
                else            maxlen = max(maxlen,i-stk.top());
            }
            else
                lastleft = i;//////////////////////////////// 
            i++;////////////////////////////////////
        }
        return maxlen;
    }
};
#elif 1 
class Solution {
public:
    int longestValidParentheses(string s) {
        int size = s.size();
        stack<char> stk;
        vector<int > vec(size,0);
        int max = 0,tmpmax = 0;
        int leftflag = 0;
        int i = -1;
        while(++i<size)
        {	
        	if(s[i] == '(')
        	{
        		stk.push(s[i]);
        		leftflag = i;
        	}
       		else if(stk.size() > 0 && s[i] == ')')
       		{
       			vec[i] = 1;
       			while(vec[leftflag]) leftflag--;//这里没有充分使用栈。。 
       			vec[leftflag] = 1;
       			stk.pop();
       		}
		}
		for(int i = 0;i<size;i++)
		{
			if(vec[i])	
			{
				tmpmax++;
				if(tmpmax>max) max = tmpmax;
			}
			else
				tmpmax = 0;
		}
		//cout<<"    "<<s<<endl;
		//printvec(vec,"vec");
		return max;
    }
};
#endif 


void test0(string s,int exp)
{
	Solution so;
	int out = so.longestValidParentheses(s); 
	if(out != exp)
		printf("------------------------failed %d\n",out);
	else
		printf("------------------------passed %d\n",out);
}
int main()
{
//	test0("((((()()(((()()))",8);
	test0("()(())",6);
	return 0;
}