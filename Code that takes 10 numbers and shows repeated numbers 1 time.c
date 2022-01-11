#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <locale.h>
#include <stdbool.h>

//ÖDEV-3 10 SAYI ALAN TEKRARLANAN SAYILARI 1 DEFA GÖSTEREN PROGRAM 

bool varMi;

int main() {
	setlocale(LC_ALL,"Turkish");
	
	int	dizi[10];
	int	i;
	
	//diziye 10 adet eleman alýyoruz
	for(i=0;i<10;i++){
		printf("%d. indisi giriniz:",i);
		scanf("%d",&dizi[i]);
	}
	
	printf("\n\nGirdiðiniz dizi: (ayný karakter birden fazla girildiyse bir defa yazýldý.) \n\n");
	for(i = 0; i < 10; i++){
		int j;
		varMi = false; //bool deðeri false olarak atadým baþlangýçta
		if(i!=0){ //0 dan baþlayamaz aþaðýda j=i-1; var o yüzden i 0 deðilse diye bakýyoruz.		
			for(j = i - 1; j >= 0; j--){ //j büyükten baþlayýp, azalarak gidecek.		
				if(dizi[i] == dizi[j]){ //0 dan 10'a kadar içinde gezecek ve eðer dizi[] dizisinde ki deðerler ayný ise
					varMi = true; //bool deðerini true yapýyorum, burada ayný olan tüm deðerleri kaydediyor.
				}
			}
		}	
		if(varMi == false){ //ayný olan deðerler true olarak kaydedildi, geri kalanlar (aynýsý olmayanlar) false da kaldý
			printf("%d ",dizi[i]); //tüm false'da kalanlarý yazdýrýyoruz. for içinde bu da dikkat et	
		}
	}

	return 0;
}




















