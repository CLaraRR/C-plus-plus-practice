#include <iostream>
#include <stdlib.h>
using namespace std;

int F(int n){
	if (n == 0 || n == 1)
		return 1;
	else
		return F(n - 1) + F(n - 2);
}

int main(){
	int n;
	cin >> n;
	int result = F(n);
	cout << result << endl;
	system("pause");
	return 0;
}