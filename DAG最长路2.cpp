/*
给定一个有向无环图（DAG），求解整个图的所有路径中权值之和最大的那条。
用dp[i]表示以i号结尾能获得的最长路径长度
*/
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1000;
const int INF = 0x3fffffff;
int n, m, G[maxn][maxn]; //节点数，边数，记录有向图节点之间的权值二维数组
int dp[maxn]; //dp[i]表示以i号结尾出发能获得的最长路径长度
vector<int> pre[maxn]; //记录最长路径上顶点的前继结点

//递推获得所有的dp[i]
void DP(){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (G[i][j] != INF){
				int temp = dp[i] + G[i][j]; //状态转移方程
				if (temp > dp[j]){ //如果可以获得更长的路径
					dp[j] = temp; //更新dp[i]
					pre[j].clear(); //之前记录的前继结点都要清除
					pre[j].push_back(i); //加入新的前继节点
				}
				else if (temp == dp[j]){
					pre[j].push_back(i); //如果有相同的路径长度，也将这个前继节点加入
				}
			}
		}
	}
}

//如果有多条最长路径，则输出其中一条（无法输出字典序最小的）
void printPath(int i){
	if (pre[i].size() == 0){
		cout << i << " ";
		return;
	}
	printPath(pre[i][0]); //递归获得前继结点
	cout << i << " ";
}

int main(){
	cin >> n >> m;
	memset(dp, 0, sizeof(dp));
	fill(G[0], G[0] + maxn*maxn, INF);
	int u, v, wt;
	for (int i = 0; i < m; i++){
		cin >> u >> v >> wt;
		G[u][v] = wt;
	}
	
	//求出以各个顶点i为结尾的最长路径dp[i]
	//则dp[i]的最大值是整个DAG的最长路径长度
	DP();
	int maxdis = dp[0];
	int end = 0;
	for (int i = 1; i < n; i++){
		if (dp[i] > maxdis){
			maxdis = dp[i];
			end = i; //记录最长路径的终点
		}
	}
	cout << maxdis << endl;
	printPath(end); //打印出以dp[i]为结尾的最长路径，如有多条则打印其中一条

	system("pause");
	return 0;
}