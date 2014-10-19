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
       	if(root->left != NULL)
       		root->left->next = root->right/*,printf("%d next=%d\n",root->left->val,root->right->val)*/;
   		if(root->right != NULL && root->next != NULL)//充分利用已经有的next指针 
       			root->right->next = root->next->left/*,printf("%d next=%d\n",root->right->val,root->next->left->val)*/;
		
       	connect(root->left);
       	connect(root->right); 
    }
};
#endif
void test0()
{
	TreeLinkNode node1(1);
	TreeLinkNode node2(2);
	TreeLinkNode node3(3);
	TreeLinkNode node4(4);
	TreeLinkNode node5(5);
	TreeLinkNode node6(6);
	TreeLinkNode node7(7);
	
	node1.left = &node2;
	node1.right = &node3;
	
	node2.left = &node4;
	node2.right = &node5;
	
	node3.left = &node6;
	node3.right = &node7;
	
	Solution so;
	so.connect(&node1);
}
int main()
{
	test0();
	return 0;
}

