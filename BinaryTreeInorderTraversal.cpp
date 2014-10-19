/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/
#include <iostream>
#include <vector>
#include <stack> 
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
void printVector(vector<int> in,char* name)
{
	printf("%s size=%d\n",name,in.size());	
	for(int i = 0;i< in.size();i++)
    {
    	printf("%d  ",in[i]);
	}
	printf("\n");
}
#if 0
class Solution {
public://中序遍历，左中右 
    vector<int> inorderTraversal(TreeNode *root) {
		vector<int> out;
        if(root == NULL)      	return out;
        	
        vector<int> outleft = inorderTraversal(root->left);	
        vector<int> outright = inorderTraversal(root->right);
		out.insert(out.begin(),outright.begin(),outright.end());		
		out.insert(out.begin(),root->val);	
		out.insert(out.begin(),outleft.begin(),outleft.end());
        return out;
    }
};
#elif 1//栈 ------------赞！！！！ 
class Solution {
public://中序遍历，左中右 
    vector<int> inorderTraversal(TreeNode *root) {
		vector<int> out;
        stack<TreeNode *> stk;
       	TreeNode *p = root;
       	while(!stk.empty() || p)
       	{
       		if(p != NULL)
       		{
       			stk.push(p);
       			p = p->left;
  			}
  			else
  			{
				p = stk.top();
				stk.pop();
				out.push_back(p->val);
				p = p->right;
  			}
  		}
       
        return out;
    }
};
#endif 
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
	vector<int> out = so.inorderTraversal(&node1);
	
	int tmp[7] = {4,2,5,1,6,3,7};
	
	int i = 0;
	for(i = 0;i<7 && i<out.size();i++)
	{
		if(out[i] != tmp[i])
		{
			break;
		}
	}
	if(i == 7)
		printf("---------------------passed\n");
	else
		printf("---------------------failed\n");	
}
int main()
{
	test0();
}
