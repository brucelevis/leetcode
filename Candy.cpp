/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;

void printvec(vector<int > A, char *name)
{
	printf("%s:",name);
	for(int i = 0;i<A.size();i++)
	{
		printf("%d,",A[i]);
	}
	printf("\n");
}

class Solution {
public:
    int candy(vector<int> &ratings) {
        int mincandy = 0;
        int size = ratings.size();
        vector<int > candynum(size,1);
        int num = 0, ptr = 0;
        //printvec(candynum,"1");
       
       	for(int i=1;i<size;i++)
       	{
       		if(ratings[i]>ratings[i-1])
       			candynum[i] = candynum[i-1]+1;
 			else
 				candynum[i] = 1;
	   	}
	   	for(int i=size-2;i>=0;i--)
       	{
       		if(ratings[i]>ratings[i+1])
       			candynum[i] = max(candynum[i+1]+1,candynum[i]);
	   	}
	   	
	   	
        //printvec(candynum,"ret");
        for(int i=0;i<size;i++)
        	mincandy+=candynum[i];
        return mincandy;
    }
};


void test0(int a[],int n,int ret)
{
	Solution so;
	vector<int > ratings(a,a+n);
	printvec(ratings,"ratings");
	int out = so.candy(ratings);
	if(out != ret)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	int a[] = {1,2,3,4,5,6};
	test0(a,6,21);
	int a1[] = {2,1};
	test0(a1,2,3);
	return 0;
}