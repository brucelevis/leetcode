/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;
//这里需要注意 *代码0个时表示前面那一个是无效的。 
class Solution {
public:
   bool isMatch(const char *s, const char *p) {
    //assert(s && p);
    if (*p == '\0') return *s == '\0';

    // next char is not '*': must match current character
    if (*(p+1) != '*') {
        //assert(*p != '*');
        return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);//在进行s+1时要保证s不是空 
    }
	
    // next char is '*'
    while ((*p == *s) || (*p == '.' && *s != '\0')) {
        if (isMatch(s, p+2)) return true;
        s++;
    }
    //出循环的条件是 *p！=*s && （*p ！= '.' || *s == '\0'） 
    return isMatch(s, p+2);//*p 后面那个 *表示 0 
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
	test0("aa", "a*",true);
	test0("aa", ".*",true);
	test0("ab", ".*",true);
	test0("aab", "c*a*b",true);
	test0("ab", ".*c",false);
	test0("ab", "ab.",false);//‘.’匹配任意单个字符，‘*’匹配0个或多个前一字符。如果匹配整个串返回true。
	return 0;
}