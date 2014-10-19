#include <iostream>

using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(root == NULL)	return false;
        
        if(root->left)
			if(hasPathSum(root->left, sum - root->val))	return true;		  
		if(root->right)
			if(hasPathSum(root->right, sum - root->val))	return true;
		if(root->left == NULL && root->right == NULL && sum == root->val)	return true;//如果右为且sum = 0 返回true 
		return false;		
    }
};

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
	TreeNode node3(3);
	TreeNode node4(4);
	TreeNode node5(5);
	TreeNode node6(6);
	TreeNode node7(7);
	node1.left = &node2;
	node1.right = &node3;
	
	node2.left = &node4;
	node2.right = &node5;
	
	node3.left = &node6;
	node3.right = &node7;
	
	Solution so;
	if(so.hasPathSum(&node1,8))
		printf("---------------------passed\n");
	else
		printf("---------------------failed\n");
	
	if(so.hasPathSum(&node1,7))
		printf("---------------------passed\n");
	else
		printf("---------------------failed\n");
	
	if(!so.hasPathSum(&node1,6))
		printf("---------------------passed\n");
	else
		printf("---------------------failed\n");	
}


int main(int argc, char *argv[])
{
	test0();
	return 0;
}