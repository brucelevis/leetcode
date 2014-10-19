/*
编译环境CFree 5.0 

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
    bool hasCycle(ListNode *head) {
		if(head == NULL)
			return false;
		ListNode *slow = head;
		ListNode *fast = head;
		while(fast->next != NULL && fast->next->next != NULL) 
		{
			slow = slow->next;
	  		fast = fast->next;
	  		fast = fast->next; 
			if(fast == slow)			//一开始都是head，所以不能直接判断，需要进行一次移动后再判断 
			  return true;	  		
		}
		return false; 
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

//有环 
void test0()
{
	vector<ListNode> list;
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	ListNode *head = listCreate(list,arr, 10);
	printList(head,"head");
	list[9].next = &list[3];//制造一个环 
	Solution so;
	if(so.hasCycle(head) == false)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");

}
//无环 
void test1()
{
	vector<ListNode> list;
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	ListNode *head = listCreate(list,arr, 10);
	printList(head,"head");
	//list[9].next = &list[3];//制造一个环 
	Solution so;
	if(so.hasCycle(head) == true)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");

}


int main()
{
	test0();
	test1(); 
	return 0;
}

