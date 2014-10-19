/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        //if((x < 0.00000000001 || x) && n<0) return 0;
        
        double ret = powUnsigned(x,abs(n));
        if(n < 0)
        	ret = 1/ret;
       	return ret;
    }
    double powUnsigned(double x,unsigned int n)
    {
    	if(n == 0)	return 1;
		if(n == 1)  return x;
		double ret = powUnsigned(x,n>>1);
		ret *= ret;
		if((n & 0x1) == 1)
			ret *= x;
		return ret;
	}
};

void test0()
{
	if(1)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	test0();
	return 0;
}