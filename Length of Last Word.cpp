/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = 0, lastlen = 0;
		while(*s)
        {
        	if(*s != ' ')
        		len++,lastlen = len;
      		else
      			len = 0;
			s++;
		}
        return lastlen;
    }
};

void test0()
{
	Solution so;
	
	if(so.lengthOfLastWord("Hello World") != 5)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	test0();
	return 0;
}