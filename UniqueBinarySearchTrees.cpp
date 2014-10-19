/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/
#include <iostream>
#include <vector>
#include <stack> 
using namespace std;

#if 0 
class Solution {
public:
    int numTrees(int n) {
    	vec.resize(n+1);
    	vec[0] = 1;
    	return numTreesCore(n);
    }
    int numTreesCore(int n)
    {
    	if(vec[n]>0)	return vec[n];        
       	int num = 0;
       	for(int i=0;i<n;i++)
       		num += numTreesCore(i)*numTreesCore(n-1-i);
        vec[n] = num;
        return num;
	}
private:
	vector<int> vec;
};
#elif 1
class Solution {
public:
    int numTrees(int n) {
    	vec.resize(n+1);
    	if(n >0)vec[0] = 1;
		if(n >0)vec[1] = 1;
		if(n >1)vec[2] = 2;
    	if(n >2)
	       	for(int i=3;i<=n;i++)
	       	{
	       		vec[i] = 0;				//这里需要初始化 
	       		for(int j = 0;j<i;j++)
	       			vec[i] += vec[j]*vec[i-1-j];
	       	}
    	return vec[n];
    }
private:
	vector<int> vec;
};

#endif
void check(int x,int expected)
{
	if(x==expected)
		printf("---------------------passed\n");
	else
		printf("---------------------failed\n");	
}
int main()
{
	printf("main begin\n");
	Solution so;
	//check(so.numTrees(1),1);
	//check(so.numTrees(2),2);
	check(so.numTrees(3),5);
	check(so.numTrees(4),14);
//	check(so.numTrees(5),0);
	return 0;
}
/*

class Solution {
public:
    int numTrees(int n) {
    	vec.resize(n+1);
    	return numTreesCore(n);
    }
    int numTreesCore(int n)
    {
    	if(vec[n]>0)
		{  	
			//printf("*vec[%d] = %d\n",n,1);
			return vec[n];
		}
        if(n == 0)	
		{
			vec[n] = 1;
			//printf("0vec[%d] = %d\n",n,1);
			return 1;
		}        
       	int num = 0;
       	for(int i=0;i<n;i++)
       	{
       		num += numTreesCore(i)*numTreesCore(n-1-i);
       		//printf("2vec[%d] = %d\n",n,num);
	   	}
	   	//printf("3vec[%d] = %d\n",n,num);
        vec[n] = num;
        return num;
	}
private:
	vector<int> vec;
};
*/

 