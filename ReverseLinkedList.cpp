//
// Created by yangxj on 16/3/17.
//
#include <iostream>
#include "LeetCodeUtils.h"

using namespace std;



class Solution {
  public:
    ListNode* reverseList2(ListNode* head) {
      if (!head || !head->next) {
        return head;
      }
      ListNode *left;
      ListNode *cur = head->next;
      head->next = NULL;
      while (cur) {
        left = cur->next;
        cur->next = head;
        head = cur;
        cur = left;
      }
      return head;
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


int main() {
  int arr1[6] = {0, 2, 4, 6, 8, 9};
  ListNode *head1 = listCreate(arr1, 6);
  Solution so;
  printList(head1, "head");
  printList(so.reverseList(head1), "reverse");

}
