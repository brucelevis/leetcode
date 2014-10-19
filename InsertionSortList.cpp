#include <iostream>
#include <vector>
using namespace std;

/*
调试记录
bug1：if(head->next == NULL)//第一次这里写成的 = 粗心呀！ 
bug2： 

*/
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
 /*
调试用 
*/
void printList(ListNode *head,char *name)
{
	if(head == NULL)
		return;
	printf("%10s list:",name);
	while(head != NULL)
	{
		printf("%3d",head->val);
		head = head->next;
	} 
	printf("\n");
}
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL)
        	return NULL;
       	if(head->next == NULL)//第一次这里写成的 = 粗心呀！ 
       		return head;
  		//此时 链表里至少两个结点
  		
		ListNode *tmphead = NULL,*p = NULL;
        //把head第一个结点取下放到tmphead里 
        tmphead = head;//到这里 head中至少有一个结点 
		head = head->next; 
		tmphead->next= NULL;
        while(head != NULL)
        {
        	//把head结点取下来	
        	p = head;       	
        	head = head->next; 
        	p->next= NULL;
        	ListNode *cur = tmphead, *precur = tmphead;
        	
        	while(cur != NULL) 
        	{
        		if(p->val <= cur->val)//p放到cur前面 ,也就是 tmphead的后面 
				{
					if(cur == tmphead) //cur是第一个点
					{
						p->next = cur;
						tmphead = p; 
						cur = tmphead;
						precur = tmphead;
						break;
					} 
					else
					{
						p->next = cur;
						precur->next = p;
						break;
					}
				}
				precur = cur;				
				cur = cur->next;
			}
			if(cur == NULL)//如果遍历了整个链表，那个新结点应该放到链表最后
			{
				precur->next = p;
				p->next = NULL; 
			} 
		}//enc of while(head != NULL)
		return tmphead;
    }
};
/*
创建一个链表
*/
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
	if(i == n && ret == 1)	cout<<"-----------passed"<<endl;
	else	   				cout<<"-----------failed"<<endl;
	return;	
}
void test1()
{
	vector<ListNode> listnode;//最多含100个数据 
	int test[10] = {0,1,2,3,4,5,6,7,8,9};//正序
    ListNode *temp = listCreate(listnode,test,10);
	Solution so;
	printList(temp,"处理前");
    temp = so.insertionSortList(temp);
    checkList(temp,10);
    listnode.clear();
}
void test2()
{
	vector<ListNode> listnode;//最多含100个数据 
	int test[10] = {9,8,7,6,5,4,3,2,1,0};//逆序 
    ListNode *temp = listCreate(listnode,test,10);
	Solution so;
	//printList(temp,"处理前");
    temp = so.insertionSortList(temp);
    checkList(temp,10);
    listnode.clear();
}
void test3()
{
	vector<ListNode> listnode;//最多含100个数据 
	int test[200] = {9,8,7,6,5,48,3,2,1,0,48,12,25,86,41,47,32,58,69,1,20,45,6};//随机带重复 
    ListNode *temp = listCreate(listnode,test,20);
    //printList(temp,"no sort");
	Solution so;
    temp = so.insertionSortList(temp);
    checkList(temp,20);
    listnode.clear();
}
int main()
{
	//我个人喜欢使用日志的形式查看输出 
	freopen("log.txt","w",stdout) ;
	test1();
	test2();
	
	test3();
	freopen("CON","w",stdout) ;
	system("log.txt"); 
}
