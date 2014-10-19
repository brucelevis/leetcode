/*
编译环境CFree 5.0 
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;


//#define METHOD 1 //1- 递归法
#define METHOD 2//2- 堆栈方法 

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
#if METHOD == 1
/*
这里对vector的使用方法要得当，把两个vector拼在一起的方法是
把out1，out2，拼成（out1，out2） 
out2.insert(out2.begin(),out1.begin(),out1.end());//out1,out2顺序不要弄错 
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {//中左右 
        vector<int> out;
        if(root == NULL)
        	return out;
        	
        vector<int> out1 = preorderTraversal(root->left);
        vector<int> out2 = preorderTraversal(root->right);        
        
        out.insert(out.begin(),out2.begin(),out2.end());	//右 
        out.insert(out.begin(),out1.begin(),out1.end());	//左 
        out.insert(out.begin(),root->val); 					//中 
        
        return out;
    }
};
#elif METHOD == 2
//堆栈方法 
//这个方法不太好理解，需要加以研究 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> out;
        if(root == NULL)
        	return out;
       	//TreeNode *head = root;					//就是记录上一个弹出的结点 
       	treenodeStack.push(root);
        while(!treenodeStack.empty())
		{
			TreeNode *cur = treenodeStack.top();//增加一个记录点
			treenodeStack.pop();
			out.push_back(cur->val);
		
			if(cur->right != NULL)	treenodeStack.push(cur->right)/*,printf("lpush = %d\n",cur->right->val)*/;
			if(cur->left != NULL)	treenodeStack.push(cur->left)/*,printf("rpush = %d\n",cur->left->val)*/;
		} 
        return out;
    }
private:
	stack<TreeNode*> treenodeStack; 
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
	vector<int> out = so.preorderTraversal(&node1);
	
	//int tmp[7] = {4,5,2,6,7,3,1};后序
	int tmp[7] = {1,2,4,5,3,6,7};//先序 
	
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
