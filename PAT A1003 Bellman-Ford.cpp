#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

const int maxn = 1000;
const int INF = 0x3fffffff;

struct Node
{
	int v, dis;
	Node(int x, int y) :v(x), dis(y){}
};
vector<Node> Adj[maxn];
int n, m, start, dest, weight[maxn];
int d[maxn], w[maxn], num[maxn];
set<int> pre[maxn];

void Bellman(int s){
	fill(d, d + n, INF);
	memset(num, 0, sizeof(num));
	memset(w, 0, sizeof(w));
	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;
	for (int i = 0; i < n-1; i++){
		for (int u = 0; u < n; u++){
			for (int j = 0; j < Adj[u].size(); j++){
				int v = Adj[u][j].v;
				int dis = Adj[u][j].dis;

				if (d[u] + dis < d[v]){
					d[v] = d[u] + dis;
					w[v] = w[u] + weight[v];
					num[v] = num[u];
					pre[v].clear();
					pre[v].insert(u);
				}
				else if (d[u] + dis == d[v]){
					if (w[v] < w[u] + weight[v]){
						w[v] = w[u] + weight[v];
					}
					pre[v].insert(u);
					num[v] = 0;
					set<int>::iterator it;
					for (it = pre[v].begin(); it != pre[v].end(); it++){
						num[v] += num[*it];
					}
				}
			}
		}
	}
}


int main(){
	cin >> n >> m >> start >> dest;
	for (int i = 0; i < n; i++){
		cin >> weight[i];
	}
	int u, v, wt;
	for (int i = 0; i < m; i++){
		cin >> u >> v >> wt;
		Adj[u].push_back(Node(v, wt));
		Adj[v].push_back(Node(u, wt));
	}
	Bellman(start);
	cout << num[dest] << " " << w[dest] << endl;

	system("pause");
	return 0;
}