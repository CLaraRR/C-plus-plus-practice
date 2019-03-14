#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
using namespace std;

const int maxn = 2000;
const int INF = 1000000000;

map<int, string> int2string;
map<string, int> string2int;
map<string, int> gang;
int G[maxn][maxn] = { 0 }, weight[maxn]={0}; //��Ȩ����Ȩ
int n, k, numPerson = 0;
bool visisted[maxn] = { false };

void DFS(int now, int &head, int &numMember, int &totalValue){
	numMember++;
	visisted[now] = true;
	if (weight[now] > weight[head]){
		head = now;
	}
	for (int i = 0; i < numPerson; i++){
		if (G[now][i] > 0){
			totalValue += G[now][i];
			G[now][i] = G[i][now] = 0;
			if (visisted[i] == false){
				DFS(i, head, numMember, totalValue);
			}
		}
	}
}

void DFSTraverse(){
	for (int i = 0; i < numPerson; i++){
		if (visisted[i] == false){
			int head = i, numMember = 0, totalValue = 0;
			DFS(i, head, numMember, totalValue);
			if (numMember>2 && totalValue > k){
				gang[int2string[head]] = numMember;
			}
		}
	}
}

int change(string str){
	if (string2int.find(str) != string2int.end()){
		return string2int[str];
	}
	else{
		string2int[str] = numPerson;
		int2string[numPerson] = str;
		return numPerson++;
	}
}

int main(){
	cin >> n >> k;
	string str1, str2;
	int w;
	for (int i = 0; i < n; i++){
		cin >> str1 >> str2 >> w;
		int id1 = change(str1);
		int id2 = change(str2);
		weight[id1] += w;
		weight[id2] += w;
		G[id1][id2] += w;
		G[id2][id1] += w;
	}
	DFSTraverse();
	cout << gang.size() << endl;
	if (gang.size()>0){
		for (map<string, int>::iterator it = gang.begin(); it != gang.end(); it++){
			cout << it->first << " " << it->second << endl;
		}
	}
	system("pause");
	return 0;
}