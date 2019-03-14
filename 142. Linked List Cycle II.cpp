#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL)
			return NULL;
		ListNode *slow = head, *fast = head;
		int hasCycle = 0;
		while (fast->next != NULL && fast->next->next != NULL){
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast){
				hasCycle = 1;
				break;
			}	
			
		}
		if (hasCycle){
			ListNode *p = head;
			while (p != slow){
				p = p->next;
				slow = slow->next;
			}
			return p;
		}
		else
			return NULL;
	}
};