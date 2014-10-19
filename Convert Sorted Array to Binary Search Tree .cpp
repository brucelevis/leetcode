/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/
#include <iostream>
#include <vector>
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
		
		return (bl && br && abs(hL - hR) < 2);
    } 
bool isBalanced(TreeNode *root) {
        if(root == NULL) return true;
        int height = 0;
        return treeHeight(root,height);
    }

#if 0
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int size = num.size();
        if(size < 1)	return NULL;
        return sortedArrayToBSTcore(num, 0,size - 1);
    }
    TreeNode *sortedArrayToBSTcore(vector<int> &num,int start, int end)
    {
    	int mid = (start+end)/2;
        TreeNode *root = new TreeNode(num[mid]);
        printf("root = %d\n",root->val);
        if(start < mid)
		{
		 	root->left = sortedArrayToBSTcore(num, start, mid - 1);
		 	printf("root = %d left = %d\n",root->val,root->left->val);
		}
        else
		{
			root->left = NULL;
			printf("root = %d left = NULL\n",root->val);
		}
        if(end > mid)
		{
		 	root->right = sortedArrayToBSTcore(num, mid + 1, end);
		 	printf("root = %d right = %d\n",root->val,root->right->val);
		}
		else 
		{
			root->right = NULL; 
			printf("root = %d right = NULL\n",root->val);
		}
		return root;
	}

};
#elif 1
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int size = num.size();
        if(size < 1)	return NULL;
        return sortedArrayToBSTcore(num, 0,size - 1);
    }
    TreeNode *sortedArrayToBSTcore(vector<int> &num,int start, int end)
    {
    	int mid = (start+end)/2;
        TreeNode *root = new TreeNode(num[mid]);
        if(start < mid) 	root->left = sortedArrayToBSTcore(num, start, mid - 1);
        else				root->left = NULL;
        if(end > mid)	 	root->right = sortedArrayToBSTcore(num, mid + 1, end);
		else 				root->right = NULL; 
		return root;
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
	
	int A[] = {0,1,2,3,4,5,6};
  	vector<int> num (A, A + sizeof(A) / sizeof(int) );
  	Solution so;
	if(isBalanced(so.sortedArrayToBST(num)))
		printf("---------------------passed\n");
	else
		printf("---------------------failed\n");
}
/*功能测试*/
void test1()
{/*

	if(out == true)
		printf("---------------------passed\n");
	else
		printf("---------------------failed\n");*/	
}
int main()
{
	test0();
	test1();
	return 0;
}

 
 