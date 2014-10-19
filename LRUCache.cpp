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
*/
class ListNode1 {
public:
    ListNode1(int _key, int _val) {
        key = _key;
        val = _val;
        pre = next = NULL;
    }

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
        this->capacity = capacity;
        head = NULL;
        size = 0;
    }
    
    int get(int key) {
        if(mp.count(key) == 0)//����ʧ�� 
            return -1;
        int value = mp[key]->val;
        set(key, value);		//�����������setһ�� �����ܰ��������Ƶ�ͷ��� 
        return value;
    }
    
    void set(int key, int value) {
        if(capacity == 1) {				//���⿼�ǣ�ֻ��һ������ֱ���滻 
            mp.clear();
            head = new ListNode1(key, value);
            mp[key] = head;
            return;
        }
        if(mp.count(key) > 0) {			//��������� 
            ListNode1 *curNode = mp[key];
            curNode->val = value;		//���ܶ�ԭ����key��value�����޸� 
            
            if(curNode == head)			//�����������ͷ����������� 
                return;

            curNode->pre->next = curNode->next;
            curNode->next->pre = curNode->pre;

            head->pre->next = curNode;	//����һ������˫��������һ���ǰѵ�Ȼ��㻻��ͷ��ȥ 
            curNode->pre = head->pre;
            curNode->next = head;
            head->pre = curNode;		
            head = curNode;
            
            return;
        }

		//�����Ǵ����㲻���ڵ����� 
        if(size < capacity) {//����ʣ��ռ䣬�½�һ����㣬�ҵ�����ͷ            
            size ++;
            ListNode1 *newNode = new ListNode1(key, value);
            mp[key] = newNode;
            if(size == 1) {//������ǵ�һ����� 
                newNode->pre = newNode;
                newNode->next = newNode;
                head = newNode;
                return;
            }
            
            head->pre->next = newNode;	//1-ǰָ��new 
            newNode->pre = head->pre;	//2-newǰָ 
            newNode->next = head;		//3-new��ָ 
            head->pre = newNode;		//4-��ָ��new 
            head = newNode;
            return;
        }
        // size >= capacity  ������Ҫ����һ����� ��ʱֻҪ��map��ɾ��ԭ���ļ�¼�������¼�һ����¼�� 
        ListNode1 *tail = head->pre;
        mp.erase(mp.find(tail->key));
        mp[key] = tail;		//����Ҫɾ�������㣬ֻҪ��β�����³��µ�key��valueȻ��β��ͷ�Ϳ����ˡ� 
        tail->key = key;
        tail->val = value;
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

