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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
         
        const char* star=NULL;
        const char* ss=s; 
        while (*s){
            if ((*p=='?')||(*p==*s)){s++;p++;continue;}
            if (*p=='*'){star=p++; ss=s;continue;}
            if (star){ p = star+1; s=++ss;continue;}//如果不匹配，就是从*后面一个重新开始重新匹配 这里要理解透*代表任意个字符应该如何处理。 
            return false;
        }
        while (*p=='*'){p++;}
        return !*p;
    }
};
void test0(char *str,char *p,bool ret)
{
	Solution so;
	
	if(so.isMatch(str,p) != ret)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	test0("abcdefga","a?*gb",false);
	//test0("abcdefga","a?*ga",true);
	return 0;
}