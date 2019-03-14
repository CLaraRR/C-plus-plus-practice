#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>
using namespace std;

struct mooncake{
	double store;
	double total_price;
	double single_price;
}cake[1010];

bool cmp(mooncake a, mooncake b){
	return a.single_price > b.single_price;
}

int main(){
	int n;
	double D;
	cin >> n >> D;
	for (int i = 0; i < n; i++){
		cin >> cake[i].store;
	}
	for (int i = 0; i < n; i++){
		cin >> cake[i].total_price;
		cake[i].single_price = cake[i].total_price / cake[i].store;
	}
	sort(cake, cake + n, cmp);
	double ans = 0;
	for (int i = 0; i < n; i++){
		if (cake[i].store <= D){
			D -= cake[i].store;
			ans += cake[i].total_price;
		}
		else{
			ans += cake[i].single_price*D;
			break;
		}
	}
	cout << setiosflags(ios::fixed)<<setprecision(2)<<ans << endl;


	system("pause");
	return 0;
}