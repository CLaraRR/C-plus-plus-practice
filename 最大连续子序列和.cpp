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

	dp[0] = A[0];//边界
	int maxsum = dp[0];
	for (int i = 1; i < n; i++){
		dp[i] = max(dp[i - 1] + A[i], A[i]); //状态转移方程
		maxsum = max(maxsum, dp[i]);

	}

	cout << maxsum << endl;
	system("pause");
	return 0;

}