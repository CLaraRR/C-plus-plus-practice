#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1000;
const int INF = 0x3fffffff;

int n, m, start, dest, G[maxn][maxn],weight[maxn];
int d[maxn],w[maxn],num[maxn];
bool visited[maxn] = { false };

void Dijkstra(int s){
	fill(d, d + n, INF);
	memset(num, 0, sizeof(num));
	memset(w, 0, sizeof(w));
	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;
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
					w[v] = w[u] + weight[v];
					num[v] = num[u];
				}
				else if (d[u] + G[u][v] == d[v]){
					if (w[v] < w[u] + weight[v]){
						w[v] = w[u] + weight[v];
					}
					num[v] += num[u];
				}
			}
		}
	}
}


int main(){
	cin >> n >> m >> start>> dest;
	for (int i = 0; i < n; i++){
		cin >> weight[i];
	}
	fill(G[0], G[0] + maxn*maxn, INF);
	int u, v, wt;
	for (int i = 0; i < m; i++){
		cin >> u >> v >> wt;
		G[u][v] = wt;
		G[v][u] = wt;
	}
	Dijkstra(start);
	cout << num[dest] << " " <<w[dest] << endl;

	system("pause");
	return 0;
}