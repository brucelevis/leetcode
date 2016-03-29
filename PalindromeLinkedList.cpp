//
// Created by yangxj on 16/3/17.
//
#include <iostream>
#include "LeetCodeUtils.h"

using namespace std;



class Solution {
  public:
    bool isPalindrome(ListNode* head) {
      if (!head || !head->next) {
        return true;
      }
      ListNode *fast = head;
      ListNode *slow = head;
      while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
      }
      if (fast) {
        slow = slow->next;
      } //奇数个
      fast = head;
      slow = reverseList(slow);
      while (slow) {
        if (fast->val != slow->val) {
          return false;
        }
        fast = fast->next;
        slow = slow->next;
      }
      return true;
    }

    ListNode* reverseList(ListNode* head) {
      if (!head || !head->next) {
        return head;
      }
      ListNode *tail = head->next;    // 这里就可以提前标记出最后一个结点
      ListNode *head2 = reverseList(head->next);
      tail->next = head;
      head->next = NULL;
      return head2;
    }
};


class Solution2 {
  private:
    ListNode *lst;
  public:
    bool judge(ListNode *head)
    {
      if(head == NULL) return true;

      if(judge(head->next) == false) return false;

      if(lst->val != head->val) return false;
      else{
        lst = lst->next;
        return true;
      }
    }
    bool isPalindrome(ListNode* head) {
      if(head == NULL || head->next == NULL) return true;
      lst = head;

      return judge(head);
    }
};

int main() {
  int arr1[6] = {0, 2, 4, 4, 2, 0};
  ListNode *head1 = listCreate(arr1, 6);

  Solution solution;
  if (solution.isPalindrome(head1)) {
    printf("passed\n");
  }

  int arr2[7] = {0, 2, 4, 5, 4, 2, 0};
  ListNode *head2 = listCreate(arr2, 7);
  if (solution.isPalindrome(head2)) {
    printf("passed\n");
  }

}
