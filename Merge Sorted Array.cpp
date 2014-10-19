#include <iostream>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int end = m+n-1;
        int i = m-1, j = n-1;
        while(i >= 0 && j >= 0)
        {
        	if(A[i] > B[j])
        		A[end--] = A[i--];
			else
				A[end--] = B[j--];
		}
		if(i<0)
			while(j >= 0)
				A[end--] = B[j--];	
		if(j<0)
			while(i >= 0)
				A[end--] = A[i--];	
    }
};

void check(int A[],int B[], int len)
{
	int i = 0;
	for(;i<len;i++)
	{
		if(A[i] != B[i])
			break;
	}
	if(i != len)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}

void test0()
{
	int A[100] = {1,3,5,7,9};
	int B[100] = {2,4,6,8,10};
	int C[100] = {1,2,3,4,5,6,7,8,9,10};
	Solution so;
	so.merge(A,5,B,5);
	check(A,C,10);
}
int main()
{
	test0();
	return 0;
}

