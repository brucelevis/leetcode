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
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int> > ret;
        vector<int>  tmp;
        sort(candidates.begin(),candidates.end());
        combinationSumCore(ret,tmp,candidates,0,target);
        return ret;
    }
    void combinationSumCore(vector<vector<int> > &ret,vector<int>  &tmp,vector<int> &candidates,int index,int target)
    {
    	if(index == candidates.size() || target == 0)
    	{
    		if(target == 0 && tmp.size() != 0)
    		{
    			if(find(ret.begin(),ret.end(),tmp) == ret.end())
    				ret.push_back(tmp);
    			//printvec(tmp,"ok");
    			return;
    		}
    		//printvec(tmp,"not ok");
    		return;
    	}
    	if(target-candidates[index] < 0)
    	{
    		//printf("index = %d -- A[%d]=%d\n",target,index,candidates[index]);
    		return;
    	}
    	//printf("---------------------%d %d\n",index,target);
    	//system("pause");
    		
    	//包含index 所指向元素     	
    	
    	//while(index > 0 && candidates[index] == candidates[index-1])	index++;
    	tmp.push_back(candidates[index]);
    	combinationSumCore(ret,tmp,candidates,index+1,target-candidates[index]);
    	tmp.pop_back();
    	//不包含当前元素 
    	combinationSumCore(ret,tmp,candidates,index+1,target);    
	}
};

void test0()
{
	int A[] = {10,1,2,7,6,1,5};
	vector<int > num(A,A+sizeof(A)/sizeof(int)); 
	Solution so;
	vector<vector<int> > out = so.combinationSum2(num,8);
	printvecvec(out,"out");
	if(1)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}/*
void test1()
{
	int A[] = {8,7,4,3};
	vector<int > num(A,A+sizeof(A)/sizeof(int)); 
	Solution so;
	vector<vector<int> > out = so.combinationSum2(num,11);
	printvecvec(out,"out");
	if(1)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}*/
int main()
{
	test0();
	//test1();
	return 0;
}