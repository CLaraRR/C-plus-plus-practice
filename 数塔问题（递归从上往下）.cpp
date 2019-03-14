#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

const int maxn = 1000;
int f[maxn][maxn], dp[maxn][maxn];
int n;

int tower(int i, int j){
	//边界
	if (i == n)
		return dp[i][j];
	if (dp[i][j] != -1)
		return dp[i][j];
	else{
		dp[i][j] = max(tower(i + 1, j), tower(i + 1, j + 1)) + f[i][j];//状态转移方程
		return dp[i][j];
	}
}
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= i; j++){
			cin >> f[i][j];
		}
	}
	//边界
	for (int j = 1; j <= n; j++){
		dp[n][j] = f[n][j];

	}

	//其他dp[i][j]赋初值为-1
	for (int i = 1; i <= n - 1; i++){
		for (int j = 1; j <= i; j++){
			dp[i][j] = -1;
		}
	}
	
	//递归求解
	int maxlen = tower(1, 1);
	cout << maxlen << endl;
	system("pause");

	return 0;
}