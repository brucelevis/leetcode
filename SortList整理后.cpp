/*
编译环境：CFree 5.0
*/
#include <iostream>
#include <vector>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *sortList(ListNode *head) {
    	//printList(head,"1");
    	//指针类题目开始先要判断是否为空 
		if(head == NULL)
    		return NULL;
   		if(head->next == NULL )
		   return head;
		//利用快慢指针查找中间点
		ListNode *slow = head;
		ListNode *fast = head;
	 	ListNode *mid = head;
	 	while(fast->next != NULL && fast->next->next != NULL)
		 {
		 	fast = fast->next;
		 	fast = fast->next;
		 	slow = slow->next; 
		 } 
		 mid = slow->next;
		 slow->next = NULL;//把前半部分最后一个结点置NULL 
		 //递归开始 
		 head = sortList(head);
		 mid = sortList(mid);
		 //进行规并排序
		 //printList(head,"a");
		 //printList(mid,"b");
		 head = mergeSort(head,mid);//要明白指针是传值进去的，改变这里的head，原来head的实参的值没变	
		 //printList(head,"2");
		 return head;	 
    }
    ListNode *mergeSort(ListNode *list0, ListNode *list1) {
    	//还是一样开关判断是否为空 
  		if(list0 == NULL) return list1;
  		if(list1 == NULL) return list0;
  		
		ListNode *head = NULL, *temp = NULL;
		
		//取其中小的，也就是递增排序
		if(list0->val < list1->val)//链表的头需要特殊考虑，这是一个重点 
		{
			head = list0;
			list0 = list0->next; 			
		}
		else
		{
			head = list1;
			list1 = list1->next; 
		}
		temp = head;
		while(list0 != NULL && list1 != NULL)
    	{
    		if(list0->val < list1->val)
    		{
    			temp->next = list0;
    			temp = temp->next;
    			list0 = list0->next; 
    		}
    		else
    		{
    			temp->next = list1;
    			temp = temp->next;
    			list1 = list1->next; 
			}
		}
		if(list0 == NULL) temp->next = list1;
		if(list1 == NULL) temp->next = list0;
		return head;
    }
};
ListNode *listCreate(vector<ListNode> &listnode, int input[],int n)
{
	if(n < 1)
 		return NULL;
 		
 	for(int i = 0;i<n;i++)
	 {
	 	ListNode temp(input[i]);
	 	listnode.push_back(temp); 
	 }	
	
	ListNode *p = NULL;	
	listnode[0].next = NULL;
	listnode[0].val = input[0];
	
	p = &listnode[0];
	for(int i = 1;i<n;i++)
	{
		listnode[i].next = NULL;
		listnode[i].val = input[i];
		p->next = &listnode[i];
		p = &listnode[i];
	}
	p = &listnode[0];
	return p;
}
void checkList(ListNode *head,int n)
{
	int ret = 1;
	if(head == NULL)
	{
		if(n != 0) cout<<"----------------failed"<<endl;
		else	   cout<<"----------------passed"<<endl;
		return;
	}
	ListNode *p = NULL,*prep = NULL;//每一个前面要加 * 
	prep = head;
	p = head->next;
	printf("list:%3d",prep->val);
	int i = 1;
	while(p != NULL)
	{
		if(prep->val > p->val)
		{
			ret = 0;
		}
		prep = p;
		p = p->next;
		i++;
		printf("%3d",prep->val);
	}
	if(i == n && ret == 1)	cout<<"---passed"<<endl;
	else	   				cout<<"---failed"<<endl;
	return;
	
}
void test1()
{
	vector<ListNode> listnode;//最多含100个数据 
	int test[10] = {0,1,2,3,4,5,6,7,8,9};//正序
    ListNode *temp = listCreate(listnode,test,10);
	Solution so;
    temp = so.sortList(temp);
    checkList(temp,10);
    listnode.clear();
}
void test2()
{
	vector<ListNode> listnode;//最多含100个数据 
	int test[10] = {9,8,7,6,5,4,3,2,1,0};//逆序 
    ListNode *temp = listCreate(listnode,test,10);
	Solution so;
    temp = so.sortList(temp);
    checkList(temp,10);
    listnode.clear();
}
void test3()
{
	vector<ListNode> listnode;//最多含100个数据 
	int test[200] = {9,8,7,6,5,48,3,2,1,0,48,12,25,86,41,47,32,58,69,1,20,45,6};//随机带重复 
    ListNode *temp = listCreate(listnode,test,20);
	Solution so;
    temp = so.sortList(temp);
    checkList(temp,20);
    listnode.clear();
}
int main()
{
	test1();
	test2();
	test3();
}
