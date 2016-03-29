//
// Created by yangxj on 16/3/17.
//
#include <iostream>
#include "LeetCodeUtils.h"

using namespace std;



class Solution {
  public:
    ListNode* oddEvenList(ListNode* head) {
      if (!head || !head->next || !head->next->next) {
        return head;
      }
      ListNode *evenHead = head->next;
      ListNode *oddTail = head, *evenTail = evenHead;
      ListNode *p = evenHead->next;
      while(p) {
        if (evenTail->next == p) {
          oddTail->next = p;
          oddTail = p;
        } else {
          evenTail->next = p;
          evenTail = p;
        }
        p = p->next;
      }
      oddTail->next = evenHead;
      evenTail->next = NULL;  // ATTENTION
      return head;
    }
};


int main() {
  int arr1[8] = {0, 1, 2, 3, 4, 5, 6, 7};
  ListNode *head1 = listCreate(arr1, 8);
  printList(head1, "befor");
  Solution solution;
  printList(solution.oddEvenList(head1), "after");
}
