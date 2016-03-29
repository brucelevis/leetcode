#include <iostream>
#include <vector>
#include <stack>
#include "LeetCodeUtils.h"

using namespace std;

class Solution1 {
  public:
    vector<int> preorderTraversal2(TreeNode *root) {
      vector<int> out;
      if (root == NULL)
        return out;

      vector<int> out1 = preorderTraversal(root->left);
      vector<int> out2 = preorderTraversal(root->right);

      out.insert(out.begin(), out2.begin(), out2.end());
      out.insert(out.begin(), out1.begin(), out1.end());
      out.insert(out.begin(), root->val);

      return out;
    }

    vector<int> preorderTraversal(TreeNode *root) {
      vector<int> out;
      if (root == NULL)
        return out;
      //TreeNode *head = root;
      treenodeStack.push(root);
      while (!treenodeStack.empty()) {
        TreeNode *cur = treenodeStack.top();
        treenodeStack.pop();
        out.push_back(cur->val);

        if (cur->right != NULL) treenodeStack.push(cur->right)/*,printf("lpush = %d\n",cur->right->val)*/;
        if (cur->left != NULL) treenodeStack.push(cur->left)/*,printf("rpush = %d\n",cur->left->val)*/;
      }
      return out;
    }

  private:
    stack<TreeNode *> treenodeStack;
};


class Solution {
  public:
    vector<int> preorderTraversal1(TreeNode* root) {
      vector<int> out;
      if (!root) {
        return out;
      }
      vector<int> left = preorderTraversal(root->left);
      vector<int> right = preorderTraversal(root->right);
      out.insert(out.begin(), root->val);
      out.insert(out.end(), left.begin(), left.end());
      out.insert(out.end(), right.begin(), right.end());
//      out.insert(out.begin(), right.begin(), right.end());
//      out.insert(out.begin(), left.begin(), left.end());
//      out.insert(out.begin(), root->val);
      return out;
    }
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> out;
      if (!root) {
        return out;
      }
      stack<TreeNode*> treeStack;
      treeStack.push(root);
      while(!treeStack.empty()) {
        TreeNode* top = treeStack.top();
        out.push_back(top->val);
        treeStack.pop();
        if (top->right) {
          treeStack.push(top->right);
        }
        if (top->left) {
          treeStack.push(top->left);
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
  vector<int> out = so.preorderTraversal(&node1);

  int tmp[7] = {1, 2, 4, 5, 3, 6, 7};

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
