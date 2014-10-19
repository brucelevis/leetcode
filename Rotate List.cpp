/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;
 struct ListNode {
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
 // 是实现循环右移k次 
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;
        
        ListNode *p = head->next,*prep = head;
        int i = 0;
        while(++i<k&&p!=NULL)
			p=p->next;	
		if(p == NULL)//////////////////////
		{
			k = k%(i);//i是链表长度//////////////////////////////////////i+1还是i 
			if(k == 0)	return head; /////////////////////////////////////
			i = 0;///////////////////////////////////
			p = head->next; 
			while(++i<k&&p!=NULL)
				p=p->next;
		} 
		
		while(p->next != NULL)
		{
			prep = prep->next;
			p = p->next;
		}
		p->next = head;
		head = prep->next;
		prep->next = NULL;
		return head;
    }
}; 
 /**
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL || head->next == NULL || k < 0) return head;
        
        ListNode *p = head->next,*prep = head;
        int i = 0;
        while(i++<k&&p!=NULL)
        {
        	prep = p;
			p=p->next;	
		}
		if(p == NULL) return head;
		prep->next = NULL;
		prep = p;
		while(prep->next != NULL)
			prep = prep->next;
		prep->next = head;
		return p;
    }
};
*/
void test0()
{
	if(1)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
int main()
{
	test0();
	return 0;
}