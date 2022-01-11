#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main() {
	setlocale(LC_ALL,"Turkish");
	
	int evineVarmasiIcinGerekenSure = 0;
	int toplamSoruSayisi = 0;
	int toplamSure = 240;
	int	yeniToplamSure=0;
	
	printf("Toplam soru sayýsýný girniz:\n");
	scanf("%d",&toplamSoruSayisi);
	
	printf("Amcasinin evine varmasý için gereken süreyi giriniz:\n");
	scanf("%d",&evineVarmasiIcinGerekenSure);
	
	
	yeniToplamSure = toplamSure - evineVarmasiIcinGerekenSure;
	
	int cozulebilecekSoruSayisi = 0;

		while(yeniToplamSure > 0){
		yeniToplamSure = yeniToplamSure -  cozulebilecekSoruSayisi * 5;
		
		if(yeniToplamSure < 0){
			break;
		}else if(yeniToplamSure > 0){
			cozulebilecekSoruSayisi++;	
		}
		

	}

	printf("En fazla çözülebilecek soru sayýsý %d", cozulebilecekSoruSayisi);
	
	return 0;
}
