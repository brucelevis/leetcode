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

debug记录：
1- 这里写错成mp[key].count，对map不熟悉的原因 
2- 这里竟然写成了 head->pre - curNode; 这样的错误要避免
3- 头结点 
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
    	this->capacity = capacity;			//this是一个指针 
    	this->size = 0;
    	this->head = NULL;
    }
    
    int get(int key) {
       if(mp.count(key) == 0)				//这里写错成mp[key].count 
       		return -1;
   		int value = mp[key]->val;			//mp[key]是一个 ListNode1*类型 
   		set(key,value);
		return value; 
    }
    
    void set(int key, int value) {
       if(this->capacity < 1) return;
       if(this->capacity == 1)				//直接替换
	   {
	   		mp.clear();
	   		head = new ListNode1(key,value);
			mp[key] = head;
			return; 
	   } 
	   //这个点已经存在
	   if(mp.count(key) > 0)
	   {
	   		//将结点摘下放到头部
			ListNode1 *cur = mp[key];
			cur->val = value;
			if(cur == head)					//判断是否是头结点 
				return;
			//摘下
			cur->pre->next = cur->next;
			cur->next->pre = cur->pre;
			//放到头
			head->pre->next= cur;
			cur->pre = head->pre;
			cur->next = head;
			head->pre = cur;				//这里竟然写成了 head->pre - curNode; 这样的错误要避免 
			head = cur;
			
			return;			 
	   } 
	   if(size < capacity)					//队列不满在头部添加一个结点 
	   {
	   		size++;
	   		ListNode1 *cur = new ListNode1(key,value);
			mp[key] = cur;
			//如果是第一个结点				！！！！
			if(size == 1)
			{				
				cur->next= cur;
				cur->pre= cur;
				head = cur;
				return;
			} 
			
			//放到头
			head->pre->next= cur;
			cur->pre = head->pre;
			cur->next = head;
			head->pre = cur;
			head = cur;	
	   		return; 
	   } 
	   //如果满了，只需要把尾结点信息改成最新，同时把尾结点改成新结点，不需要链表操作
	   ListNode1 *tail = head->pre;
	   //mp.erase(mp.find(tail->key));
	   mp.erase(tail->key);//这种方法和上一种方法都可以 
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

