/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maxPro = 0;
        for(int i = 1;i<prices.size();i++)
        {
            if(prices[i]>prices[i-1])
                maxPro += (prices[i]-prices[i-1]);
        }
        return maxPro;
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