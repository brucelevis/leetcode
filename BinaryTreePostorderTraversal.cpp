#include <iostream>
#include <vector>
#include <stack>
#include "LeetCodeUtils.h"

using namespace std;


class Solution1 {
  public:
    vector<int> postorderTraversal(TreeNode *root) {
      vector<int> out;
      if (root == NULL)
        return out;

      vector<int> out1 = postorderTraversal(root->left);
      vector<int> out2 = postorderTraversal(root->right);

      out.insert(out.begin(), root->val);          //��
      out.insert(out.begin(), out2.begin(), out2.end());  //��
      out.insert(out.begin(), out1.begin(), out1.end());  //��
      return out;
    }

    vector<int> postorderTraversal1(TreeNode *root) {
      vector<int> out;
      if (root == NULL)
        return out;
      TreeNode *head = root;          //���Ǽ�¼��һ�������Ľ��
      treenodeStack.push(root);
      while (!treenodeStack.empty()) {
        TreeNode *cur = treenodeStack.top();//����һ����¼��

        if (cur->left == head || cur->right == head || (cur->left == NULL && cur->right == NULL))//��������ܹؼ�
        {
          treenodeStack.pop();
          out.push_back(cur->val);
          head = cur;
          //printf("pop = %d\n",cur->val);
          //system("pause");
        }
        else {
          if (cur->right != NULL) treenodeStack.push(cur->right)/*,printf("lpush = %d\n",cur->right->val)*/;
          if (cur->left != NULL) treenodeStack.push(cur->left)/*,printf("rpush = %d\n",cur->left->val)*/;
        }
      }
      return out;
    }

  private:
    stack<TreeNode *> treenodeStack;
};

class Solution {
  public:
    vector<int> postorderTraversal(TreeNode *root) {
      vector<int> out;
      if (root == NULL)
        return out;

      stack<TreeNode*> treeStack;
      treeStack.push(root);
      TreeNode* tmp = NULL;
      while (!treeStack.empty()) {
        TreeNode* top = treeStack.top();
        if ((top->left == NULL && top->right == NULL) || top->left == tmp || top->right == tmp) {
          out.push_back(top->val);
          treeStack.pop();
          tmp = top;
        } else {
          if (top->right != NULL) treeStack.push(top->right)/*,printf("lpush = %d\n",cur->right->val)*/;
          if (top->left != NULL) treeStack.push(top->left)/*,printf("rpush = %d\n",cur->left->val)*/;
        }
      }
      return out;
    }
};

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
  vector<int> out = so.postorderTraversal(&node1);

  int tmp[7] = {4, 5, 2, 6, 7, 3, 1};

  int i = 0;
  for (i = 0; i < 7 && i < out.size(); i++) {
    if (out[i] != tmp[i]) {
      break;
    }
  }
  if (i == 7)
    printf("---------------------passed\n");
  else
    printf("---------------------failed\n");
}

int main() {
  test0();
}
