/*
给定一个有向无环图（DAG），求解整个图的所有路径中权值之和最大的那条。
用dp[i]表示从i号顶点出发能获得的最长路径长度
*/
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1000;
const int INF = 0x3fffffff; //一个很大的正数
const int INFS = 0xbfffffff; //一个很小的负数
int n, m, dest, G[maxn][maxn]; //节点数，边数，终点，记录有向图节点之间的权值二维数组
int dp[maxn]; //dp[i]表示从i号顶点出发能获得的最长路径长度
vector<int> post[maxn]; //记录最长路径上顶点的后继结点
bool visited[maxn] = { false };

//递归获得dp[i]
int DP(int i){
	if (visited[i])
		return dp[i]; //dp[i]已经计算得到
	visited[i] = true;
	for (int j = 0; j < n; j++){ //遍历i的所有出边
		if (G[i][j] != INF){
			int temp = DP(j) + G[i][j]; //状态转移方程
			if (temp > dp[i]){ //如果可以获得更长的路径
				dp[i] = temp; //更新dp[i]
				post[i].clear(); //之前记录的后继结点都要清除
				post[i].push_back(j); //加入新的后继节点
			}
			else if (temp == dp[i]){
				post[i].push_back(j); //如果有相同的路径长度，也将这个后继节点加入
			}
		}

	}
	return dp[i]; //返回计算完毕的dp[i]
}


//如果有多条最长路径，则输出字典序最小的路径
void printPath(int i){
	cout << i << " ";
	while (post[i].size() != 0){
		i = post[i][0];
		cout << i << " ";
	}
	cout << endl;
}

int main(){
	cin >> n >> m >> dest;
	fill(dp, dp + n, INFS);
	fill(G[0], G[0] + maxn*maxn, INF);
	dp[dest] = 0;
	int u, v, wt;
	for (int i = 0; i < m; i++){
		cin >> u >> v >> wt;
		G[u][v] = wt;
	}
	int maxdis = 0;
	int start;
	//求出从所有顶点出发到达dest能获得的最长路径dp[i]
	//则dp[i]的最大值是固定终点的整个DAG的最长路径长度
	for (int i = 0; i < n; i++){
		int dis = DP(i);
		if (dis > maxdis){
			maxdis = dis;
			start = i; //记录最长路径的起点，如果有多条最长路径则默认取字典序最小的那个起点
		}
	}
	cout << maxdis << endl;
	printPath(start); //从起点开始打印出最长路径，如果从该起点开始有多条最长路径则打印字典序最小的那条

	system("pause");
	return 0;
}