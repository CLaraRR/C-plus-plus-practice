#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode *L = new ListNode(0);
		L->next = head;
		ListNode *m = L, *q = L, *p = head;
		while (1){
			while (p!=NULL&&p->val >= x){
				p = p->next;
				q = q->next; 
			}
			if (m != q){
				q->next = p->next;
				p->next = m->next;                                  
				m->next = p;
				p = q->next;
				m = m->next;
			}
			else{
				q = q->next;
				p = p->next;
				m = m->next;
			}
		}
		return L->next;
	}
};