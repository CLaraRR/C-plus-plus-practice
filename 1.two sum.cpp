#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int len = nums.size();
		map<int, int> nummap;
		for (int i = 0; i < len; i++){
			int another = target - nums[i];
			if (nummap.count(another)){
				vector<int> result = {nummap.at(another), i};
				return result;
			}
			nummap.insert(make_pair(nums[i], i));
		}
		throw "error";

	}


};


int main(){
	
	
}