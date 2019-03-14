#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> ss;
		char c;
		for (int i = 0; i < s.size(); i++){
			switch (s[i])
			{
			case '(':ss.push(s[i]); break;
			case '[':ss.push(s[i]); break;
			case '{':ss.push(s[i]); break;
			case ')':
				if (!ss.empty()){
					c = ss.top();
					ss.pop();
				}else
					c = ' ';
				if (c != '(')
					return false;
				break;
			case ']':
				if (!ss.empty()){
					c = ss.top();
					ss.pop();
				}
				else
					c = ' ';
				if (c != '[')
					return false;
				break;
			case '}':
				if (!ss.empty()){
					c = ss.top();
					ss.pop();
				}
				else
					c = ' ';
				if (c != '{')
					return false;
				break;
			default:
				break;
			}
		}
		if (ss.empty())
			return true;
		else
			return false;
	}
};