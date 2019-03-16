/*
����һ�������޻�ͼ��DAG�����������ͼ������·����Ȩֵ֮������������
��dp[i]��ʾ��i�Ŷ�������ܻ�õ��·������
*/
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1000;
const int INF = 0x3fffffff;
int n, m, G[maxn][maxn]; //�ڵ�������������¼����ͼ�ڵ�֮���Ȩֵ��ά����
int dp[maxn]; //dp[i]��ʾ��i�Ŷ�������ܻ�õ��·������
vector<int> post[maxn]; //��¼�·���϶���ĺ�̽��

//�ݹ���dp[i]
int DP(int i){
	if (dp[i] > 0)
		return dp[i]; //dp[i]�Ѿ�����õ�
	for (int j = 0; j < n; j++){ //����i�����г���
		if (G[i][j] != INF){
			int temp = DP(j) + G[i][j]; //״̬ת�Ʒ���
			if (temp > dp[i]){ //������Ի�ø�����·��
				dp[i] = temp; //����dp[i]
				post[i].clear(); //֮ǰ��¼�ĺ�̽�㶼Ҫ���
				post[i].push_back(j); //�����µĺ�̽ڵ�
			}
			else if (temp == dp[i]){
				post[i].push_back(j); //�������ͬ��·�����ȣ�Ҳ�������̽ڵ����
			}
		}
		
	}
	return dp[i]; //���ؼ�����ϵ�dp[i]
}


//����ж����·����������ֵ�����С��·��
void printPath(int i){
	cout << i << " ";
	while (post[i].size() != 0){
		i = post[i][0];
		cout << i << " ";
	}
	cout << endl;
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
	int maxdis = 0;
	int start;
	//��������ж�������ܻ�õ��·��dp[i]
	//��dp[i]�����ֵ������DAG���·������
	for (int i = 0; i < n; i++){ 
		int dis = DP(i);
		if (dis > maxdis){
			maxdis = dis;
			start = i; //��¼�·������㣬����ж����·����Ĭ��ȡ�ֵ�����С���Ǹ����
		}
	}
	cout << maxdis << endl;
	printPath(start); //����㿪ʼ��ӡ���·��������Ӹ���㿪ʼ�ж����·�����ӡ�ֵ�����С������

	system("pause");
	return 0;
}