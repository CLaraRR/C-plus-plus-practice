#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void digit2string(int digit){
	switch (digit)
	{
	case 0:printf("%s", "ling");break;
	case 1:printf("%s", "yi"); break;
	case 2:printf("%s", "er"); break;
	case 3:printf("%s", "san"); break;
	case 4:printf("%s", "si"); break;
	case 5:printf("%s", "wu"); break;
	case 6:printf("%s", "liu"); break;
	case 7:printf("%s", "qi"); break;
	case 8:printf("%s", "ba"); break;
	case 9:printf("%s", "jiu"); break;
	}
}

int main(){
	char str[100];
	int sum=0;
	scanf("%s", str);
	int digits[3];
	int i = 0;
	while (str[i]!='\0'){
		sum += str[i] - '0';
		i++;
	}
	//printf("%d\n", sum);
	i = 0;
	while (sum != 0){
		digits[i] = sum % 10;
		sum = sum / 10;
		i++;
	}
	i--;
	while (i>0){
		digit2string(digits[i]);
		printf(" ");
		i--;
	}
	digit2string(digits[i]);
	system("pause");
	return 0;
}