#include <iostream>
using namespace std;

/**/
// * Definition for singly-linked list with a random pointer.
 struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
   	if(head == NULL) return head;
     //克隆,把p的复制放在p后面 
	 RandomListNode *p = head;
	 while(p != NULL)
	 {
	 	RandomListNode* pclone = new RandomListNode(p->label);
		pclone->next = p->next;
		pclone->random = NULL;
		p->next = pclone; 
		p = pclone->next;
	 }
	 p = head;
	 while(p)
	 {
	 	if(p->random) p->next->random = p->random->next;
	 	p = p->next;
	 	p = p->next;
	 }   
	 RandomListNode *tmphead = head->next;
	 p = head;
	 RandomListNode *tmpp = tmphead;
	 while(p)
	 {
	 	p->next = tmpp->next;
	 	p = p->next;
	 	if(p)
	 	{
	 		tmpp->next = p->next;
	 		tmpp = tmpp->next;
	 	}
	 	else
	 		tmpp->next = NULL;
	 }
	 return tmphead;
    }
};
int main(int argc, char *argv[])
{
	
	return 0;
}