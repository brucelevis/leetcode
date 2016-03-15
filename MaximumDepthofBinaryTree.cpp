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

   TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

#if 0//递归法
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
#elif 0//循环法  栈 深度优先
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(root == NULL)
          return 0;
         stack<TreeNode*> treeStk;
         treeStk.push(root);
    int maxhigh = 1, tmphigh = 1;
    TreeNode *preNode = root;  //记录上一个被遍历的结点   初始值要是root
    while(!treeStk.empty())
    {
      TreeNode *topNode = treeStk.top();
      //printf("top = %d high = %d\n",topNode->val,tmphigh);
      if(topNode->left == NULL && topNode->right == NULL)  /*叶子结点*/
      {
        if(tmphigh > maxhigh)	maxhigh = tmphigh;
        treeStk.pop();
        preNode = topNode;
        continue;
      }
      if(topNode->right == preNode || topNode->left == preNode)  //孩子结点已经被遍历
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
#elif 1 //队列广度优先

class Solution {
  public:
    //二叉树最大深度（层次遍历，遍历一层高度加1）
    int maxDepth(TreeNode *root) {
      int height = 0,rowCount = 1;
      if(root == NULL){
        return 0;
      }
      //创建队列
      queue<TreeNode*> queue;
      //添加根节点
      queue.push(root);
      //层次遍历
      while(!queue.empty()){
        //队列头元素
        TreeNode *node = queue.front();
        //出队列
        queue.pop();
        //一层的元素个数减1，一层遍历完高度加1
        rowCount --;
        if(node->left){
          queue.push(node->left);
        }
        if(node->right){
          queue.push(node->right);
        }
        //一层遍历完
        if(rowCount == 0){
          //高度加1
          height++;
          //下一层元素个数
          rowCount = queue.size();
        }
      }
      return height;
    }

};

#endif

/*功能测试*/
void test0() {
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


  if (high == 3)
    printf("---------------------passed\n");
  else
    printf("---------------------failed\n");
}

/*功能测试*/
void test1() {
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


  if (high == 3)
    printf("---------------------passed\n");
  else
    printf("---------------------failed\n");
}

/*功能测试*/
void test2() {
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


  if (high == 5)
    printf("---------------------passed\n");
  else
    printf("---------------------failed\n");
}

/*功能测试*/
void test3() {
  Solution so;
  int high = so.maxDepth(NULL);


  if (high == 0)
    printf("---------------------passed\n");
  else
    printf("---------------------failed\n");
}

/*功能测试*/
void test4() {
/*
						1
*/
  TreeNode node1(1);
  Solution so;
  int high = so.maxDepth(&node1);


  if (high == 1)
    printf("---------------------passed\n");
  else
    printf("---------------------failed\n");
}

int main() {
  test0();
  test1();
  test2();
  test3();
  test4();
  return 0;
}
