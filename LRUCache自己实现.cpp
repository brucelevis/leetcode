/*
���뻷��CFree 5.0 
*/
 #include <iostream>
#include <map>
using namespace std;

/*
Ҫ��1��ʹ��˫�����������ɾ���ǳ����㣬ֻ�Ƕ�λ��ĳ����㣬�Ϳ���ɾ����
		����������Ҫ��¼pre������
Ҫ��2���������룬 
Ҫ��3�������סͷ���������ԡ�

debug��¼��
1- ����д���mp[key].count����map����Ϥ��ԭ�� 
2- ���ﾹȻд���� head->pre - curNode; �����Ĵ���Ҫ����
3- ͷ��� 
*/
class ListNode1 {
public:
    ListNode1(int _key, int _val):key(_key),val(_val),pre(NULL),next(NULL) {}

    ListNode1 *pre;
    int key;
    int val;
    ListNode1 *next;
};


 /*
������ ��ӡ�������� 
*/
void printList(ListNode1 *head,char *name)
{
	if(head == NULL)
		return;
	
	printf("%10s list:",name);
	
	ListNode1* p = head->next;
	printf(" (%d,%d) ",head->key,head->val);
	while(p != NULL && p != head)
	{
		printf(" (%d,%d) ",p->key,p->val);
		p = p->next;
	} 
	printf("\n");
}

class LRUCache{
public:
    LRUCache(int capacity) {
    	this->capacity = capacity;			//this��һ��ָ�� 
    	this->size = 0;
    	this->head = NULL;
    }
    
    int get(int key) {
       if(mp.count(key) == 0)				//����д���mp[key].count 
       		return -1;
   		int value = mp[key]->val;			//mp[key]��һ�� ListNode1*���� 
   		set(key,value);
		return value; 
    }
    
    void set(int key, int value) {
       if(this->capacity < 1) return;
       if(this->capacity == 1)				//ֱ���滻
	   {
	   		mp.clear();
	   		head = new ListNode1(key,value);
			mp[key] = head;
			return; 
	   } 
	   //������Ѿ�����
	   if(mp.count(key) > 0)
	   {
	   		//�����ժ�·ŵ�ͷ��
			ListNode1 *cur = mp[key];
			cur->val = value;
			if(cur == head)					//�ж��Ƿ���ͷ��� 
				return;
			//ժ��
			cur->pre->next = cur->next;
			cur->next->pre = cur->pre;
			//�ŵ�ͷ
			head->pre->next= cur;
			cur->pre = head->pre;
			cur->next = head;
			head->pre = cur;				//���ﾹȻд���� head->pre - curNode; �����Ĵ���Ҫ���� 
			head = cur;
			
			return;			 
	   } 
	   if(size < capacity)					//���в�����ͷ�����һ����� 
	   {
	   		size++;
	   		ListNode1 *cur = new ListNode1(key,value);
			mp[key] = cur;
			//����ǵ�һ�����				��������
			if(size == 1)
			{				
				cur->next= cur;
				cur->pre= cur;
				head = cur;
				return;
			} 
			
			//�ŵ�ͷ
			head->pre->next= cur;
			cur->pre = head->pre;
			cur->next = head;
			head->pre = cur;
			head = cur;	
	   		return; 
	   } 
	   //������ˣ�ֻ��Ҫ��β�����Ϣ�ĳ����£�ͬʱ��β���ĳ��½�㣬����Ҫ�������
	   ListNode1 *tail = head->pre;
	   //mp.erase(mp.find(tail->key));
	   mp.erase(tail->key);//���ַ�������һ�ַ��������� 
	   mp[key] = tail;
	   tail->key=key;
	   tail->val=value;
	   head = tail;
	    
    }
private:
    int capacity;
    int size;
    map<int, ListNode1*> mp;
public:
    ListNode1 *head;
};

/*
LRU��least recently used������ʹ�á�
���� ����Ϊ 4 3 4 2 3 1 4 2
�������3�� ��
���� 4�����ڴ� 4
���� 3�����ڴ� 3 4
֮�� 4�����ڴ� 4 3
֮�� 2�����ڴ� 2 4 3
֮�� 3�����ڴ� 3 2 4
֮�� 1�����ڴ� 1 3 2����Ϊ����ʹ�õ���4�����Զ���4��
֮�� 4�����ڴ� 4 1 3��ԭ��ͬ�ϣ�
��� 2�����ڴ� 2 4 1
*/
int main()
{
	int input[8] = {4,3,4,2,3,1,4,2};
	LRUCache lr(3);
	for(int i = 0;i<8;i++)
	{
		lr.set(input[i],i);	
		printf("%d ",input[i]);
		printList(lr.head,"1");
	}
} 

