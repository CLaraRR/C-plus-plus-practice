#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn = 1000;
char A[maxn], B[maxn];
int dp[maxn][maxn];

int main(){
	cin.getline(A + 1, maxn);
	cin.getline(B + 1, maxn);
	int lenA = strlen(A + 1);
	int lenB = strlen(B + 1);
	//边界
	for (int i = 0; i <= lenA; i++){
		dp[i][0] = 0;
	}
	for (int j = 0; j <= lenB; j++){
		dp[0][j] = 0;
	}

	int maxlen = 0;
	int A_index = 0, B_index = 0;
	//状态转移方程
	for (int i = 1; i <= lenA; i++){
		for (int j = 1; j <= lenB; j++){
			if (A[i] == B[j]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
				maxlen = max(maxlen, dp[i][j]);
				A_index = i;
				B_index = j;
			}
			else{
				dp[i][j] = 0;
			}
		}
	}

	cout << maxlen << endl;

	//从后面往前推获得子串
	int i = A_index, j = B_index;
	int k = maxlen;
	char sequence[maxn];
	while (i >= 1 && j >= 1){
		sequence[k--] = A[i];
		i--;
		j--;
	}

	for (int i = 1; i <= maxlen; i++){
		cout << sequence[i];
	}
	cout << endl;
	system("pause");
	return 0;
}