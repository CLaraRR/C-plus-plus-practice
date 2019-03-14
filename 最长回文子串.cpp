#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn = 1000;
char s[maxn];
int dp[maxn][maxn];

int main(){
	cin.getline(s, maxn);
	int len = strlen(s);
	for (int i = 0; i < len; i++){
		for (int j = 0; j < len; j++){
			dp[i][j] = 0;
		}
	}

	int maxlen = 1;//回文长度至少为1，每个单独的字符都是一个回文
	//边界
	for (int i = 0; i < len; i++){
		dp[i][i] = 1; //每个单独的字符都是一个回文
		if (i < len - 1){
			if (s[i] == s[i + 1]){
				dp[i][i + 1] = 1; //若连续的两个字符相同则为回文
				maxlen = 2;//回文长度更新为2
			}
		}
	}

	//状态转移方程
	for (int k = 3; k <= len; k++){ //枚举子串的长度
		for (int i = 0; i + k - 1 < len; i++){
			int j = i + k - 1;
			//若当前长度的子串的左右两端点相同且中间的子串为回文串，则这个子串为回文
			if (s[i] == s[j] && dp[i + 1][j - 1] == 1){
				dp[i][j] = 1;
				maxlen = k;//回文长度更新
			}
		}
	}

	cout << maxlen << endl;



	system("pause");
	return 0;
}