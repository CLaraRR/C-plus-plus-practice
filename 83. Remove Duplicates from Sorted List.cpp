#include <iostream>
#include <map>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		map<int, int> nummap;
		ListNode *p = head->next,*q=head;
		nummap.insert(make_pair(q->val, 1));
		while (p != NULL){
			if (nummap.count(p->val)){
				ListNode *m = p;
				q->next = p->next;
				p = p->next;
				delete(m);
			}
			else{
				nummap.insert(make_pair(p->val, 1));
				p = p->next;
				q = q->next;
			}
		}
		return head;
	}
};