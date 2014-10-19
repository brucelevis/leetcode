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
#if 0//�ݹ鷨 
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(root == NULL)
        	return 0;
       	int left = maxDepth(root->left);
       	int right = maxDepth(root->right);
       	if(left > right)
       		return left + 1;
  		else
  			return right + 1;        	
    }
};
#elif 0//ѭ����  ջ ������� 
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(root == NULL)
        	return 0;
       	stack<TreeNode*> treeStk;
       	treeStk.push(root);
		int maxhigh = 1, tmphigh = 1;
		TreeNode *preNode = root;		//��¼��һ���������Ľ��   ��ʼֵҪ��root 
		while(!treeStk.empty())
		{
			TreeNode *topNode = treeStk.top();
			//printf("top = %d high = %d\n",topNode->val,tmphigh);
			if(topNode->left == NULL && topNode->right == NULL/*Ҷ�ӽ��*/)
			{
				if(tmphigh > maxhigh)	maxhigh = tmphigh;
				treeStk.pop();
				preNode = topNode; 
				continue;				 
			}
			if(topNode->right == preNode || topNode->left == preNode)//���ӽ���Ѿ������� 
			{
				tmphigh--;
				treeStk.pop();
				preNode = topNode;
				continue;	
			}
			if(topNode->right != NULL) treeStk.push(topNode->right);
			if(topNode->left != NULL) treeStk.push(topNode->left);
			tmphigh++;//�߶ȼ�1	
		}
		return maxhigh;
    }
};
#elif 1 //���й������ 
class Solution {
public:
    //�����������ȣ���α���������һ��߶ȼ�1��
    int maxDepth(TreeNode *root) {
        int height = 0,rowCount = 1;
        if(root == NULL){
            return 0;
        }
        //��������
        queue<TreeNode*> queue;
        //��Ӹ��ڵ�
        queue.push(root);
        //��α���
        while(!queue.empty()){
            //����ͷԪ��
            TreeNode *node = queue.front();
            //������
            queue.pop();
            //һ���Ԫ�ظ�����1��һ�������߶ȼ�1
            rowCount --;
            if(node->left){
                queue.push(node->left);
            }
            if(node->right){
                queue.push(node->right);
            }
            //һ�������
            if(rowCount == 0){
                //�߶ȼ�1
                height++;
                //��һ��Ԫ�ظ���
                rowCount = queue.size();
            }
        }
        return height;
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
	int high = so.maxDepth(&node1);
	

	if(high == 3)
		printf("---------------------passed\n");
	else
		printf("---------------------failed\n");	
}

/*���ܲ���*/
void test1()
{
/*
				1
		2	
	3	
*/ 
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);
	
	node1.left = &node2;
	
	node2.left = &node3;
	
	Solution so;
	int high = so.maxDepth(&node1);
	

	if(high == 3)
		printf("---------------------passed\n");
	else
		printf("---------------------failed\n");	
}

/*���ܲ���*/
void test2()
{
/*
						1
			2					3
	4				5
				6
					7
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
	
	node5.left = &node6;
	node6.right = &node7;
	
	Solution so;
	int high = so.maxDepth(&node1);
	

	if(high == 5)
		printf("---------------------passed\n");
	else
		printf("---------------------failed\n");	
}
/*���ܲ���*/
void test3()
{
	Solution so;
	int high = so.maxDepth(NULL);
	

	if(high == 0)
		printf("---------------------passed\n");
	else
		printf("---------------------failed\n");	
}
/*���ܲ���*/
void test4()
{
/*
						1
*/ 
	TreeNode node1(1);
	Solution so;
	int high = so.maxDepth(&node1);
	

	if(high == 1)
		printf("---------------------passed\n");
	else
		printf("---------------------failed\n");	
}
int main()
{
	test0();
	test1();
	test2();
	test3();
	test4();
	return 0;
}
