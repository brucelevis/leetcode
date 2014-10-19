/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){} 
} ;
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
//结果放到l1下面 
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    	if(l1 == NULL)	return l2;
    	if(l2 == NULL)	return l1;
        ListNode *tmp1 = l1, *pretmp1 = NULL, *tmp2 = l2;
        int takeover = 0;
        while(tmp1 && tmp2)
        {
        	int tmp = tmp1->val + tmp2->val + takeover;
        	if(tmp > 9)
			{
				tmp1->val = tmp - 10;
				takeover = 1;
			} 
			else
			{
				tmp1->val = tmp;
				takeover = 0;
			}
			pretmp1 = tmp1;
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
		if(tmp1 == NULL)
		{
			pretmp1->next = tmp2;
			tmp1 = pretmp1->next;
		}
		while(tmp1)
		{
			int tmp = tmp1->val + takeover;
			if(tmp > 9)
			{
				tmp1->val = tmp - 10;
				takeover = 1;
			} 
			else
			{
				tmp1->val = tmp;
				takeover = 0;
				break;
			}
			pretmp1 = tmp1;
			tmp1 = tmp1->next;
		}
		if(takeover == 1)
		{
			ListNode *addnode = new ListNode(1);
			pretmp1->next = addnode;
		}
		return l1;
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

void test0()
{
	vector<ListNode> list;
	int arr[10] = {2,4,3};
	ListNode *head = listCreate(list,arr, 3);
	printList(head,"head");
	
	vector<ListNode> list1;
	int arr1[10] = {5,6,4};
	ListNode *head1 = listCreate(list1,arr1, 3);
	printList(head1,"head1");
	
	Solution so;
	ListNode *head2 = so.addTwoNumbers(head,head1);
	int arr2[10] = {7,0,8};
	CheckList(head2,arr2,3);
	//printList(head,"head");
}
void test1()
{
	vector<ListNode> list;
	int arr[10] = {2,4,3};
	ListNode *head = listCreate(list,arr, 3);
	printList(head,"head");
	
	vector<ListNode> list1;
	int arr1[10] = {5,6,7};
	ListNode *head1 = listCreate(list1,arr1, 3);
	printList(head1,"head1");
	
	Solution so;
	ListNode *head2 = so.addTwoNumbers(head,head1);
	int arr2[10] = {7,0,1,1};
	CheckList(head2,arr2,4);
	//printList(head,"head");
}

int main()
{
	test0();
	test1();
	
	return 0;
}