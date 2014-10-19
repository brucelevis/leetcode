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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *p = head,*q = head->next;
        int tmpval = 0;
        int num = 0;
        while(q != NULL)
        {
	        while(q != NULL && p->val == q->val)
	        {
	        	p = q;
	        	q=q->next;
	        	num++;
			}
			if(q == NULL) return NULL;///////////////////
			if(num > 0)
			{
				head = q;
				p = head;
				q = head->next;
				num = 0;
			}
			else
				break;
        }
        if(q == NULL) return head;
        tmpval = q->val;
        //ListNode *preq = q;
        q = q->next;
        num = 0;
        while(q != NULL)
        {
        	if(q->val == tmpval)
        	{
        		num++;
			}
			else
			{
				if(num >0)
					p->next = q;
				else
					p = p->next;
				tmpval = q->val;/////////////////////
				num = 0;///////////////////////////
			}
			q = q->next;
		}
		if(num > 0)//////////////////////////
		    p->next = NULL;
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
	int arr[10] = {0,1,1,3,5,5,6,7,8};
	ListNode *head = listCreate(list,arr, 9);
	printList(head,"head");
	Solution so;
	head = so.deleteDuplicates(head);
	printList(head,"head");
	int arr1[10] = {0,3,6,7,8};
	CheckList(head,arr1,5);
	//printList(head,"head");
}
int main()
{
	test0();
	return 0;
}