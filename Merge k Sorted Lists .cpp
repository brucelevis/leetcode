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

void printList(ListNode *head)
{
	while(head != NULL)
	{
		printf("%3d,",head->val);
		head = head->next;
	}
	printf("\n");
}

void printList(vector<ListNode *> &lists,char *name)
{
	printf("%s\n",name);
	for(int i = 0;i<lists.size();i++)
		printList(lists[i]);
	printf("\n");
}
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *head = NULL;
        int size = lists.size();
        if(size < 1) return NULL;
        //printList(lists,"lists");
        int i = 0;
        while(i<size && head == NULL) head = lists[i++];
        if(head == NULL) return NULL;//全部空 
        
        ListNode *p = head->next,*prep = head, *q = NULL;//////////////////////////////
       
        for(;i<size;i++)
        {//p的前一个结点必须记录 
        	if(lists[i] == NULL)	continue; 
        	prep = head;////////////////////////////////
        	p = head->next;
        	if(head->val > lists[i]->val)
        	{
        		p = lists[i]->next;
        		lists[i]->next = head;
        		head = lists[i];
        		lists[i] = p;
        		p = head->next;
        		prep = head;
			}
        	while(p!=NULL && lists[i] != NULL)
        	{
        		if(p->val<lists[i]->val)
				{	
					prep = p;///////////////////////////
					p = p->next;
				}
        		else
				{
					q = lists[i]->next;
					lists[i]->next = prep->next;
					prep->next = lists[i];///////////////////////////////////////////
					prep = lists[i];
					lists[i] = q;
				} 
				//printList(head,"head"); 
				//printList(lists[i],"lists"); 
			}
			if(p == NULL) prep->next = lists[i];
			//printList(head,"head------"); 
			//printList(lists[i],"lists------"); 			
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

//功能测试，
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
	
	vector<ListNode> list3;
	int arr3[5] = {4,6,7,12,19};
	ListNode *head3 = listCreate(list3,arr3, 5);
	printList(head3,"head3");
	
	vector<ListNode* > list;
	list.push_back(head1);
	list.push_back(head2);
	list.push_back(head3);
	
	Solution so;
	ListNode *head0 = so.mergeKLists(list);
	printList(head0,"head0");
	int arr0[15] = {0,1,2,3,4,4,5,6,6,7,7,8,9,12,19};
	CheckList(head0,arr0,15);
	//printList(head,"head");
}
void test1()
{
	vector<ListNode> list1;
	int arr1[5] = {-1,1};
	ListNode *head1 = listCreate(list1,arr1, 2);
	printList(head1,"head1");
	
	vector<ListNode> list2;
	int arr2[5] = {-3,1,4};
	ListNode *head2 = listCreate(list2,arr2, 3);
	printList(head2,"head2");
	
	vector<ListNode> list3;
	int arr3[5] = {-2,-1,0,2};
	ListNode *head3 = listCreate(list3,arr3, 4);
	printList(head3,"head3");
	
	vector<ListNode* > list;
	list.push_back(head1);
	list.push_back(head2);
	list.push_back(head3);
	
	Solution so;
	ListNode *head0 = so.mergeKLists(list);
	printList(head0,"head0");
	int arr0[15] = {-3,-2,-1,-1,0,1,1,2,4};
	CheckList(head0,arr0,9);
	//printList(head,"head");
}
int main()
{
	//test0();
	test1();
	return 0;
}
