#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL)	return l2;
        if(l2 == NULL)	return l1;
        
        ListNode *head = NULL, *p = NULL, *p1 = l1, *p2 = l2;
        if(l1->val < l2->val)     	head = l1,p1 = p1->next;
       	else						head = l2,p2 = p2->next;
       	p=head;
       	p->next = NULL;
       	//printList(head,"head");
        while(p1 != NULL && p2 != NULL)
        {
        	if(p1->val < p2->val)
        	{
        		p->next = p1;
        		p1 = p1->next;
        		p = p->next;
        		p->next = NULL;
			}
			else
			{
				p->next = p2;
        		p2 = p2->next;
        		p = p->next;
        		p->next = NULL;
			}
			//printList(head,"head");
		}
		if(p1 == NULL)
		{
			while(p2 != NULL)
			{
				p->next = p2;
        		p2 = p2->next;
        		p = p->next;
        		p->next = NULL;				
			}
		}
		if(p2 == NULL)
		{
			while(p1 != NULL)
			{
				p->next = p1;
        		p1 = p1->next;
        		p = p->next;
        		p->next = NULL;				
			}
		}
		return head;
    }
};
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
	vector<ListNode> list1;
	int arr1[5] = {0,2,4,6,8};
	ListNode *head1 = listCreate(list1,arr1, 5);
	printList(head1,"head1");
	
	vector<ListNode> list2;
	int arr2[5] = {1,3,5,7,9};
	ListNode *head2 = listCreate(list2,arr2, 5);
	printList(head2,"head2");
	
	Solution so;
	ListNode *head0 = so.mergeTwoLists(head1,head2);
	printList(head0,"head0");
	int arr0[10] = {0,1,2,3,4,5,6,7,8,9};
	CheckList(head0,arr0,10);
	//printList(head,"head");
}
int main()
{
	test0();
	return 0;
}
