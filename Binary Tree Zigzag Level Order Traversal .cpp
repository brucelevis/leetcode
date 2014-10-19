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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        if(root == NULL)	return ret;
		queue<TreeNode* > quTree;
		quTree.push(root);
		int levelsum = 1;//同一层有多少个结点
		int hight = 1;
		vector<int> tmp; 
		while(!quTree.empty())
		{
				TreeNode* cur = quTree.front();
				if(hight % 2 == 1)
					tmp.push_back(cur->val);
				else
					tmp.insert(tmp.begin(),cur->val);
				quTree.pop();
				levelsum--;		
				if(cur->left != NULL)	quTree.push(cur->left);
				if(cur->right != NULL)	quTree.push(cur->right);
				if(levelsum == 0)//本层结束，开始下一层 
				{
					levelsum = quTree.size();
					ret.push_back(tmp);
					tmp.clear();
					hight++;
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
	vector<vector<int> > out = so.zigzagLevelOrder(&node1);
	
	printvecvec(out,"ret");	
}

int main(int argc, char *argv[])
{
	test0();
	return 0;
}

