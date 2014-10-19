#include <iostream>
#include <vector>
using namespace std;
/*
�ܽ᣺
���Թ��������������⼰�������
��д�������������õķ������Ȱѳ�ʼ�����ݷ���һ��vector�����һ�������о�����������õģ�
				��ʱ���ã����ֺõ��ٻ���
 
ListNode *sortList(ListNode *head) ����head�ں������޸�ָ�������ǲ�Ӱ��ʵ����ԭ��
	������Ľ���ģ��ź����Ҫ�÷���ֵ���س��������������ϳ������⡣��Ҳ���Լ���
	�����ϳ�������ĵط��� 

ListNode *listCreate(vector<ListNode> &listnode, int input[],int n) ������Ҫʹ������
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
	printf("%s list:",name);
	while(head != NULL)
	{
		printf("%3d",head->val);
		head = head->next;
	} 
	printf("\n");
}
#if 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next !=NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
        }
        ListNode *tmp_head = slow->next;
        slow->next = NULL;
        head = sortList(head);
        tmp_head = sortList(tmp_head);
        
        ListNode *ret_head = NULL;
        if(head->val <= tmp_head->val)
        {
            ret_head = head;
            head = head->next;
        }
        else
        {
            ret_head = tmp_head;
            tmp_head = tmp_head->next;
        }
        ret_head->next = NULL;
        ListNode *p = ret_head;
        while(head != NULL && tmp_head != NULL)
        {
            if(head->val <= tmp_head->val)
            {
                p->next = head;
                head = head->next;
            }
            else
            {
                p->next = tmp_head;
                tmp_head = tmp_head->next;
            }
            p = p->next;
            p->next = NULL;
        }
        if(head != NULL)
            p->next = head;
        if(tmp_head != NULL)
            p->next = tmp_head;
        
        return ret_head;
    }
};


#elif 1
class Solution {
public:
    ListNode *sortList(ListNode *head) {
    	//printList(head,"1");
    	//ָ������Ŀ��ʼ��Ҫ�ж��Ƿ�Ϊ�� 
		if(head == NULL)
    		return NULL;
   		if(head->next == NULL )
		   return head;
		//���ÿ���ָ������м��
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
		 slow->next = NULL;//��ǰ�벿�����һ�������NULL 
		 //�ݹ鿪ʼ 
		 head = sortList(head);
		 mid = sortList(mid);
		 //���й沢����
		 //printList(head,"a");
		 //printList(mid,"b");
		 head = mergeSort(head,mid);//Ҫ����ָ���Ǵ�ֵ��ȥ�ģ��ı������head��ԭ��head��ʵ�ε�ֵû��	
		 //printList(head,"2");
		 return head;	 
    }
    ListNode *mergeSort(ListNode *list0, ListNode *list1) {
    	//����һ�������ж��Ƿ�Ϊ�� 
  		if(list0 == NULL) return list1;
  		if(list1 == NULL) return list0;
  		
		ListNode *head = NULL, *temp = NULL;
		
		//ȡ����С�ģ�Ҳ���ǵ�������
		if(list0->val < list1->val)//�����ͷ��Ҫ���⿼�ǣ�����һ���ص� 
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
#endif
/*
��ô����һ��������ô��ѽ����ǿ�����ַ�����ϣ���и��ֽ��Ҹ��߼��ķ����� 

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
    temp = so.sortList(temp);
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
    temp = so.sortList(temp);
    checkList(temp,10);
    listnode.clear();
}
void test3()
{
	vector<ListNode> listnode;//��ຬ100������ 
	int test[200] = {9,8,7,6,5,48,3,2,1,0,48,12,25,86,41,47,32,58,69,1,20,45,6};//������ظ� 
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
