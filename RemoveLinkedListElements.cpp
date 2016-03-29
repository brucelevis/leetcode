//
// Created by yangxj on 16/3/17.
//
#include <iostream>
#include "LeetCodeUtils.h"

using namespace std;


class Solution1 {
  public:
    ListNode* removeElements(ListNode* head, int val) {
      if (head == NULL) {
        return head;
      }
      while (head && head->val == val) {
        ListNode *p = head;
        head = head->next;
        delete(p);
      }
      if (!head) {
        return head;
      }
//      printList(head, "tmp");
      ListNode *p = head->next;
      ListNode *preP = head;
      while (p) {
        if (p->val == val) {
          preP->next = p->next;
          delete(p);
          p = preP->next;
        } else {
          preP = p;
          p = p->next;
        }
      }
      return head;
    }

    ListNode* removeElements2(ListNode* head, int val) {
      if (head == NULL) {
        return head;
      }
      ListNode *p = head->next;
      ListNode *preP = head;
      while (p) {
        if (p->val == val) {
          preP->next = p->next;
          delete(p);
          p = preP->next;
        } else {
          preP = p;
          p = p->next;
        }
      }
      return head->val==val ? head->next: head;
    }

    ListNode* removeElements3(ListNode* head, int val) {
      if (head == NULL) {
        return head;
      }
      head->next = removeElements(head->next, val);
      return head->val==val ? head->next: head;
    }
};

class Solution {
  public:
    void removeElement(ListNode* node) {
      if (!node || !node->next) {
        return;
      }
      ListNode* tmp = node->next;
      node->val = node->next->val;
      node->next = node->next->next;
      delete(tmp);
    }
    ListNode* removeElements(ListNode* head, int val) {
      if (head == NULL) {
        return head;
      }
      ListNode *p = head;
      ListNode *pre = NULL;
//      printList(head, "tmp");
      while (p->next) {
        if (p->val == val) {
          removeElement(p);
        } else {
          pre = p;
          p = p->next;
        }
//        printList(head, "tmp");
      }
      if (p->val == val) {
        if (pre) {
          pre->next = NULL;
          delete(p);
        } else {
          return NULL;
        }
      }
      return head;
    }
};


int main() {
  int arr1[6] = {0, 2, 4, 6, 8, 9};
  ListNode *head1 = listCreate(arr1, 6);
  printList(head1, "head1");
  Solution so;

  ListNode *head2 = so.removeElements(head1, 0);
  printList(head2, "head2");
  ListNode *head3 = so.removeElements(head2, 4);
  printList(head3, "head3");
  ListNode *head4 = so.removeElements(head3, 9);
  printList(head4, "head4");
  ListNode *head5 = so.removeElements(head4, 3);
  printList(head5, "head5");


}
