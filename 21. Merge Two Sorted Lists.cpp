#include <iostream>
using namespace std;

struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *newList = new ListNode(0);
		ListNode *p1 = l1, *p2 = l2, *m = newList;
		while (p1 != NULL&&p2 != NULL){
			if (p1->val <= p2->val){
				ListNode *newnode = new ListNode(p1->val);
				m->next = newnode;
				m = m->next;
				p1 = p1->next;
			}
			else if(p1->val > p2->val){
				ListNode *newnode = new ListNode(p2->val);
				m->next = newnode;
				m = m->next;
				p2 = p2->next;
			}
		}
		if (p1 == NULL&&p2 != NULL)
			m->next = p2;
		else if (p2 == NULL&&p1 != NULL)
			m->next = p1;
		return newList->next;
	}
};