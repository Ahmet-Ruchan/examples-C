#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>


int main() {
	
	setlocale(LC_ALL,"Turkish");

	/*
	int sayi;
	int ilkBasamak;
	int sonBasamak;
	
	printf("Sayiyi giriniz\n");
	scanf("%d",&sayi);
	
	ilkBasamak = sayi % 10; //sayýyýnýn mod 10'nunu alýnca birler basamaðýnda kalan deðer
							//ilk basamak olur
	
	
	for(sayi;sayi>=10;sayi=sayi/10){//girilen sayýdan baþla, sayý 10 dan büyük olduðu
		sonBasamak = sayi; 		   //müddetçe devam et zaten 10 dan küçükse rakam olur
	}							 //sayýyý her seferinde 1 basamak azalt
	sonBasamak = sayi;	//yani her sefer birler - onlar - yüzler... basamaklarýný sil 
					   //en son kalan deðeri sonBasamak olarak ata.
	
	printf("Ilk Basamak: %d\nSon Basamak: %d",ilkBasamak,sonBasamak);
	*/
	
	
	
	//DÖNGÜSÜZ ÝLK VE SON BASAMAK BULMA (MATH.H KÜTÜPHANESÝ LAZIM)
	
	int sayi, ilkBasamak, sonBasamak, basamak;
	
	printf("Sayýyý giriniz: \n");
	scanf("%d", &sayi);
	
	ilkBasamak = sayi % 10; 
	
	basamak = (int)log10(sayi);
	sonBasamak = (int)(sayi / pow(10, basamak));
	 
	printf("Ýlk basamak = %d\n", ilkBasamak);
	printf("Son basamak = %d\n", sonBasamak);

	
	return 0;
}
