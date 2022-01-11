#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>

 main() {

setlocale(LC_ALL,"Turkish");

srand(time(NULL));  // üretilen sayının rastgele değerlerde olmasını sağlar
int sayi = rand() % 100; // 1 ile 100 arasında bir sayı üretmeyi sağlayan kod

int tahmin;
int denemeHakki = 1;
bool bulundu = false;


while(bulundu==false){
	printf("Tahmin giriniz: \n");
	scanf("%d", &tahmin);
	
	if(tahmin==sayi){
		printf("Tebrikler... %d denemede buldunuz \n", denemeHakki);
		bulundu=true;
	}
	else if(tahmin<sayi){
		printf("Daha büyük bir sayı giriniz... \n");
		denemeHakki++;
	}
	else{
		printf("Daha küçük bir sayı giriniz... \n");
		denemeHakki++;
	}
	}
		
}


