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
        vector<int> maxback(prices.size(),0);
        vector<int> maxfont(prices.size(),0);
        
        int minprice = INT_MAX;
        int maxprice = 0;
        int maxPro = 0;
        for(int i = 0;i<prices.size();i++)
        {
            if(prices[i]<minprice) minprice = prices[i];
            if(prices[i] - minprice > maxPro) maxPro = prices[i] - minprice;
            maxfont[i] = maxPro;
        }
        maxPro = 0;
        for(int i = prices.size()-1;i>=0;i--)
        {
            if(prices[i]>maxprice) maxprice = prices[i];
            if(maxprice - prices[i] > maxPro) maxPro = maxprice - prices[i];
            maxback[i] = maxPro;
        }
        maxPro = 0;
        for(int i = 0;i<prices.size();i++)
        {
            if(maxback[i] + maxfont[i] > maxPro)
                maxPro = maxback[i] + maxfont[i];
        }
        return maxPro;
    }
};
#elif 1

#endif
void test0()
{
	int A[] = {6,1,3,2,4,7};
	vector<int > num(A,A+sizeof(A)/sizeof(int)); 
	
	Solution so;
	if(so.maxProfit(num) != 7)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
void test2()
{
	int A[] = {1,2,4};
	vector<int > num(A,A+sizeof(A)/sizeof(int)); 
	
	Solution so;
	if(so.maxProfit(num) != 3)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
void test1()
{
	int A[] = {1,8,1,7,2,9};
	vector<int > num(A,A+sizeof(A)/sizeof(int)); 
	
	Solution so;
	if(so.maxProfit(num) != 15)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	test0();
	return 0;
}