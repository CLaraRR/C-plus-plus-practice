#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main(){
	ifstream in("∂¡»Î.txt");
	int a[10];
	for (int i = 0; i < 10; i++){
		in >> a[i];
		
	}
	for (int i = 0; i < 10; i++){
		cout << a[i] << " ";
	}
	string str[256];
	int i = 0;
	while (getline(in, str[i])){
		cout << str[i] << endl;
		i++;
	}

	//for (int i = 0; i < 256; i++){
	//	if (str[i].size()!=0)
	//		cout << str[i] << endl;
	//}
	ofstream out("∂¡»Î.txt",ios::app);
	for (int i = 0; i < 10; i++){
		out << "add string " << i <<endl;
	}
	in.close();
	out.close();

	system("pause");
	return 0;
}