#include <iostream>
using namespace std;
#define MAX_N 100000
int main(){
	int n;
	cin >> n;
	int school[MAX_N] = { 0 };
	int id, score;
	int m = n;
	while (m--){
		cin >> id >> score;
		school[id] += score;

	}
	int max = 0;
	int max_id = 1;
	for (int i = 1; i < n; i++){
		if (school[i]>max){
			max = school[i];
			max_id = i;
		}
	}

	cout << max_id << " " << max << endl;
	system("pause");
	return 0;
}