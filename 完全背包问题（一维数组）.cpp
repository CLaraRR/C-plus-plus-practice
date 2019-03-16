#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn = 1000;

int n, capacity; //n件物品，容量为capacity的背包
int w[maxn], v[maxn]; //每件物品的重量，和每件物品的价值
int dp[maxn]; //滚动数组，记每个物品为一个阶段，滚动每个阶段，dp[j]表示容量为j时，前i件物品的最佳组合装进去所获得的最大价值（前i件不一定都装进去）


int getMaxValue(){
	for (int i = 1; i <= n; i++){
		for (int j = w[i]; j <= capacity; j++){
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);	
		}
	}
	return dp[capacity]; //最后的那个元素就是获得的最大价值
}



int main(){
	cin >> n >> capacity;
	for (int i = 0; i < n; i++)
		cin >> w[i];
	for (int i = 0; i < n; i++)
		cin >> v[i];

	//初始化边界
	for (int i = 0; i <= capacity; i++){
		dp[i] = 0;
	}
	int maxValue = getMaxValue();
	cout << maxValue << endl;

	system("pause");
	return 0;


}