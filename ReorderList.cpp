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
    void reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL)//两个以下结点返回NULL 
        	return;
       	//这里至少有三个结点
		ListNode *slow = head, *fast = head, *mid  = head;
		//快慢指针找到中点 
		while(fast->next != NULL && fast->next->next != NULL)
		{
			slow=slow->next;
			fast=fast->next;
			fast=fast->next; 
		} 
		mid = slow->next;
		slow->next = NULL;
		//把mid后面的反序挂起来 
		ListNode *tmphead = mid;		
		mid = mid->next;
		tmphead->next = NULL;					//注意单身非循环链表最后要置NULL ，以及什么时置NULL，一定要让后面的结点用变量记录下来才可能置NULL 
		
		while(mid != NULL)
		{
			ListNode *p = mid;
			mid = mid->next;
			p->next=tmphead;
			tmphead = p;
		}
		//把tmphead中的结点间隔插入head列中 
		ListNode *q = head;
		while(tmphead != NULL)
		{
			ListNode *p = tmphead;
			tmphead = tmphead->next;
			//p插到q后面 
			p->next = q->next; 
			q->next = p;
			q = p->next; 
		} 
		return;
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
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	ListNode *head = listCreate(list,arr, 10);
	printList(head,"head");
	Solution so;
	so.reorderList(head);
	int arr1[10] = {0,9,1,8,2,7,3,6,4,5};
	CheckList(head,arr1,10);
	//printList(head,"head");
}
//特殊输入，只有一个元素 
void test1()
{
	vector<ListNode> list;
	int arr[1] = {0};
	ListNode *head = listCreate(list,arr, 1);
	printList(head,"head");
	Solution so;
	so.reorderList(head);
	int arr1[1] = {0};
	CheckList(head,arr1,1);
	//printList(head,"head");
}
//奇数个元素 
void test2()
{
	vector<ListNode> list;
	int arr[3] = {0,1,2};
	ListNode *head = listCreate(list,arr, 3);
	printList(head,"head");
	Solution so;
	so.reorderList(head);
	int arr1[3] = {0,2,1};
	CheckList(head,arr1,3);
	//printList(head,"head");
}
void test3()
{
	Solution so;
	so.reorderList(NULL);
}

int main()
{
	test0();
	test1();
	test2();
	test3();
	return 0;
}


 