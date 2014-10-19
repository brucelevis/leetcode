#include <iostream>
using namespace std;

#if 1
class Solution {  
public:  
    int maxSubArray(int A[], int n) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        int sum = A[0], max = A[0];  
        for (int i = 1; i < n; i++) {  
            sum = sum < 0 ? A[i] : sum + A[i];  
            max = sum > max ? sum : max;  
        }  
        return max;  
    }  
};  
#elif 1//自己写的，数据大时就会出问题 
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int *sum = new int[n];
        for(int i = 0;i<n;i++)
        	sum[i] = 0; 
       	
        int max_sum = 0;
        for(int i = 0;i<n;i++)
        {
        	for(int j = n-1;j>0;j--)
        	{
	        	if(i>=j)
	        	{
	        		sum[j]=sum[j-1]+A[i];
	        		if(sum[j] > max_sum) max_sum = sum[j];
	        	}
        	}
        	sum[0] = A[i];
        	if(sum[0] > max_sum) max_sum = sum[0];
        	/*
        	printf("%4d:",A[i]);
        	for(int k = 0;k<n;k++)
        	{
        		printf("%4d,",sum[k]);
			}
			printf("\n");
			*/
		}
        
        delete [] sum;
        return max_sum;
    }
};
#endif 
void test0()
{
	int A[] = {0,1,2,3,4,5,6,7,8,9};
	Solution so;
	if(so.maxSubArray(A,10) != 45)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
void test1()
{
	int A[] = {-2,1,-3,4,-1,2,1,-5,4};
	Solution so;
	if(so.maxSubArray(A,9) != 6)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}

int main(int argc, char *argv[])
{
	test0();
	test1();
	return 0;
}
