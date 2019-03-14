#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

const int maxn = 110;

struct node
{
	int weight;
	vector<int> child;
}Node[maxn];

bool cmp(int a, int b){
	return Node[a].weight > Node[b].weight;
}

int n, m, S;
int path[maxn];

void DFS(int index, int numNode, int sum){
	if (sum > S) return;
	if (sum == S){
		if (Node[index].child.size() != 0) return;
		for (int i = 0; i < numNode; i++){
			cout << Node[path[i]].weight;
			if (i < numNode - 1) cout << " ";
			else cout << endl;
		}
		return;
	}
	for (int i = 0; i < Node[index].child.size(); i++){
		int child = Node[index].child[i];
		path[numNode] = child;
		DFS(child, numNode + 1, sum + Node[child].weight);

	}
}

int main(){
	cin >> n >> m >> S;
	for (int i = 0; i < n; i++){
		cin >> Node[i].weight;
	}
	int id, k, child;
	for (int i = 0; i < m; i++){
		cin >> id >> k;
		for (int j = 0; j < k; j++){
			cin >> child;
			Node[id].child.push_back(child);
		}
		sort(Node[id].child.begin(), Node[id].child.end(), cmp);
	}

	path[0] = 0;
	DFS(0, 1, Node[0].weight);

	system("pause");
	return 0;
}


