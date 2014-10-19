/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    // Divide two unsigned int once, using binary divide method.
    unsigned int unsigned_divide_once(unsigned int &dividend, unsigned int divisor)
    {
        if (dividend < divisor)
        {
            dividend = 0; // Update dividend.
            return 0;
        }
 
        unsigned int result = 1;
 
        while (divisor < dividend)
        {
            divisor <<= 1;
            result <<= 1;
        }
 
        if (divisor != dividend)
        {
            divisor >>= 1;
            result >>= 1;
        }
 
        dividend -= divisor;
 
        return result;
    }
 
    int divide(int dividend, int divisor) 
    {
        if (divisor == 0) throw 1;
 
        bool negative = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);
        unsigned int udividend = dividend < 0 ? -dividend : dividend;
        unsigned int udivisor = divisor < 0 ? -divisor : divisor;
        unsigned int uresult = 0;
 
        while (udividend != 0)
        {
            uresult += unsigned_divide_once(udividend, udivisor);
        }
 
        return negative ? -(int)uresult : (int)uresult;
    }
};

void test0()
{
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