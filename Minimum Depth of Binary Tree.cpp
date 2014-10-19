#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    int minDepth(TreeNode *root) {
    	if(root == NULL)	return 0;
        queue<TreeNode*> quTree;
        quTree.push(root);
        int levelSum = 1;
        int mimDep = 1;
        while(!quTree.empty())
        {
        	TreeNode *cur = quTree.front();
        	quTree.pop();
        	if(cur->left == NULL && cur->right == NULL)
        		return mimDep;
       		if(cur->left) quTree.push(cur->left);
       		if(cur->right) quTree.push(cur->right);
       		levelSum--;
       		if(levelSum == 0)
       		{
       			levelSum = quTree.size();
       			mimDep++;
		    }
		}
    }
};
 
 /*π¶ƒ‹≤‚ ‘*/
void test0()
{
/*
				1
		2				3
	4		5		6		
	 7
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
	node4.right = &node7;
	
	Solution so;
	int out = so.minDepth(&node1);
	
	
	if(out == 3)
		printf("---------------------passed\n");
	else
		printf("---------------------failed\n");	
}

int main(int argc, char *argv[])
{
	test0(); 
	return 0;
}