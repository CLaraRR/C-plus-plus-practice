#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
	stack<int> s;
public:
	/** initialize your data structure here. */
	MinStack() {
		
	}

	void push(int x) {
		if (s.empty()){
			s.push(x);
			s.push(x);
		}
		else{
			int min = s.top();
			s.pop();
			if (min < x){
				s.push(x);
				s.push(min);
			}
			else{
				s.push(x);
				s.push(x);
			}
		}
	}

	void pop() {
		s.pop();
	}

	int top() { 
		int min = s.top();
		s.pop();
		int top = s.top();
		s.push(min);
		return top;
	}

	int getMin() {
		return s.top();
	}
};