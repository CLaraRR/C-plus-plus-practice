#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
using namespace std;

struct Student
{
	char id[13];
	int score;
	int location_num;
	int local_rank;
}student[30010];

bool cmp(Student a, Student b){
	if (a.score != b.score)
		return a.score > b.score;
	else
		return strcmp(a.id, b.id) < 0;
}

int main(){
	int n, k, num = 0;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> k;
		for (int j = 0; j < k; j++){
			cin >> student[num].id >> student[num].score;
			student[num].location_num = i;
			num++;
		}
		sort(student + num - k, student + num, cmp);
		student[num - k].local_rank = 1;
		for (int j = num - k + 1; j < num; j++){
			if (student[j].score == student[j - 1].score){
				student[j].local_rank = student[j - 1].local_rank;
			}
			else{
				student[j].local_rank = j - (num - k) + 1;
			}
		}
	}
	cout << num << endl;
	sort(student, student + num, cmp);
	int rank = 1;
	for (int i = 0; i < num; i++){
		if (i > 0 && student[i].score != student[i - 1].score){
			rank = i + 1;
		}
		cout << student[i].id << " " << rank << " " << student[i].location_num << " " << student[i].local_rank << endl;

	}
	



	system("pause");
	return 0;
}