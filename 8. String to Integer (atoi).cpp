#include <iostream>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		string newstr;
		for (int i = 0; i < str.size(); i++){
			if (str[i] == '+' || str[i] == '-'){
				newstr.push_back(str[i]);
			}
			else if (str[i] - '0' <= 9 && str[i] >= 0){

			}
		}
	}
};