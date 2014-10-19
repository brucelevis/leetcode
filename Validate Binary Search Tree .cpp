#include <iostream>
#include <stack>
using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 //ÏÈÐò±éÀúÒ»±é 
class Solution {
public:
    bool isValidBST(TreeNode *root) {
    	if(root == NULL)	return true;
    	if(root->left == NULL && root->right == NULL)
    		return true;
        stack<TreeNode *>stk;
        //stk.push(root);///////////////////////////////////////////
        TreeNode *p = root;
        TreeNode *pre = NULL;
        while(p != NULL || !stk.empty())
        {
        	if(p!=NULL)
        	{
        		stk.push(p);
        		p = p->left;
			}
			else
			{
				p = stk.top();
				if(pre)
					if(pre->val>=p->val)
						return false;
				stk.pop();
				pre = p;
				p = p->right;
			}
		}
		return true;
    }
    
};

int main(int argc, char *argv[])
{
	
	return 0;
}