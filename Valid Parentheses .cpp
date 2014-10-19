/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int size = s.size();
        stack<char> stk;
        while(size--)
        {	
        	if(stk.size() == 0 || !ispair(stk.top(),s[size]))
        		stk.push(s[size]);
       		else
       			stk.pop();
		}
		return stk.empty();
    }
    bool ispair(char ch1,char ch2)
    {
    	return ((ch1 == ')' && ch2 == '(')||(ch1 == '}' && ch2 == '{')||(ch1 == ']' && ch2 == '['))	; 
	}
};


void test0()
{
	Solution so;
	
	if(!so.isValid("()()()()"))
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	test0();
	return 0;
}