/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while(i<j)
        {
        	if(!isalnum(s[i])) 		i++;////////////////////////使用isalnum 
        	else if(!isalnum(s[j])) j--;
        	else
        	{
        		if(tolower(s[i]) != tolower(s[j]))
        			return false;
       			else
				{i++;j--;} 
			}
		}
		return true; 
    }
};

void test0(string s,bool ret)
{
	Solution so;
	
	if(so.isPalindrome(s) != ret)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	test0("A man, a plan, a canal: Panama",true);
	test0("race a car",false);
	return 0;
}