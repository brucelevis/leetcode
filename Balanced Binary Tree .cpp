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
	
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if(root == NULL) return true;
        int height = 0;
        return treeHeight(root,height);
    }
private:
	bool treeHeight(TreeNode *root, int &height)
	{
		if(root == NULL)
		{	
			height = 0;
			return true;
		}
		int hL = 0, hR = 0;
		bool bl = treeHeight(root->left, hL);
		bool br = treeHeight(root->right,hR);
		height = hL>hR?hL + 1:hR + 1;
		
		//平衡的条件是左右都是平衡且高度相差不超过1 
		return (bl && br && abs(hL - hR) < 2);
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
	bool out = so.isBalanced(&node1);

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
	TreeNode node3(3);
	TreeNode node4(4);
	TreeNode node5(5);
	TreeNode node6(6);
	TreeNode node7(7);
	node1.left = &node2;
	node1.right = &node3;
	
	node2.left = &node4;
	node3.right = &node5;
	
	node4.left = &node6;
	node5.right = &node7;
	
	Solution so;
	bool out = so.isBalanced(&node1);

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

