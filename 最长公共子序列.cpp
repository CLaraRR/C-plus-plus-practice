#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn = 1000;
char A[maxn], B[maxn];
int dp[maxn][maxn];

int main(){
	cin.getline(A+1, maxn);
	cin.getline(B+1, maxn);
	int lenA = strlen(A + 1);
	int lenB = strlen(B + 1);
	//边界
	for (int i = 0; i <= lenA; i++){
		dp[i][0] = 0;
	}
	for (int j = 0; j <= lenB; j++){
		dp[0][j] = 0;
	}

	//状态转移方程
	for (int i = 1; i <= lenA; i++){
		for (int j = 1; j <=lenB; j++){
			if (A[i] == B[j]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	int maxlen = dp[lenA][lenB];
	cout << maxlen << endl;//dp[lenA][lenB]保存了最长公共子序列

	//从后面往前推获得子序列
	char sequence[maxn];
	int k = maxlen;
	int i = lenA, j = lenB;
	while (i >= 1 && j >= 1){
		if (A[i] == B[j]){
			sequence[k--] = A[i];
			i--;
			j--;
		}
		else{
			if (dp[i - 1][j] >= dp[i][j - 1]) 
				i--;
			else 
				j--;
		}
	}
	for (int i = 1; i <= maxlen; i++){
		cout << sequence[i];
	}
	cout << endl;
	system("pause");
	return 0;

}