#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > ret;
        if(root == NULL)	return ret;
		queue<TreeNode* > quTree;
		quTree.push(root);
		int levelsum = 1;//ͬһ���ж��ٸ����
		vector<int> tmp; 
		while(!quTree.empty())
		{
				TreeNode* cur = quTree.front();
				tmp.push_back(cur->val);
				quTree.pop();
				levelsum--;
				if(cur->left != NULL)	quTree.push(cur->left);
				if(cur->right != NULL)	quTree.push(cur->right); 
				if(levelsum == 0)//�����������ʼ��һ�� 
				{
					levelsum = quTree.size();
					ret.insert(ret.begin(),tmp);
					tmp.clear();
				}
		}
        return ret;
    }
};


void printvec(vector<int > A)
{
	for(int i = 0;i<A.size();i++)
	{
		printf("%d,",A[i]);
	}
	printf("\n");
}

void printvecvec(vector<vector<int > > A, char *name)
{
	printf("%s\n",name);
	for(int i = 0;i<A.size();i++)
	{
		printf("%3d:",i);
		printvec(A[i]);
	}
	printf("\n");
}

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
	vector<vector<int> > out = so.levelOrderBottom(&node1);
	
	printvecvec(out,"ret");	
}

int main(int argc, char *argv[])
{
	test0();
	return 0;
}

