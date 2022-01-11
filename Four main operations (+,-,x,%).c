#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//2. SORU

float	carpma(float	x,float	y){
	
	float	sonuc;
	sonuc = x * y;
	printf("\nÇarpma iþleminin sonucu= %2.2f\n",sonuc);
}

float	bolme(float	x,float	y){
	
	float	sonuc;
	sonuc = x / y;
	printf("\nBölme iþleminin sonucu= %2.2f\n",sonuc);
}

float	toplama(float	x,float	y){
	
	float	sonuc;
	sonuc = x + y;
	printf("\nToplama iþleminin sonucu= %2.2f\n",sonuc);
}

float	cikarma(float	x,float	y){
	
	float	sonuc;
	sonuc = x - y;
	printf("\nÇýkarma iþleminin sonucu= %2.2f\n",sonuc);
}

int main() {
	setlocale(LC_ALL,"Turkish");
	
	float	sayi1,sayi2;
	
	printf("1. sayýyý giriniz:\n");
	scanf("%f",&sayi1);
	printf("2. sayýyý giriniz:\n");
	scanf("%f",&sayi2);
	
	carpma(sayi1,sayi2);
	bolme(sayi1,sayi2);
	toplama(sayi1,sayi2);
	cikarma(sayi1,sayi2);
	
	return 0;
}
