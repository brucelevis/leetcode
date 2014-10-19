#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
 void printList(ListNode *head,char *name)
{
	printf("%s\n",name);
	while(head != NULL)
	{
		printf("%3d,",head->val);
		head = head->next;
	}
	printf("\n");
}

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL)	return NULL;
        ListNode *p = head;
        ListNode *q = p->next;
        while(q != NULL)
        {
        	if(p->val == q->val)//把q移除
			{
				p->next = q->next;
				q = p->next; 
			} 
			else
			{
				q = q->next;
				p = p->next;
			}
		}
		return head;
    }
};


/*
vector 在添加过程中会动态的申请内存，元素的位置会动态的调整，所以
不能边创建vector边创建链表，中间指针可能会动。

这里的list需要使用传引用 
*/
ListNode* listCreate(vector<ListNode> &list, int arr[], int n)
{
	if(n <= 0)
		return NULL;
		
	for(int i=0;i<n;i++)
	{
		ListNode tmp(arr[i]);
		list.push_back(tmp);
	}
	
	ListNode *head = &list[0];
	for(int i=1;i<n;i++)
	{
		head->next = &list[i];
		head = head->next;
	}
	head = &list[0];
	return head;
}
void CheckList(ListNode *head,int arr[], int n)
{
	int i = 0;
	for(i = 0;i<n && head != NULL;i++,head=head->next)
	{
		if(head->val != arr[i])
			break;
	}
	if(i != n)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}

//功能测试，长度为偶数 
void test0()
{
	vector<ListNode> list;
	int arr[10] = {0,1,1,3,3,5,6,7,7,7};
	ListNode *head = listCreate(list,arr, 10);
	printList(head,"head");
	Solution so;
	so.deleteDuplicates(head);
	int arr1[6] = {0,1,3,5,6,7};
	CheckList(head,arr1,6);
	//printList(head,"head");
}

int main(int argc, char *argv[])
{
	test0(); 
	return 0;
}
