#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <iomanip>
using namespace std;
const double eps = 1e-8;
#define Equ(a,b) ((fabs((a)-(b))<(eps))

int main(){
	double d = 12.34562356;

	printf("%f\n", d);
	printf("%.3f\n", d);
	printf("%12f\n", d);
	printf("%012f\n", d);

	cout << setiosflags(ios::fixed) << setprecision(3) << d << endl;
	if (Equ(d,12.34562356))){
		cout << "true" << endl;
	}
		
	else
		cout << "false"<<endl;

	system("pause");
	return 0;
}