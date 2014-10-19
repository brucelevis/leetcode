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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(head == NULL || head->next == NULL || m >= n) return head;
        
        int i = 1;
        ListNode *p = head;
        while(++i<m && p != NULL) p = p->next;
        
        if(p == NULL) return head;
        ListNode *saveHead = p;
        if(m > 1)
        	p = p->next;
       	ListNode *tmphead = p, *tmptail = p;
        i = m;
        p = p->next;
        while(++i<=n && p != NULL)
        {
        	tmptail->next = p->next;
        	p->next = tmphead;
        	tmphead = p;
        	p = tmptail->next;//////////////////////////
		}
        if(m>1)
        	saveHead->next = tmphead;
        else
			head = tmphead;	
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
	int arr[10] = {0,1,2,3,4,5,6,7,8};
	ListNode *head = listCreate(list,arr, 9);
	printList(head,"head");
	Solution so;
	head = so.reverseBetween(head,1,4);
	printList(head,"head");
	int arr1[10] = {3,2,1,0,4,5,6,7,8};
	CheckList(head,arr1,9);
	//printList(head,"head");
}
int main()
{
	test0();
	return 0;
}