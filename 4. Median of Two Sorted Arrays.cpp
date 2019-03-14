#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	double findKth(vector<int>::iterator arr1, int size1, vector<int>::iterator arr2, int size2, int k){
		if (size1 > size2)
			return findKth(arr2, size2, arr1, size1, k);
		if (size1 == 0)
			return arr2[k - 1];
		if (k == 1)
			return min(arr1[0], arr2[0]);
		int pa = min(k / 2, size1);
		int pb = k - pa;
		if (arr1[pa - 1] < arr2[pb - 1])
			return findKth(arr1 + pa, size1 - pa, arr2, size2, k - pa);
		else if (arr1[pa - 1] > arr2[pb - 1])
			return findKth(arr1, size1, arr2 + pb, size2 - pb, k - pb);
		else
			return arr1[pa - 1];


	}

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len1 = nums1.size();
		int len2 = nums2.size();
		int sum = len1 + len2;
		if (sum % 2 != 0)
			return findKth(nums1.begin(), len1, nums2.begin(), len2, sum / 2 + 1);
		else
			return (findKth(nums1.begin(), len1, nums2.begin(), len2, sum / 2)
			+ findKth(nums1.begin(), len1, nums2.begin(), len2, sum / 2 + 1)) / 2;
	}
};


int main(){

}