#include <stdio.h>
#include <locale.h>
#include <math.h>

void maxMinYazdir(char c);
void sirala(char s);
float istatistikGoster(float ort, float sapma);
int dizi[10];
char c;
char s;
float ort;
float standartSapma;
float toplam;

int secim;



main(){
setlocale(LC_ALL,"Turkish");

	srand(time(NULL));
	int i;


	for(i = 0; i < 10; i++){
		dizi[i] = (rand() % 51);
		int k;
		for(k = 0; k < i; k++){
			if(dizi[i] == dizi[k]){
				dizi[i] = (rand() % 51);
			}
		}
	}


printf("Oluþan diziniz : \t");
diziyiYazdir();
printf("\n\n");

 


printf("1 - Yazdýr \n");
printf("2 - Tersten Yazdýr \n");
printf("3 - Max-Min Yazdýr \n");
printf("4 - Sýrala \n");
printf("5 - Ýstatistik Göster \n \n");

printf("SEÇÝMÝNÝZ:");
scanf("%d",&secim);

if(secim==1){
	diziyiYazdir(); 
	printf("\n");	
}
else if(secim==2){
	diziyiTerstenYazdir();
	printf("\n");	
}
else if(secim==3){
	maxMinYazdir(c);
	printf("\n");
}
else if(secim==4){
	sirala(s);
	printf("\n");	
}
else if(secim==5){
	istatistikGoster(ort,standartSapma);
	printf("\n");
}




printf("\n\n");

printf("******************************** Bir öceki fonksiyonun cevabý üst kýsýmda yer almaktadýr ******************************* \n");
printf("***** Programdan Çýkmadan Diðer Fonksiyonlarý Kullanabilmeniz Ýçin Dizi Yenilendi. Keþfetmeye Devam Edebilirsiniz *****");

printf("\n\n\n\n");

return main();








}

int diziyiYazdir(){
	
	int j;
	for(j = 0; j < 10; j++){
		printf("%d",dizi[j]);
		if(j != 9){
			printf(",");
		}
	}
	
	
	
}

int diziyiTerstenYazdir(){

	int j;
	for(j=9; j>=0; j--){
		printf("%d",dizi[j]);
		if(j != 0){
			printf(",");
		}
	}	
}


void maxMinYazdir(char c){
	setlocale(LC_ALL,"Turkish");
	printf("Seçiminiz: (K)küçük / (B)büyük \n");
	scanf(" %c",&c);
	
	
	
	if(c=='B'){
		int max;
		max = dizi[0];
		for(int i=0; i<10; i++){
			if(dizi[i]>max) max = dizi[i];
		}
		printf("Maximum Deðer : %d \n",max);
	}
	
	if(c=='K'){
		int min;
		min = dizi[0];
		for(int i=0; i<10; i++){
			if(dizi[i]<min) min = dizi[i];
		}
		printf("Minimum Deðer : %d \n",min);
	}	
}



void sirala(char s){
	setlocale(LC_ALL,"Turkish");
	printf("Seçiminiz: (K)küçük / (B)büyük \n");
	scanf(" %c",&s);
	
	if(s=='B'){
		int i,j,t;
    
      
      	for(i=0;i<10;i++){
            for(j=0;j<10;j++){
                  if(dizi[j]<=dizi[i]){
                        t=dizi[i];  
                        dizi[i]=dizi[j];
                        dizi[j]=t;
                        }
                  }
            }
      
    printf("\n Büyükten Küçüðe Sýralama: ");
      
    for(i = 0;i <10; i++){
        printf("%d ",dizi[i]);
      }
    printf("\n >>> Devam etmek için *ENTER* a basýn. <<<");  
    getch();            
}
	
	if(s=='K'){
		int i,j,t;
    	
      
      	for(i=0;i<10;i++){
            for(j=0;j<10;j++){
                  if(dizi[j]>=dizi[i]){
                        t=dizi[i];  
                        dizi[i]=dizi[j];
                        dizi[j]=t;
                        }
                  }
            }
      
    printf("\n Küçükten Büyüðe Sýralama: ");
      
    for(i = 0;i <10; i++){
        printf("%d ",dizi[i]);
      }
     printf("\n >>> Devam etmek için *ENTER* a basýn. <<<"); 
    getch();            	
	}	
}



float istatistikGoster(float ort, float standartSapma){
	setlocale(LC_ALL,"Turkish");

	
toplam=0.0;
int i;
float standartToplam;

	for(int i=0; i<10; i++){
	
		toplam = toplam + dizi[i];
		ort = toplam/10.0;
		
	}
	printf("ortalama: %f \n",ort);
	

	
	for(i = 0; i < 10; i++){
		standartToplam = standartToplam + pow((dizi[i]-ort),2);
	}
	standartSapma = sqrt(standartToplam/=9);
	printf("Standart Sapma: %.2f",standartSapma);
	
		
	
	
	
	
	
	}	



	

	

	
	

