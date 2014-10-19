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
void printvec(vector<int > A)
{
	for(int i = 0;i<A.size();i++)
	{
		printf("%d,",A[i]);
	}
	printf("\n");
}

void printvecvec(vector<vector<int > > A, char *name)
{
	printf("%s\n",name);
	for(int i = 0;i<A.size();i++)
	{
		printf("%3d:",i);
		printvec(A[i]);
	}
	printf("\n");
}
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > ret;
        vector<int>  tmp;
        sort(candidates.begin(),candidates.end());
        combinationSumCore(ret,tmp,candidates,0,target);
        return ret;
    }
    void combinationSumCore(vector<vector<int> > &ret,vector<int>  &tmp,vector<int> &candidates,int index,int target) {
    	if(index == candidates.size() || target == 0) {
    		if(target == 0 && tmp.size() != 0) {
    			ret.push_back(tmp);
    			return;
    		}
    		return;
    	}
    	if(target-candidates[index] < 0) {
    		return;
    	}    	
    	tmp.push_back(candidates[index]);
    	combinationSumCore(ret,tmp,candidates,index,target-candidates[index]);
    	tmp.pop_back();
    	combinationSumCore(ret,tmp,candidates,index + 1,target);    
	}
};

void test0()
{
	int A[] = {2,3,6,7};
	vector<int > num(A,A+sizeof(A)/sizeof(int)); 
	Solution so;
	vector<vector<int> > out = so.combinationSum(num,7);
	printvecvec(out,"out");
	if(1)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
void test1()
{
	int A[] = {8,7,4,3};
	vector<int > num(A,A+sizeof(A)/sizeof(int)); 
	Solution so;
	vector<vector<int> > out = so.combinationSum(num,11);
	printvecvec(out,"out");
	if(0)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	//test0();
	test1();
	return 0;
}