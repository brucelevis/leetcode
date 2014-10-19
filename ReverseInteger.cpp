#include <iostream>
#include <stack>

using namespace std;


class Solution {
public:
    int reverse(int x) {
    	int sign = 1;
    	if(x < 0)	x = -x,sign = -1;
    	int ret = 0;
    	while(x>0)
    	{
    		ret = ret * 10 + (x%10);
    		x /= 10;
		}    	
        return ret*sign;
    }
};

void check(int x,int expected)
{
	Solution so;

	if(expected == (so.reverse(x)))
		printf("---------------------passed%5d--%5d \n",expected,(so.reverse(x)));
	else
		printf("---------------------failed%5d--%5d \n",expected,(so.reverse(x)));
}

int main()
{
	check(123,321);
	check(0,0);
	check(1,1);
	check(-123,-321);
	check(+123,321);
	return 0;
} 
