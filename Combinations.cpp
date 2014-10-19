#include <iostream>
#include <vector>
using namespace std;

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


#if 0//这个方法不是特别好 
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
    	vector<vector<int> > ret;
        if(n == 0 || k == 0)	return ret;
        if(n == k)
        {
        	vector<int> tmp;
        	for(int i = 1;i<=k;i++)
        		tmp.push_back(i);
			ret.push_back(tmp);
			//printvecvec(ret,"0");
			return ret;
		}
		if(k==1)
		{
			vector<int> tmp;
        	for(int i = 1;i<=n;i++)
        	{
        		tmp.push_back(i);
				ret.push_back(tmp);
				tmp.clear();
        	}
        	//printvecvec(ret,"1");
			return ret;
		}
		ret = combine(n-1, k);
		//printvecvec(ret,"2");
		vector<vector<int> > ret1 = combine(n-1, k-1);
		for(int i = 0;i<ret1.size();i++)
			ret1[i].push_back(n);
		//printvecvec(ret1,"3");
		ret.insert(ret.begin(),ret1.begin(),ret1.end());
		//printvecvec(ret,"4");
		return ret;
    }
};
#elif 1
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
    	vector<vector<int> > ret;
        vector<int> tmp(k);
        combineCore(1,k,1,n,tmp,ret);
        return ret;
    }
    void combineCore(int i,int k,int start,int n, vector<int> &tmp,vector<vector<int> > &ret)
    {
    	if(i == k+1)
		{	
			ret.push_back(tmp);
			return;
		}
    	for(int j = start;j<=n;j++)
    	{
    		tmp[i-1] = j;
    		combineCore(i+1,k,j+1,n,tmp,ret);
		}
	}
};
#endif
void test0()
{
	Solution so;
	printvecvec(so.combine(4,2),"");
}
int main(int argc, char *argv[])
{
	test0();
	return 0;
}