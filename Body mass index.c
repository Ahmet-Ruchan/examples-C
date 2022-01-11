#include <stdio.h>
#include <stdlib.h>


int main() {
	
	float	boy;
	float	kilo;
	float	BKI;
	
	printf("boyunuzu giriniz (metre cinsinden. Ornegin=>1.87): \n");
	scanf("%f",&boy);
	
	printf("kilonuzu giriniz: \n");
	scanf("%f",&kilo);
	
	BKI = (kilo)/(boy*boy);
	printf("BKI = %2.2f \n",BKI);
	
	if(BKI>=40){
		printf("3. derece morbid obez \n");
	}
	else if(BKI<40){
		if(BKI<35){
			if(BKI<30){
				if(BKI<25){
					if(BKI<18.5){
						printf("Zayif \n");
						return 0;
					}
				printf("Normal \n");
				return 0;
				}
			printf("Fazla kilolu \n");
			return 0;
			}
		printf("1. derece obez \n");
		return 0;
		}
	printf("2. derece obez");
	return 0;
	}
	
	
	
	return 0;
}
