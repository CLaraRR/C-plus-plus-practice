#include <iostream>
using namespace std;

struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *L = new ListNode(0);
		L->next = head;
		ListNode *p = head, *q = head;
		ListNode *pre = L;
		while (--n)
			q = q->next;
		while (q->next != NULL){
			pre = pre->next;
			p = p->next;
			q = q->next;
		}
		pre->next = p->next;
		delete(p);
		return L->next;
	}
};