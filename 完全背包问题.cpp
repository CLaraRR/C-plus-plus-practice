#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn = 1000;

int n, capacity; //n件物品，容量为capacity的背包
int w[maxn], v[maxn]; //每件物品的重量，和每件物品的价值
int dp[maxn][maxn]; //dp[i][j]表示容量为j时，前i件物品的最佳组合装进去所获得的最大价值（前i件不一定都装进去）


int getMaxValue(){
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= capacity; j++){
			if (i == 0 || j == 0){ //边界
				dp[i][j] = 0;
			}
			else if (j < w[i]){ //如果容量j小于当前物品的重量w[i],则装不进去
				dp[i][j] = dp[i - 1][j];
			}
			else{ //如果当前物品可以装进去，那么可以选择“装”或者“不装”
				dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i]] + v[i]);	//如果“不装”，则容量为j时前i件物品的最大价值等于容量为j时前i-1件物品的最大价值
				//如果“装”，则容量为j时前i件物品的最大价值等于当减去当前物品的重量得到的剩余容量为j-w[i]时前i件物品的最大价值，然后再加上当前物品的价值所得到的价值
				//最终dp[i][j]的值为上面两个值中取较大的那一个
			}
		}
	}
	return dp[n][capacity]; //最后的那个元素就是获得的最大价值
}



int main(){
	cin >> n >> capacity;
	for (int i = 0; i < n; i++)
		cin >> w[i];
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int maxValue = getMaxValue();
	cout << maxValue << endl;

	system("pause");
	return 0;


}