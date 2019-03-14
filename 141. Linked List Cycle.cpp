#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == NULL)
			return false;
		ListNode *slow = head, *fast = head;
		while (slow != NULL){
			if (fast == NULL || fast->next == NULL){
				return false;
			}
			fast = fast->next->next;
			if (slow == fast)
				return true;
			slow = slow->next;
		}
		return false;
	}
};