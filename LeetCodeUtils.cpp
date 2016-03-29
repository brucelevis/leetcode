//
// Created by yangxj on 16/2/29.
//

#include "LeetCodeUtils.h"

void printVector(vector<int> vec) {
  for(int i = 0;i<vec.size();i++)
  {
    printf("%d,",vec[i]);
  }
  printf("\n");
}

void printVector(vector<int> vec, char *name) {
  printf("%s\n",name);
  printVector(vec);
}

void printVector(vector<vector<int> > vec, char *name) {
  printf("%s\n",name);
  for(int i = 0;i<vec.size();i++)
  {
    printf("%3d:",i);
    printVector(vec[i]);
  }
  printf("\n");
}

void printList(ListNode *head, string name) {
  printf("%s:", name.c_str());
  int count = 0;
  while (head != NULL) {
    printf("%3d,", head->val);
    head = head->next;
    count++;
  }
  printf("\nsize=%d\n", count);
}



ListNode *listCreate(int arr[], int n) {
  if (n <= 0)
    return NULL;

  ListNode *head = NULL, *p = NULL;
  for (int i = 0; i < n; i++) {
    ListNode *tmp = new ListNode(arr[i]);
    if (head==NULL) {
      head = tmp;
      p=head;
    } else {
      p->next = tmp;
      p = p->next;
    }
  }

  return head;
}
