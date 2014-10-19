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
    vector<int> grayCode(int n) {    	
    	vector<int> ret;
    	ret.push_back(0);
    	if(n == 0)	return ret;    	
    	ret.push_back(1);
        int i = 2 ,sum = 2;
        //printvec(ret,"0");
        //printf("%d--%d\n",i,n);
        while(i++ <= n)
        {
        	//printvec(ret,"1");
        	for(int j = sum-1;j>=0;j--)
        	{
        		ret.push_back(ret[j] + sum);
			}
			sum *= 2;
			//printvec(ret,"2");
		}
		return ret;
    }
};

void chechbit(vector<int> A)
{
	for(int i = 0;i<A.size()-1;i++)
	{
		printf("0x%8X\n",abs(A[i]-A[i+1]));
	}
	printf("\n");
}



int main()
{
	Solution so;
	vector<int> ret = so.grayCode(4);
	printvec(ret,"ret");
	chechbit(ret);
	return 0;
}
