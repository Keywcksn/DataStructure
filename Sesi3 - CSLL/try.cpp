#include<stdio.h>

int main(){
	char nama[30];
	printf("Nama: ");
	scanf("%[^\n]", nama);
	printf("%s", nama);
	return 0;
}
