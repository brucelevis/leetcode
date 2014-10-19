/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once.
		int total = 0;
		int currentgas = 0; 
		int startpoint = -1;
		int sz = gas.size();
		for(int i = 0; i < sz; i++)
		{
			currentgas += gas[i] - cost[i];
			total += gas[i] - cost[i];
			if(currentgas < 0)
			{
				startpoint = i;
				currentgas = 0;
			}
		}
		return total >= 0 ? startpoint+1 : -1;
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