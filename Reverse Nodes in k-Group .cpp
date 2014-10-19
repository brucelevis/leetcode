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
#if 1
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head == NULL || head->next == NULL || k == 1) return head;
        int i = 0;        
        ListNode *tmphead = head, *tmptail = head, *tmpSaveHead = NULL,*tmpSaveTail = NULL , *p;
        
        while(tmptail != NULL)
        {
	        while(++i<k && tmptail != NULL)
	        	tmptail = tmptail->next;
	       	if(tmptail == NULL) return head;	       	
	       	tmpSaveTail = tmptail->next;
	       	//printList(tmphead,"tmphead");
	       	p = tmphead->next;
	       	tmptail = tmphead;
	       	while(i-- > 1)
	       	{
	       		tmptail->next = p->next;
				p->next = tmphead;
				tmphead = p;
				p = tmptail->next;	
	   		}
	       	
	       	if(tmpSaveHead)	tmpSaveHead->next = tmphead;
	       	else	head = tmphead;
	       	tmpSaveHead = tmptail;
	       	//printList(tmphead,"1tmphead");
	       	//system("pause");
	       	//printList(head,"head");
	       	//system("pause");
	       	tmphead  = tmpSaveTail;
	       	tmptail = tmpSaveTail;
	       	i = 0;
        }     
		return head;
    }
};
#elif 0
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head == NULL || head->next == NULL) return head;
        int i = 0;        
        ListNode *tmphead = head, *tmptail = head, *tmp = NULL,*tmp1 = NULL;
        
        while(tmptail != NULL)
        {
	        while(++i<k && tmptail != NULL)
	        	tmptail = tmptail->next;
	       	if(tmptail == NULL) return head;	       	
	       	tmp1 = tmptail->next;
	       	//printList(tmphead,"tmphead");
	       	reverseKGroupCore(&tmphead,&tmptail);
	       	if(tmp)	tmp->next = tmphead;
	       	else	head = tmphead;
	       	tmp = tmptail;
	       	//printList(tmphead,"1tmphead");
	       	//printList(head,"head");
	       	//system("pause");
	       	tmphead  = tmp1;
	       	tmptail = tmp1;
	       	i = 0;
        }     
		return head;
    }
    //
    void reverseKGroupCore(ListNode **head,ListNode** tail)
    {
    	ListNode *tmpHead = *head;
		ListNode *tmpTail = tmpHead;
		ListNode *stop = (*tail)->next;
		ListNode *p = tmpHead->next;
		while(p != stop)
		{
			tmpTail->next = p->next;
			p->next = tmpHead;
			tmpHead = p;
			printf("p = %d\n",p->val);
			p = tmpTail->next; 			
		}
		*head = tmpHead;
		*tail = tmpTail;		 
	}
};
#endif
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
	int arr[10] = {0,1,2,3,4,5,6,7,8};
	ListNode *head = listCreate(list,arr, 9);
	printList(head,"head");
	Solution so;
	head = so.reverseKGroup(head,2);
	printList(head,"head");
	int arr1[10] = {1,0,3,2,5,4,7,6,8};
	CheckList(head,arr1,9);
	//printList(head,"head");
}
int main()
{
	test0();
	return 0;
}