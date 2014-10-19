#include <iostream>
#include <stack>
#include <queue>
using namespace std;
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
#if 0//递归法 	
//无论是深度还是广度，遍历一遍就可以了。 
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p == NULL || q == NULL)
		{
			//printf("return\n");
			if(p == q)	return true;
			else		return false;
		} 
		if(p->val == q->val)
		{
			//printf("%d\n",p->val);
			if(!isSameTree(p->left,q->left))	return false;
			if(!isSameTree(p->right,q->right))	return false;
			return true;
		}
		else 
		{
			//printf("%d--%d\n",p->val,q->val);
			return false;
		}
    }
};
#elif 1//广度优先遍历 
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p == NULL || q == NULL)
		{
			//printf("return\n");
			if(p == q)	return true;
			else		return false;
		} 
		queue<TreeNode*> pque, qque;
		pque.push(p),qque.push(q);
		TreeNode *tmpp, *tmpq; 
		while((!pque.empty()) && (!qque.empty()))
		{
			tmpp = pque.front(),tmpq = qque.front();	//能进循环的栈一定不是空，所以不用判断空 
			if(tmpp->val != tmpq->val)	return false;
				pque.pop(),qque.pop();
			
			if(tmpq->left != NULL && tmpp->left != NULL)		//左孩子要不都存在，要不都不存在 
				 pque.push(tmpp->left),qque.push(tmpq->left);
		 	else if((tmpq->left != NULL) || (tmpp->left != NULL))	
		 		return false;	
		 		
			if(tmpq->right != NULL && tmpp->right != NULL)		//右孩子要不都存在，要不都不存在 
				 pque.push(tmpp->right),qque.push(tmpq->right);
		 	else if((tmpq->right != NULL) || (tmpp->right != NULL))	
		 		return false;				 	
		} 
		if(pque.empty() && qque.empty())	return true;
		else								return false;
    }
};

#elif 1//深度优先 栈 
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p == NULL || q == NULL)
		{
			//printf("return\n");
			if(p == q)	return true;
			else		return false;
		} 
		stack<TreeNode*> pstk, qstk;
		pstk.push(p),qstk.push(q);
		TreeNode *tmpp, *tmpq; 
		while((!pstk.empty()) && (!qstk.empty()))
		{
			tmpp = pstk.top(),tmpq = qstk.top();	//能进循环的栈一定不是空，所以不用判断空 
			if(tmpp->val != tmpq->val)	return false;
				pstk.pop(),qstk.pop();
			
			if(tmpq->right != NULL && tmpp->right != NULL)		//右孩子要不都存在，要不都不存在 
				 pstk.push(tmpp->right),qstk.push(tmpq->right);
		 	else if((tmpq->right != NULL) || (tmpp->right != NULL))	
		 		return false;
		 		
			if(tmpq->left != NULL && tmpp->left != NULL)		//左孩子要不都存在，要不都不存在 
				 pstk.push(tmpp->left),qstk.push(tmpq->left);
		 	else if((tmpq->left != NULL) || (tmpp->left != NULL))	
		 		return false;		 	
		} 
		if(pstk.empty() && qstk.empty())	return true;
		else								return false;
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
	bool ret = so.isSameTree(&node1,&node1);
	
	if(ret)
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

	/*
				1
		2				3
	4		5		6
*/ 
	TreeNode nodeq1(1);
	TreeNode nodeq2(2);
	TreeNode nodeq3(3);
	TreeNode nodeq4(4);
	TreeNode nodeq5(5);
	TreeNode nodeq6(6);
	nodeq1.left = &nodeq2;
	nodeq1.right = &nodeq3;
	
	nodeq2.left = &nodeq4;
	nodeq2.right = &nodeq5;
	
	nodeq3.left = &nodeq6;
	
	Solution so;
	bool ret = so.isSameTree(&node1,&nodeq1);
	
	if(!ret)
		printf("---------------------passed\n");
	else
		printf("---------------------failed\n");	
}
/*功能测试*/
void test2()
{
	/*
				1
		2				3
	4		5		6
*/ 
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);
	TreeNode node4(4);
	TreeNode node5(5);
	TreeNode node6(6);
	node1.left = &node2;
	node1.right = &node3;
	
	node2.left = &node4;
	node2.right = &node5;
	
	node3.left = &node6;

	/*
				1
		2				3
	4		5		7
*/ 
	TreeNode nodeq1(1);
	TreeNode nodeq2(2);
	TreeNode nodeq3(3);
	TreeNode nodeq4(4);
	TreeNode nodeq5(5);
	TreeNode nodeq6(7);
	nodeq1.left = &nodeq2;
	nodeq1.right = &nodeq3;
	
	nodeq2.left = &nodeq4;
	nodeq2.right = &nodeq5;
	
	nodeq3.left = &nodeq6;
	
	Solution so;
	bool ret = so.isSameTree(&node1,&nodeq1);
	
	if(!ret)
		printf("---------------------passed\n");
	else
		printf("---------------------failed\n");	
}

int main()
{
	test0();
	test1();
	test2();
	return 0;
}

