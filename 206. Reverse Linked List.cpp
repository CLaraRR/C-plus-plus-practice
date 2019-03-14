#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *L = new ListNode(0);
		L->next = head;
		ListNode *p = head->next, *tail = head;
		while (p != NULL){
			tail->next = p->next;
			p->next = L->next;
			L->next = p;
			p = tail->next;

		}
		return L->next;
	}
};