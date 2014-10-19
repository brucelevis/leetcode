#include <iostream>
#include <vector>
using namespace std;

/*
���Լ�¼
bug1��if(head->next == NULL)//��һ������д�ɵ� = ����ѽ�� 
bug2�� 

*/
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
 /*
������ 
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
       	if(head->next == NULL)//��һ������д�ɵ� = ����ѽ�� 
       		return head;
  		//��ʱ �����������������
  		
		ListNode *tmphead = NULL,*p = NULL;
        //��head��һ�����ȡ�·ŵ�tmphead�� 
        tmphead = head;//������ head��������һ����� 
		head = head->next; 
		tmphead->next= NULL;
        while(head != NULL)
        {
        	//��head���ȡ����	
        	p = head;       	
        	head = head->next; 
        	p->next= NULL;
        	ListNode *cur = tmphead, *precur = tmphead;
        	
        	while(cur != NULL) 
        	{
        		if(p->val <= cur->val)//p�ŵ�curǰ�� ,Ҳ���� tmphead�ĺ��� 
				{
					if(cur == tmphead) //cur�ǵ�һ����
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
			if(cur == NULL)//������������������Ǹ��½��Ӧ�÷ŵ��������
			{
				precur->next = p;
				p->next = NULL; 
			} 
		}//enc of while(head != NULL)
		return tmphead;
    }
};
/*
����һ������
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
	ListNode *p = NULL,*prep = NULL;//ÿһ��ǰ��Ҫ�� * 
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
	vector<ListNode> listnode;//��ຬ100������ 
	int test[10] = {0,1,2,3,4,5,6,7,8,9};//����
    ListNode *temp = listCreate(listnode,test,10);
	Solution so;
	printList(temp,"����ǰ");
    temp = so.insertionSortList(temp);
    checkList(temp,10);
    listnode.clear();
}
void test2()
{
	vector<ListNode> listnode;//��ຬ100������ 
	int test[10] = {9,8,7,6,5,4,3,2,1,0};//���� 
    ListNode *temp = listCreate(listnode,test,10);
	Solution so;
	//printList(temp,"����ǰ");
    temp = so.insertionSortList(temp);
    checkList(temp,10);
    listnode.clear();
}
void test3()
{
	vector<ListNode> listnode;//��ຬ100������ 
	int test[200] = {9,8,7,6,5,48,3,2,1,0,48,12,25,86,41,47,32,58,69,1,20,45,6};//������ظ� 
    ListNode *temp = listCreate(listnode,test,20);
    //printList(temp,"no sort");
	Solution so;
    temp = so.insertionSortList(temp);
    checkList(temp,20);
    listnode.clear();
}
int main()
{
	//�Ҹ���ϲ��ʹ����־����ʽ�鿴��� 
	freopen("log.txt","w",stdout) ;
	test1();
	test2();
	
	test3();
	freopen("CON","w",stdout) ;
	system("log.txt"); 
}
