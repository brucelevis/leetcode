/*
���뻷��CFree 5.0 

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
			if(fast == slow)			//��һ������������ 
			  break;	  		
		}
		//��slow�õ�head��fast�ٶȸ�Ϊ1
		slow = head; 
		while(fast->next != NULL && fast->next->next != NULL) 
		{
			if(fast == slow)			//������Ҫ�ƶ�ǰ�棬��Ϊ�����Ŀ��ܾ���ͷ��� 
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

//�л� 
void test0()
{
	vector<ListNode> list;
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	ListNode *head = listCreate(list,arr, 10);
	printList(head,"head");
	list[9].next = &list[3];//����һ���� 
	Solution so;
	if(so.detectCycle(head) != &list[3])
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");

}
//�޻� 
void test1()
{
	vector<ListNode> list;
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	ListNode *head = listCreate(list,arr, 10);
	printList(head,"head");
	//list[9].next = &list[3];//����һ���� 
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
	list[1].next = &list[0];//����һ���� 
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

