#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int strlen = s.length();
		int maxlen = 0;
		map<char, int> cmap;

		for (int i = 0, j = 0; j < strlen; j++){
			if (cmap.count(s[j])){
				i = max(i, cmap.at(s[j]));
			}
			maxlen = max(maxlen, j - i + 1);
			cmap.insert(make_pair(s[j], j + 1));
		}
		return maxlen;

	}
};

int main(){

}