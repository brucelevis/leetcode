/*
编译环境CFree 5.0 
*/
#include <iostream>
#include <map>
using namespace std;

/*
要点1：使用双向链表，插入和删除非常方便，只是定位到某个结点，就可以删除，
		单身链表需要记录pre结点才行
要点2：特殊输入， 
要点3：链表记住头结点的特殊性。
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
调试用 打印环形链表 
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
        if(mp.count(key) == 0)//查找失败 
            return -1;
        int value = mp[key]->val;
        set(key, value);		//如果存在重新set一次 ，才能把这个结点移到头结点 
        return value;
    }
    
    void set(int key, int value) {
        if(capacity == 1) {				//特殊考虑，只有一个结点果直接替换 
            mp.clear();
            head = new ListNode1(key, value);
            mp[key] = head;
            return;
        }
        if(mp.count(key) > 0) {			//这个结点存在 
            ListNode1 *curNode = mp[key];
            curNode->val = value;		//可能对原来的key的value进行修改 
            
            if(curNode == head)			//如果这个结点是头结点则不做处理 
                return;

            curNode->pre->next = curNode->next;
            curNode->next->pre = curNode->pre;

            head->pre->next = curNode;	//这是一个环形双向链表，这一步是把当然结点换到头上去 
            curNode->pre = head->pre;
            curNode->next = head;
            head->pre = curNode;		
            head = curNode;
            
            return;
        }

		//下面是处理结点不存在的情形 
        if(size < capacity) {//还有剩余空间，新建一个结点，挂到链表头            
            size ++;
            ListNode1 *newNode = new ListNode1(key, value);
            mp[key] = newNode;
            if(size == 1) {//如果这是第一个结点 
                newNode->pre = newNode;
                newNode->next = newNode;
                head = newNode;
                return;
            }
            
            head->pre->next = newNode;	//1-前指向new 
            newNode->pre = head->pre;	//2-new前指 
            newNode->next = head;		//3-new后指 
            head->pre = newNode;		//4-后指向new 
            head = newNode;
            return;
        }
        // size >= capacity  这里需要更新一个结点 这时只要从map中删除原来的记录，重新新加一条记录。 
        ListNode1 *tail = head->pre;
        mp.erase(mp.find(tail->key));
        mp[key] = tail;		//不需要删除链表结点，只要改尾结点更新成新的key和value然后尾做头就可以了。 
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
LRU（least recently used）最少使用。
假设 序列为 4 3 4 2 3 1 4 2
物理块有3个 则
首轮 4调入内存 4
次轮 3调入内存 3 4
之后 4调入内存 4 3
之后 2调入内存 2 4 3
之后 3调入内存 3 2 4
之后 1调入内存 1 3 2（因为最少使用的是4，所以丢弃4）
之后 4调入内存 4 1 3（原理同上）
最后 2调入内存 2 4 1
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

