#include <iostream>
#include <stdlib.h>
using namespace std;

const int maxn = 1000;
int dp[maxn];

int F(int n){
	//边界
	if (n == 0 || n == 1)
		return 1;
	if (dp[n] != -1)
		return dp[n];
	else{
		dp[n] = F(n - 1) + F(n - 2);//状态转移方程
		return dp[n];
	}
}

int main(){
	int n;   
	cin >> n;
	for (int i = 0; i <= n; i++){
		dp[i] = -1;
	}
	int result = F(n);
	cout << result << endl;
	system("pause");
	return 0;
}