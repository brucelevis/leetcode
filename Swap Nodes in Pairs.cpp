/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/
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
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL || head->next == NULL)	return head;
        //printList(head,"head");	
        //至少两个结点 
		ListNode *p = head, *prep = NULL;
        ListNode *q = p->next;
        p->next = q->next;
		q->next = p;
		head = q;
		prep = p;
		p = p->next;
		//printList(head,"head");	
		while(p != NULL && p->next != NULL)
		{
			q = p->next;
			p->next = q->next;
			q->next = p;
			prep->next = q;
			prep = p;
			p = p->next;
			//printList(head,"head");	
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
	int arr1[10] = {0,1,2,3,4,5,6,7,8,9};
	ListNode *head1 = listCreate(list1,arr1, 10);
	printList(head1,"head1");	
	Solution so;
	ListNode *head0 = so.swapPairs(head1);
	printList(head0,"head0");
	int arr0[10] = {1,0,3,2,5,4,7,6,9,8};
	CheckList(head0,arr0,10);
	//printList(head,"head");
}
int main()
{
	test0();
	return 0;
}

