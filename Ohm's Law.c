#include <stdio.h>
#include <stdlib.h>

// 1. Ohm Kanunu
int main() {
	
int	R;
int	I;
int	V;

printf("Iletkenin direncini giriniz (R): \n");
scanf("%d",&R);
printf("Iletkenin icerisinden gecen akimi giriniz (I): \n");
scanf("%d",&I);

V = R * I;

printf("Iletkenin uclari arasindaki gerilim (V): %d\n",V);
	
	
	
	
	
	
	
	return 0;
}
