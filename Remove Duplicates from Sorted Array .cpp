#include <iostream>
using namespace std;

/*
看清返回值是什么？？？ 
*/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
    	if(n<=1)	return n;
        int head = 0, tail = 1;
        while(tail < n)
        {
        	if(A[head] == A[tail])
        	{
        		tail++;
			}
			else
			{
				head++;
				A[head] = A[tail];
				tail++;
			}
		}
		return head+1;
    }
};
void check(int A[],int B[], int len, int except)
{
	int i = 0;
	for(;i<len;i++)
	{
		printf("%d:%d-%d\n",i,A[i],B[i]);
		if(A[i] != B[i])
			break;
	}
	if(i != len || len != except)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
void test0()
{
	int A[] = {0,1,2,3,3,3,4,5,5,5,6,7,8,9};
	int B[] = {0,1,2,3,4,5,6,7,8,9};
	Solution so;
	int len = so.removeDuplicates(A,14);
	check(A,B,len,10);	
}
int main()
{
	test0();
	return 0;
}
