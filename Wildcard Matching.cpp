/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
    	const char *ss = s;
    	const char *star = NULL;
    	
    	while(*s)
    	{
    		if(*p == '?' || *p == *s) {s++;p++;continue;}
    		if(*p == '*') {star = p++;ss=s;continue;}
    		if(star){p = star + 1;s = ++ss;continue;}/////////////////////
    		return false;
		}
		while(*p == '*') p++;
		return !*p;
    }
};
void test0(char *s,char *p,bool ret)
{
	Solution so;
	if(so.isMatch(s,p) != ret)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	test0("aa","a",false);
	test0("aa","aa",true);
	test0("aaa","aa",false);
	test0("aa", "*",true);
	test0("aa", "a*",true);
	test0("ab", "?*",true);
	test0("aab", "c*a*b",false);
	return 0;
}