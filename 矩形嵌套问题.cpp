/*
有n个矩形，每个矩形可以用a,b来描述，表示长和宽。矩形X(a,b)可以嵌套在
矩形Y(c,d)中当且仅当a<c,b<d或者b<c,a<d（相当于旋转X90度）。
例如（1,5）可以嵌套在（6,2）内，但不能嵌套在（3,4）中。
你的任务是选出尽可能多的矩形排成一行，使得除最后一个外，每一个矩形都
可以嵌套在下一个矩形内。

将每个矩形看成一个顶点，并将嵌套关系视为顶点之间的有向边，边权均为1，问题转换为DAG最长路问题
*/
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1000;
const int INF = 0x3fffffff;

int n; //矩形个数
int G[maxn][maxn];
int dp[maxn];
vector<int> post[maxn];

struct Rectangle
{
	int x;
	int y;
}rec[maxn];

bool isContain(Rectangle a, Rectangle b){
	return (a.x < b.x) && (a.y < b.y);
}

int DP(int i){
	if (dp[i] > 0)
		return dp[i]; //dp[i]已经计算得到
	for (int j = 0; j < n; j++){ //遍历i的所有出边
		if (G[i][j] != INF){
			int temp = DP(j) + 1; //状态转移方程dp[i]=max(dp[i],dp[i]+1)
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
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> rec[i].x >> rec[i].y;
		if (rec[i].x < rec[i].y){
			swap(rec[i].x, rec[i].y);
		}
	}
	fill(G[0], G[0] + maxn*maxn, INF);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (isContain(rec[i], rec[j])){
				G[i][j] = 1;
			}
		}
	}
	memset(dp, 0, sizeof(dp));
	int maxdis = 0;
	int start;
	for (int i = 0; i < n; i++){
		int dis = DP(i);
		if (dis > maxdis){
			maxdis = dis;
			start = i;
		}
	}
	cout << maxdis + 1 << endl; //矩形个数等于最长路径+1
	printPath(start); //从起点开始打印出最长路径，如果从该起点开始有多条最长路径则打印字典序最小的那条

	system("pause");
	return 0;
}