/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

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
    int sumNumbers(TreeNode *root) {
        if(root == NULL) return 0;
		int sum = 0; 
		sumNumbersCore(root,sum);
		return sum;
    }
    void sumNumbersCore(TreeNode *root, int &sum)
    {
    	if(root == NULL)	return;
    	if(root->left == NULL && root->right == NULL )
    	{
    		sum = sum + root->val;
    		//printf("root%d = %d\n",root->val,sum);
    		return;
    	}
    	int left = (sum + root->val)*10;
    	if(root->left) 		sumNumbersCore(root->left,left);
   		else   				left = 0;
   		
    	int right = (sum + root->val)*10;
    	if(root->right)		sumNumbersCore(root->right,right);
   		else   				right = 0;
    	
    	sum = left + right;
    	//printf("root%d = %d\n",root->val,sum);
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
	int out = so.sumNumbers(&node1);
	printf("out = %d\n",out);
	if(out == 522)
		printf("---------------------passed\n");
	else
		printf("---------------------failed\n");	
}
/*功能测试*/
void test1()
{
/*
				1
		2(0)				3
	4		5		6		7
*/ 
	TreeNode node1(1);
	TreeNode node2(0);
	node1.left = &node2;
	
	Solution so;
	int out = so.sumNumbers(&node1);
	printf("out = %d\n",out);
	if(out == 10)
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