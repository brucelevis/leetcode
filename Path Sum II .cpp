#include <iostream>
#include <vector>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
    	vector<vector<int> > ret;
        if(root == NULL)	ret;
        vector<int> tmp;
        pathSumCore(ret,tmp,root,sum);
        return ret;
    }
    void pathSumCore(vector<vector<int> > &ret,vector<int> &tmp, TreeNode *root,int sum)
    {
    	tmp.push_back(root->val);
    	//printf("root = %d\n",root->val);
    	if(root->left == NULL && root->right == NULL && sum == root->val)
		{
			ret.push_back(tmp);
			tmp.pop_back();
			return;
		}//如果右为且sum = 0 返回true 
    	if(root->left)
			pathSumCore(ret,tmp,root->left,sum-root->val);		  
		if(root->right)
			pathSumCore(ret,tmp,root->right,sum-root->val);
		tmp.pop_back();
		return;	
	}
};

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
/*功能测试*/
void test0()
{
/*
				1
		2				3
	4		5		6		7
*/ 
	TreeNode node1(1);
	TreeNode node2(2);
	node1.left = &node2;
	
	Solution so;
	vector<vector<int> > out = so.pathSum(&node1,0);
	
	printvecvec(out,"out");
	
	if(7 == 7)
		printf("---------------------passed\n");
	else
		printf("---------------------failed\n");	
}

int main(int argc, char *argv[])
{
	test0();
	return 0;
}