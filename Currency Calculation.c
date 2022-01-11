#include <stdio.h>
#include <stdlib.h>

// 4. Döviz Hesaplama
int main() {
	
float	dolarKuru;
float	dolarMiktari;
float	TLmiktari;

printf("Dolar kurunu giriniz: \n");
scanf("%f",&dolarKuru);
printf("Dolar miktarini giriniz: \n");
scanf("%f",&dolarMiktari);

TLmiktari = dolarKuru * dolarMiktari;

printf("TL Miktari: %2.2f",TLmiktari);
	
return 0;
}
