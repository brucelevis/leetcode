/*
���뻷��CFree 5.0
���͵�ַ��http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ret(n,vector<int> (n));
        int sum = 1;
        for(int i = 0;i<(n+1)/2;i++)
        	generateMatrixCore(ret,sum,i);
       	return ret;
    }
    void generateMatrixCore(vector<vector<int> > &ret,int &sum,int start)
    {//���ϵ����� 
    	int n = ret.size();
    	for(int i = start;i<n-start;i++)
    		ret[start][i] = sum++;
   		if(n - start*2 == 1) return;
   	//���ϵ�����	
   		for(int i = start+1;i<n-start;i++)
    		ret[i][n-start-1] = sum++;
	//���µ�����
        for(int i = n-start-2;i>= start;i--)
    		ret[n-start-1][i] = sum++;
	//���µ�����
		for(int i = n-start-2;i> start;i--)
    		ret[i][start] = sum++;
	}
};

void printvec(vector<int > A)
{
	for(int i = 0;i<A.size();i++)
	{
		printf("%3d,",A[i]);
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
	Solution so;
	int n = 4;
	vector<vector<int > > out = so.generateMatrix(n);
	printvecvec(out,"out");
	
}
int main()
{
	test0();
	return 0;
}