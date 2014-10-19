/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;

#if 1
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maxPro = 0;
        int maxprice = 0;
        for(int i = prices.size()-1;i>=0;i--)
        {
            if(prices[i]>maxprice)  maxprice = prices[i];
            if(maxprice - prices[i] > maxPro)  maxPro = maxprice - prices[i];
        }
        return maxPro;
    }
};
#elif 1
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maxPro = 0;
        int minprice = INT_MAX;
        for(int i = 0;i<prices.size();i++)
        {
            if(prices[i]<minprice)  minprice = prices[i];
            if(prices[i] - minprice > maxPro)  maxPro = prices[i] - minprice;
        }
        return maxPro;
    }
};
#endif
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