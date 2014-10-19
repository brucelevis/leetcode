/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/
#include <iostream>
using namespace std;
/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 /*
 左子树 中左右
 右子树 中右左
 遍历结果应该相同 
 **/
 
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(root == NULL) return true;
		return isMirror(root->left,root->right); 
    }
    bool isMirror(TreeNode *root0, TreeNode *root1)
    {
    	if(root0 == NULL || root1 == NULL)
    	{
    		if(root0 == NULL && root1 == NULL)	return true;
			else								return false;    	
		}
		if(root0->val != root1->val) 			return false;
		if(!isMirror(root0->left,root1->right)) return false;
		if(!isMirror(root1->left,root0->right)) return false;
		return true;
	}
};
 
 /*功能测试*/
void test0()
{
/*
				1
		2，2				3,2 
	4,3		5,4		6,4		7,3 
*/ 
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(2);
	TreeNode node4(3);
	TreeNode node5(4);
	TreeNode node6(4);
	TreeNode node7(3);
	node1.left = &node2;
	node1.right = &node3;
	
	node2.left = &node4;
	node2.right = &node5;
	
	node3.left = &node6;
	node3.right = &node7;
	
	Solution so;
	bool out = so.isSymmetric(&node1);

	if(out == true)
		printf("---------------------passed\n");
	else
		printf("---------------------failed\n");	
}
/*功能测试*/
void test1()
{
/*
				1
		2				3
	4						5		
6								7
*/ 
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(2);
	TreeNode node4(3);
	TreeNode node5(3);
	TreeNode node6(4);
	TreeNode node7(4);
	node1.left = &node2;
	node1.right = &node3;
	
	node2.left = &node4;
	node3.right = &node5;
	
	node4.left = &node6;
	node5.right = &node7;
	
	Solution so;
	bool out = so.isSymmetric(&node1);

	if(out == true)
		printf("---------------------passed\n");
	else
		printf("---------------------failed\n");	
}
int main()
{
	test0();
	test1();
	return 0;
}

