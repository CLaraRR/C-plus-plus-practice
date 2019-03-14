/* 
描述：给定一个由整数组成的集合，集合中的整数各不相同，现在要将它分为两个子集合，
使得这两个子集合的并为原集合，交为空集，同时在两个子集合的元素个数n1与n1之差的
绝对值|n1-n2|尽可能小的前提下，要求他们各自的元素之和S1与S2之差的绝对值|S1-S2|
尽可能大。
问题：求这个|S1-S2|等于多少？
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// 产生随机的中枢值
int randPartition(int A[], int left, int right){
	int p = (round(1.0*rand() / RAND_MAX*(right - left) + left));
	swap(A[p], A[left]);
	int temp = A[left];
	while (left < right){
		while (left<right&&A[right]>temp)
			right--;
		A[left] = A[right];
		while (left < right&&A[left] < temp)
			left++;
		A[right] = A[left];

	}
	A[left] = temp;
	return left;
}

int randSelect(int A[], int left, int right,int K){
	if (left == right)
		return A[left];
	int p = randPartition(A, left, right);
	int M = p - left + 1;
	if (K == M)
		return A[p];
	if (K < M){
		return randSelect(A, left, p - 1, K);
	}
	else{
		return randSelect(A, p + 1, right, K - M);
	}
}

int main(){
	srand((unsigned)time(NULL));
	int sum = 0, sum1 = 0;
	int n;
	int A[100010];
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> A[i];
		sum += A[i];
	}
	randSelect(A, 0, n - 1, n / 2);
	for (int i = 0; i < n / 2; i++){
		sum1 += A[i];
	}
	cout << (sum - sum1) - sum1 << endl;
	system("pause");
	return 0;
}