/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {  
public:  
    int sqrt(int x) {  
        if(x >= 0)  
        {  
            long long left = 0;  
            long long right = x;  
            long long mid = 0;  
            while(left <= right)  
            {  
                //mid = left + (right-left)/2;  
                mid = (left + right)/2;
                long long temp = (long long)mid*mid;  
                if(temp < mid)  
                    right = mid - 1;  
                else if(temp == x)  
                    return mid;  
                else if(temp < x)  
                    left = mid+1;  
                else  
                    right = mid-1;  
            }  
            return right;  
        }  
        return -1;  
    }  
};  

#if 0
class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        double ans = x;
        
        while(abs(ans * ans - x) > 0.0001)
        {
            ans = (ans + x / ans) / 2;
        }
        
        return (int)ans;
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