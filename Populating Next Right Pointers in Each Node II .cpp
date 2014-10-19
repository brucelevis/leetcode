#include <iostream>
#include <queue>
using namespace std;

#define DEBUG 

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };
 
 // 队列 广度遍历
 #if 0 
class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if(root == NULL)	return;
        queue<TreeLinkNode *> treeque;
        treeque.push(root);
        int levelSum = treeque.size();
        while(!treeque.empty())
        {
        	TreeLinkNode *front = treeque.front(); 
			treeque.pop();      	
			if(front->left != NULL)		treeque.push(front->left);
			if(front->right != NULL)	treeque.push(front->right);	
			
			levelSum--;
        	if(levelSum == 0)
        	{
        		front->next=NULL;
        		levelSum = treeque.size();
#ifdef DEBUG
				printf("%d next=NULL\n",front->val);
#endif
			}
			else
			{
				front->next = treeque.front();
#ifdef DEBUG
				printf("%d next=%d\n",front->val,treeque.front()->val);
#endif
			}		
		}
    }
};
#elif 1
class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if(root == NULL)	return;
    	printf("root = %d\n",root->val);
    	TreeLinkNode *p = NULL;
    	TreeLinkNode * q = root;
    	while(q->next)
    	{
	    	if(q->next->left)
			{	
				p = q->next->left;
				break;
			}
	    	else if(q->next->right) 
			{	
				p = q->next->right;
				break;
			}
			q = q->next;
    	}
    	printf("p = %d\n",p?p->val:-1);
       	if(root->left != NULL && root->right != NULL)
       		root->left->next = root->right,printf("%d next=%d\n",root->left->val,root->right->val);
   		else if(root->left != NULL && root->right == NULL)
   			root->left->next = p,printf("%d next=%d\n",root->left->val,p?p->val:-1);
   			
   		if(root->right != NULL)//充分利用已经有的next指针 
       			root->right->next = p,printf("%d next=%d\n",root->right->val,p?p->val:-1);
		
       	connect(root->left);
       	connect(root->right); 
    }
};
#endif
void test0()
{
	TreeLinkNode node1(2);
	TreeLinkNode node2(1);
	TreeLinkNode node3(3);
	TreeLinkNode node4(0);
	TreeLinkNode node5(7);
	TreeLinkNode node6(9);
	TreeLinkNode node7(1);
	TreeLinkNode node8(2);
	TreeLinkNode node9(1);
	TreeLinkNode node10(0);
	TreeLinkNode node11(8);
	TreeLinkNode node12(8);
	TreeLinkNode node13(7);
	
	node1.left = &node2;
	node1.right = &node3;
	
	node2.left = &node4;
	node2.right = &node5;
	
	node3.left = &node6;
	node3.right = &node7;
	
	node4.left = &node8;
	
	node5.left = &node9;
	node5.right = &node10;
	
	node7.left = &node11;
	node7.right = &node12;
	
	node10.left = &node13;
	
	Solution so;
	so.connect(&node1);
}
int main()
{
	test0();
	return 0;
}

