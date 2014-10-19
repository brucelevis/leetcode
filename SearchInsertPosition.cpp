#include <iostream>

using namespace std;

#if 0 
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
    	if(n == 0)	return 0;
        if(n == 1)
        {
        	if(A[0] < target) 	return 1;
        	else 				return 0;
		}
		int mid = n/2;
		if(A[mid]<target)//目标在后半部分 
		{
			if(mid + 1 < n)
				return mid + 1 + searchInsert(&A[mid + 1],n-mid-1,target);
			else
				return n; 
		}
		else if(A[mid]>target)
				return searchInsert(&A[0],mid,target);
		else
			return mid;
    }
};
#elif 1
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
    	if(n == 0)	return 0;
		int start = 0, end = n - 1;
		while(start <= end)
		{
			int mid = (start + end)/2;
			if(A[mid]<target)
				start = mid + 1;
			else if(A[mid]>target)
				end = mid - 1;
			else 
				return mid;
		}
		return start;					//这一点需要理解透彻 
    }
};
#endif
void test0()
{
	int a[] = {1,3,5,6}; 
	int n = 4;
	int target = 5;
	int expected = 2;
	Solution so;
	if(so.searchInsert(a,n,target) == expected)
		printf("---------------------passed\n");
	else
		printf("---------------------failed\n");	
}
void test1()
{
	int a[] = {1,3,5,6}; 
	int n = 4;
	int target = 2;
	int expected = 1;
	Solution so;
	if(so.searchInsert(a,n,target) == expected)
		printf("---------------------passed\n");
	else
		printf("---------------------failed\n");	
}
void test2()
{
	int a[] = {1,3,5,6}; 
	int n = 4;
	int target = 7;
	int expected = 4;
	Solution so;
	if(so.searchInsert(a,n,target) == expected)
		printf("---------------------passed\n");
	else
		printf("---------------------failed\n");	
}
void test3()
{
	int a[] = {1,3,5,6}; 
	int n = 4;
	int target = 0;
	int expected = 0;
	Solution so;
	if(so.searchInsert(a,n,target) == expected)
		printf("---------------------passed\n");
	else
		printf("---------------------failed\n");	
}
void test4()
{
	int a[] = {1,3}; 
	int n = 2;
	int target = 0;
	int expected = 0;
	Solution so;
	if(so.searchInsert(a,n,target) == expected)
		printf("---------------------passed\n");
	else
		printf("---------------------failed\n");	
}
int main()
{
	test0();
	test1();
	test2();
	test3();
	test4();
	return 0;
}
 