/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;

void printstring(string s,int start,int end)
{
	for(int i = start;i<=end;i++)
		cout<<s[i];
	cout<<endl; 
}

#if 1
class Solution {
public:
    int numDecodings(string s) {
    	if(s.size() == 0) return 0;
    	vector<int> sum(s.size(),-1);
        //return numDecodingsCore(s,0,sum);
        for(int i = s.size()-1;i>=0;i--)
        {
        	if(s[i]<= '9' && s[i]>'0') //所有位都必须是 1-9     注意对0的处理 
			{
				if(i == s.size()-1)
					sum[i] = 1;
				else
				{
					if((s[i]-'0')*10+s[i+1]-'0' <= 26)
					{ 
						if(i == s.size()-2)
							sum[i] = sum[i+1]+ 1; 
						else
							sum[i] = sum[i+1]+ sum[i+2];
					} 
					else
						sum[i] = sum[i+1];
				}
			}
			else if(s[i] == '0')
			{
				sum[i] = 0;  
			}
			else
				return 0;
				    	
		}
		return sum[0];
    }
};
#elif 1

#endif
void test0()
{
	Solution so;
	
	if(so.numDecodings("27") != 1)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
	
	if(so.numDecodings("01") != 0)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
		
	if(so.numDecodings("10") != 1)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
	
	if(so.numDecodings("110") != 1)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
		
	if(so.numDecodings("101") != 1)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
	/*
	if(so.numDecodings("1212") != 5)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
		
	if(so.numDecodings("4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948") != 5)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
		
	if(so.numDecodings("4673351343232714528787622144828949686814115978657763689251918941228645575658338815495647817194659970") != 5)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
	*/
	
}
int main()
{
	test0();
	return 0;
}