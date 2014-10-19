/*
���뻷��CFree 5.0 
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;


#define METHOD 1 //1- �ݹ鷨
//#define METHOD 2//2- ��ջ����1 
//#define METHOD 3//3- ��ջ����3 


 

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
�����vector��ʹ�÷���Ҫ�õ���������vectorƴ��һ��ķ�����
��out1��out2��ƴ�ɣ�out1��out2�� 
out2.insert(out2.begin(),out1.begin(),out1.end());//out1,out2˳��ҪŪ�� 
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> out;
        if(root == NULL)
        	return out;
        
        vector<int> out1 = postorderTraversal(root->left);
        vector<int> out2 = postorderTraversal(root->right);
        
        out.insert(out.begin(),root->val); 					//�� 
        out.insert(out.begin(),out2.begin(),out2.end());	//�� 
        out.insert(out.begin(),out1.begin(),out1.end());	//�� 
        return out;
    }
};
#elif METHOD == 2
//��ջ���� 
//���������̫����⣬��Ҫ�����о� 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> out;
        if(root == NULL)
        	return out;
       	TreeNode *head = root;					//���Ǽ�¼��һ�������Ľ�� 
       	treenodeStack.push(root);
        while(!treenodeStack.empty())
		{
			TreeNode *cur = treenodeStack.top();//����һ����¼��
			
			if(cur->left == head || cur->right== head ||(cur->left == NULL && cur->right == NULL))//��������ܹؼ� 
			{
				treenodeStack.pop();
				out.push_back(cur->val);
				head = cur;
				//printf("pop = %d\n",cur->val);
				//system("pause");
			} 
			else
			{
				if(cur->right != NULL)	treenodeStack.push(cur->right)/*,printf("lpush = %d\n",cur->right->val)*/;
				if(cur->left != NULL)	treenodeStack.push(cur->left)/*,printf("rpush = %d\n",cur->left->val)*/;
			}
		} 
        return out;
    }
private:
	stack<TreeNode*> treenodeStack; 
};
#elif METHOD == 3
/*
���������ѽ���Լ�->�Ҷ���->�����˳������������һ������ͺ� 
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if(root == NULL)
            return res;
        vector<TreeNode*> stc;
        stc.push_back(root);
        while(!stc.empty()) {
            TreeNode* node = stc.back();
            res.push_back(node->val);
            stc.pop_back();
            if(node->left != NULL) {
                stc.push_back(node->left);
            }
            if(node->right != NULL) {
                stc.push_back(node->right);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
}; 
#endif

/*���ܲ���*/
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
	vector<int> out = so.postorderTraversal(&node1);
	
	int tmp[7] = {4,5,2,6,7,3,1};
	
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
