#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int i = 0, ret = 0;
        for(i = 0;i<n;i++)
        {
        	ret ^= A[i];
		}
		return ret;
    }
};

void test0()
{
	int A[] = {1,2,3,4,5,6,1,2,3,4,5};
	Solution so;
	int a = so.singleNumber(A,11);
	if(a != 6)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	test0();
	return 0;
}


 