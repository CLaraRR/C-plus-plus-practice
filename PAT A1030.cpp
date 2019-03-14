#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1000;
const int INF = 0x3fffffff;

int n, m, start, dest, G[maxn][maxn], cost[maxn][maxn];
int d[maxn], c[maxn], pre[maxn];
bool visited[maxn] = { false };

void Dijkstra(int s){
	fill(d, d + n, INF);
	fill(c, c + n, INF);
	d[s] = 0;
	c[s] = 0;
	for (int i = 0; i < n; i++){
		int u = -1, min = INF;
		for (int j = 0; j < n; j++){
			if (visited[j] == false && d[j] < min){
				u = j;
				min = d[j];
			}
		}
		if (u == -1)
			return;
		visited[u] = true;
		for (int v = 0; v < n; v++){
			if (visited[v] == false && G[u][v] != INF){
				if (d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					c[v] = c[u] + cost[u][v];
					pre[v] = u;
				}
				else if (d[u] + G[u][v] == d[v]){
					if (c[v] > c[u] + cost[u][v]){
						c[v] = c[u] + cost[u][v];
						pre[v] = u;
					}
				}
			}
		}
	}
}
void printPath(int s, int v){
	if (v == s){
		cout << v << " ";
		return;
	}
	printPath(s, pre[v]);
	cout << v << " ";
}

int main(){
	cin >> n >> m >> start >> dest;
	fill(G[0], G[0] + maxn*maxn, INF);
	int u, v, wt, ct;
	for (int i = 0; i < m; i++){
		cin >> u >> v >> wt>>ct;
		G[u][v] = G[v][u] = wt;
		cost[u][v] = cost[v][u] = ct;
	}
	Dijkstra(start);
	printPath(start, dest);
	cout << d[dest] << " " << c[dest] << endl;

	system("pause");
	return 0;
}