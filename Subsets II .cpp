/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;
#if 0
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > ret;
        vector<int> tmp;
        sort(S.begin(),S.end()); 
        subsetsWithDupCore(ret,0,S,tmp);
        return ret;
    }
    void subsetsWithDupCore(vector<vector<int> > &ret,int index,vector<int> &S,vector<int> &tmp)
    {
    	if(index == S.size())
    	{
    		if(find(ret.begin(),ret.end(),tmp) == ret.end())
    			ret.push_back(tmp);
    		return;
    	}
   		subsetsWithDupCore(ret,index+1,S,tmp);
   		tmp.push_back(S[index]);
   		subsetsWithDupCore(ret,index+1,S,tmp);
   		tmp.pop_back();
	}
};
#elif 1
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > ret;
        vector<int> tmp;
        sort(S.begin(),S.end()); 
        subsetsWithDupCore(ret,0,S,tmp);
        return ret;
    }
    void subsetsWithDupCore(vector<vector<int> > &ret,int index,vector<int> &S,vector<int> &tmp)
    {
    	if(index == S.size())
    	{
    		ret.push_back(tmp);
    		return;
    	}
    	for(int i = index;i<S.size();i++)
    	{
    		if(i!=index && S[i] == S[i-1])
    			continue;
    		tmp.push_back(S[i]);
   			subsetsWithDupCore(ret,i+1,S,tmp);
   			tmp.pop_back();
		}
		ret.push_back(tmp);
	}
};
#endif
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

void test0()
{
	int A[] = {1,2,2};
	vector<int > num(A,A+sizeof(A)/sizeof(int)); 
	Solution so;
 	vector<vector<int> > ret = so.subsetsWithDup(num);
 	
 	printvecvec(ret,"ret");
	if(1)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	test0();
	return 0;
}