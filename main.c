#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#include <dos.h>
#include<conio.h>


int dongu=0;
char komut1[];
char komut2[];
char komut3[];
char komut4[];
bool anahtar = false;




 main() {
 	setlocale(LC_ALL,"Turkish");
 	
 	baslangic();
	

	
	
	
	
}

baslangic(){
	
	system("COLOR 07");
	printf("Doðu yönünde büyük bir þatonun önündesin. Ýçeri girmen gerekiyor yoksa peþindekiler seni yakalayacaklar.\n");
	gets(komut1);
	
	while(dongu != 1){
		if(!(strcmp(komut1, "DOGU"))){ 
			oda1();
			dongu = 1;
		}
		else{
			printf("Geçersiz Komut \n");
			gets(komut1);	
		}
		
	}
	
}

oda1(){
	system("CLS");
	system("COLOR 4F");
	printf("Sonunda içeridesin. Yemek masasý üzerinden bir þeyler yiyebilirsin. \n");
	gets(komut2);
	
	while(dongu != 1){
		if(!(strcmp(komut2, "DOGU"))){
			oda6();
			dongu=1;
		}
		else if(!(strcmp(komut2, "BATI"))){ 
			baslangic();
			dongu=1;
		}
		else if(!(strcmp(komut2, "KUZEY"))){ 
			oda2();
			dongu=1;
		}
		else if(!(strcmp(komut2, "GUNEY"))){ 
			oda3();
			dongu=1;
		}
		else if(!(strcmp(komut2, "YEMEK YE"))){
			printf("Karnýný doldurdun ama bizi bekleyen bir prenses var yola devam. Þimdi ne yapacaksýn? \n");
			
			gets(komut2);
		}
		else{
			printf("Geçersiz Komut \n");
			gets(komut2);	
		}
	}
	
}

oda2(){
	system("CLS");
	system("COLOR FD");
	printf("Khaleesi’nin Dracarys sesini duymanla beraber ejderha ateþi altýnda yanarak öldün… \n >>> Lütfen bekle, öldüðün için 7 saniye içerisinde baþa döneceksin <<< \n");
	sleep(7);
	system("CLS");
	
	baslangic();
	
}

oda3(){
	system("CLS");
	system("COLOR B0");
	printf("Küçük bir odadasýn. Ortada bir yatak var. Yorgunsan dinlenebilirsin.\n");
	gets(komut3);
	
	while(dongu != 1){
		if(!(strcmp(komut3, "DOGU"))){ 
			oda5();
			dongu=1;
		}
		else if(!(strcmp(komut3, "GUNEY"))){ 
			oda4();
			dongu=1;
		}
		else if(!(strcmp(komut3, "KUZEY"))){ 
			oda1();
			dongu=1;
		}
		else if(!(strcmp(komut3, "DINLEN"))){ 
			printf("Yeterince dinlendin, iþe koyul ve prensesi kurtar. Þimdi ne yapacaksýn ?\n");
			
			gets(komut3);
		}
		else{
			printf("Geçersiz Komut \n");
			gets(komut3);	
		}
	}
	
	
}

oda4(){
	system("CLS");
	system("COLOR F2");
	printf("Týssss.... Bir piton yýlaný tarafýndan sýkýlarak öldürüldün… Boðulurken keþke C yerine Python mu öðrenseydim diye kafandan geçirdin...\n >>> Lütfen bekle, öldüðün için 10 saniye içerisinde baþa döneceksin <<<\n");
	sleep(10);
	system("CLS");
	
	baslangic();
	
}

oda5(){
	system("CLS");
	system("COLOR 60");
	printf("Çok karanlýk bir odadasýn. Sadece parlayan altýn bir anahtar var.\n");
	gets(komut4);
	
	while(dongu != 1){
		if(!(strcmp(komut4, "BATI"))){ 
			oda3();
			dongu=1;
		}
		else if(!(strcmp(komut4, "ANAHTAR AL"))){ 
			printf("Anahtarý aldýn þimdi prensesin odasýna gitme vakti. Þimdi ne yapacaksýn? \n");
			anahtar = true;
			gets(komut4);
			
		}
		else{
			printf("Geçersiz Komut \n");
			gets(komut4);
		}
   }
}
 

oda6(){
	system("CLS");
	system("COLOR F5");
	printf("Bilgisayar tarafýndan yönetilen odadasýn. 0 ile 9 arasýnda bir sayý tutmuþ. Üç denemede bulmalýsýn.\n\n");
	
	int tahmin;
	int tahminsayisi;
	int sayi = rand() % 10;
	srand(time(NULL)); 
	
	
	for(tahminsayisi = 3; tahminsayisi >0; tahminsayisi--){
		printf("Tahmininizi giriniz");
		scanf("%d",&tahmin);
		
		if((anahtar == false) && (tahmin == sayi)){
			printf("Doðru sayýyý buldun ancak kilitli kapýyý açacak anahtar yanýnda deðil… odaya zehirli bir gaz dolmaya baþladý ve öldün… \n >>> Lütfen bekle, öldüðün için 10 saniye içerisinde baþa döneceksin <<<\n\n");
			sleep(10);
			system("CLS");
			baslangic();
			
		}
		else if((anahtar == true) && (tahmin == sayi)){
			printf("Tebrikler… doðru sayýyý buldun ve kilitli kapýyý açarak prensesi kurtardýn…\n");
			break;
			
		}
		else if(tahminsayisi == 1){
			printf("Üç denemede bulamadýn.. odaya zehirli bir gaz dolmaya baþladý ve öldün…\n >>> Lütfen bekle, öldüðün için 10 saniye içerisinde baþa döneceksin <<<\n \a");
			sleep(10);
			system("CLS");
			baslangic();
		}
	}
		
	
}
