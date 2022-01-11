#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <locale.h>

//ÖDEV-4 N kiþilik bir sýnýfýn herhangi bir dersten yýlsonu notlarý girilmektedir. Buna göre sýnýf ortalamasýnýn altýnda kalanlara “kaldý”, diðerlerine da “geçti” yazan C program

int main() {
	setlocale(LC_ALL,"Turkish");
	
	int	n;
	int	i;
	float	toplam = 0;
	float	ortalama;
	
	printf("Notu girilecek öðrenci sayýsýný giriniz: \n");
	scanf("%d",&n);
	
	int	sinif[n];
	
	for(i=0;i<n;i++){
		printf("%d. öðrencinin notunu giriniz:",i+1);
		scanf("%d",&sinif[i]);
		toplam += sinif[i];
	}
	
	ortalama = toplam / n;
	printf("\nSýnýf ders notu ortalamasý: %2.2f \n\n",ortalama);
	
	for(i=0;i<n;i++){
		if(sinif[i] < ortalama){
			printf("%d. Öðrenci dersten kaldý \n",i+1);
		}
		else{
			printf("%d. Öðrenci dersten geçti \n",i+1);
		}
	}
	
	return 0;
}
