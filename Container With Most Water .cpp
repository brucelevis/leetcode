#include <iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
    	int size = height.size();
    	if(size < 2)	return 0;	
        int maxLine = height[0],minLine = height[0];
		int maxV = 0;
		for(int i = 1;i<size;i++)
		{
			if(height[i]>minLine)
				
		}
		 
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}