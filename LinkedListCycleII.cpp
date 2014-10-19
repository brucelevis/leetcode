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
    ListNode* detectCycle(ListNode *head) {
		if(head == NULL)
			return NULL;
		ListNode *slow = head;
		ListNode *fast = head;
		while(fast->next != NULL && fast->next->next != NULL) 
		{
			slow = slow->next;
	  		fast = fast->next;
	  		fast = fast->next; 
			if(fast == slow)			//第一次相遇后，跳出 
			  break;	  		
		}
		//把slow置到head，fast速度改为1
		slow = head; 
		while(fast->next != NULL && fast->next->next != NULL) 
		{
			if(fast == slow)			//这里需要移动前面，因为相遇的可能就是头结点 
			  return slow;
			slow = slow->next;
	  		fast = fast->next;				  		
		}
		return NULL; 
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
	if(so.detectCycle(head) != &list[3])
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
	if(so.detectCycle(head) != NULL)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");

}

void test2()
{
	vector<ListNode> list;
	int arr[2] = {0,1};
	ListNode *head = listCreate(list,arr, 2);
	printList(head,"head");
	list[1].next = &list[0];//制造一个环 
	Solution so;
	if(so.detectCycle(head) != &list[0])
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");

}


int main()
{
	test0();
	test1(); 
	test2(); 
	return 0;
}

