/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {//要考虑负数 
        int ret = 0;
        if(x<0)	return false;
        int tmpx = x;
        while(tmpx)
        {
        	ret = ret*10 + tmpx%10;
        	tmpx /= 10;
		}
		return (x==ret);
    }
};


void test0()
{
	Solution so;
	if(!so.isPalindrome(123321))
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
	if(!so.isPalindrome(12331))
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	test0();
	return 0;
}