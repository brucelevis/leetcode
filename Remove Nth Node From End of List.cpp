#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){} 
} ;

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head == NULL || n <= 0)	return NULL;
        ListNode *p = head ,*q = head, *preq = NULL;
        int i = 0;
        while(p != NULL && i++<n)
        	p = p->next;
       	if(p == NULL)
       	{
       		if(i < n)//�����С��n !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		   		return NULL;
  			//���������n��ȥͷ���
			head = head->next;
			return head; 
       	}
       	while(p != NULL)
       	{
			p = p->next;
			preq = q;
			q = q->next;
       	}
       	preq->next = q->next;
       	return head;
    }
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

/*
vector ����ӹ����лᶯ̬�������ڴ棬Ԫ�ص�λ�ûᶯ̬�ĵ���������
���ܱߴ���vector�ߴ��������м�ָ����ܻᶯ��

�����list��Ҫʹ�ô����� 
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
//���ܲ��ԣ�����Ϊż�� 
void test0()
{
	vector<ListNode> list;
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	ListNode *head = listCreate(list,arr, 10);
	printList(head,"head");
	Solution so;
	head = so.removeNthFromEnd(head,2);
	int arr1[9] = {0,1,2,3,4,5,6,7,9};
	CheckList(head,arr1,9);
	//printList(head,"head");
}
int main(int argc, char *argv[])
{
	test0();
	return 0;
}

