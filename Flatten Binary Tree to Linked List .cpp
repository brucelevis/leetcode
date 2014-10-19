/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    void flatten(TreeNode *root) {
        if(root == NULL)
        	return;
       	TreeNode *p = root;					//就是记录上一个弹出的结点
		stack<TreeNode *>  treenodeStack;
       	treenodeStack.push(root);
        while(!treenodeStack.empty())
		{
			TreeNode *cur = treenodeStack.top();//增加一个记录点
			treenodeStack.pop();
			if(cur->right != NULL)	treenodeStack.push(cur->right)/*,printf("lpush = %d\n",cur->right->val)*/;
			if(cur->left != NULL)	treenodeStack.push(cur->left)/*,printf("rpush = %d\n",cur->left->val)*/;
			cur->left = cur->right = NULL;
			if(cur != root)
			{
				p->right = cur;
				p = p->right;
			}
		} 
    }
};

void CheckList(TreeNode *head,int arr[], int n)
{
	int i = 0;
	for(i = 0;i<n && head != NULL;i++,head=head->right)
	{
		if(head->val != arr[i])
			break;
	}
	if(i != n)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
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
	so.flatten(&node1);
	
	int tmp[7] = {1,2,4,5,3,6,7};
	CheckList(&node1,tmp,7);

}
int main()
{
	test0();
	return 0;
}