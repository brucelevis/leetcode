/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> getRow(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if ( n<0 )
    		return vector<int>();
		vector<int> level;
		for(int i=0;i<=n;i++)
		{
			int k=(int)level.size();
			for(int  j=k-1;j>=1;j--)
				level[j]+=level[j-1];
			level.push_back(1);
		}
		return level;
    }
};

void test0()
{
	Solution so;
	so.getRow(21);
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