#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

const int maxn = 1000;
int f[maxn][maxn], dp[maxn][maxn];
int n;

int tower(int i, int j){
	//�߽�
	if (i == n)
		return dp[i][j];
	if (dp[i][j] != -1)
		return dp[i][j];
	else{
		dp[i][j] = max(tower(i + 1, j), tower(i + 1, j + 1)) + f[i][j];//״̬ת�Ʒ���
		return dp[i][j];
	}
}
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= i; j++){
			cin >> f[i][j];
		}
	}
	//�߽�
	for (int j = 1; j <= n; j++){
		dp[n][j] = f[n][j];

	}

	//����dp[i][j]����ֵΪ-1
	for (int i = 1; i <= n - 1; i++){
		for (int j = 1; j <= i; j++){
			dp[i][j] = -1;
		}
	}
	
	//�ݹ����
	int maxlen = tower(1, 1);
	cout << maxlen << endl;
	system("pause");

	return 0;
}