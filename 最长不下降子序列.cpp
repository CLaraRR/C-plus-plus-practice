#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn = 1000;
int A[maxn], dp[maxn];

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> A[i];
	}
	int maxlen = -1; //记录最大的dp[i]
	for (int i = 0; i < n; i++){ //按顺序计算出dp[i]的值
		dp[i] = 1; //边界初始条件（即先假设每个元素自成一个序列）
		for (int j = 0; j < i; j++){
			if (A[j]<=A[i] && dp[j] + 1>dp[i]){ //状态转移条件
				dp[i] = dp[j] + 1; //状态转移方程，用以更新dp[i]
			}
		}
		maxlen = max(maxlen, dp[i]);
	}
	cout << maxlen << endl;
	system("pause");
	return 0;
}