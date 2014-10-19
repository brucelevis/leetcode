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
	if(head == NULL)
		return;
	printf("%s list:",name);
	while(head != NULL)
	{
		printf("%3d",head->val);
		head = head->next;
		//system("pause");
	} 
	printf("\n");
}
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *p = head,*preq=head,*q=head->next;
        while(q != NULL)
        {
        	//system("pause");
        	//printf("q=%d\n",q->val);
        	//printList(head,"head");
        	if(q->val < x)
        	{
        		if(p->val>=x)
        		{
        			preq->next = q->next;
        			q->next = head;
					head = q;
					p = head;
					q = preq;
				}
				else
				{
	        		if(preq != p)
	        		{
	        			preq->next = q->next;
	    				q->next = p->next;
	    				p->next = q;
	    				p = q;
	    				//printf("p=%d\n",p->val);
						q = preq;
	        		}
	        		else
	        			p=p->next;
				}
			}
			
			preq = q;
			q = q->next;
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
	vector<ListNode> list;
	int arr[6] = {1,3,-1,5,2,1};
	ListNode *head = listCreate(list,arr, 6);
	printList(head,"head");
	Solution so;
	head = so.partition(head,3);
	printList(head,"head");
	int arr1[6] = {1,-1,2,1,3,5};
	CheckList(head,arr1,6);
	//printList(head,"head");
}
void test1()
{
	vector<ListNode> list;
	int arr[9] = {2,0,4,1,3,1,4,0,3};
	ListNode *head = listCreate(list,arr, 9);
	printList(head,"head");
	Solution so;
	head = so.partition(head,4);
	printList(head,"head");
	int arr1[9] = {2,0,1,3,1,0,3,4,4};
	CheckList(head,arr1,9);
	//printList(head,"head");
}
void test2()
{
	vector<ListNode> list;
	int arr[2] = {2,1};
	ListNode *head = listCreate(list,arr, 2);
	printList(head,"head");
	Solution so;
	head = so.partition(head,2);
	printList(head,"head");
	int arr1[2] = {1,2};
	CheckList(head,arr1,2);
	//printList(head,"head");
}
int main()
{
	test0();
	test1();
	test2();
	return 0;
}