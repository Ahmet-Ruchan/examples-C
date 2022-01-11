#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <locale.h>

//ÖDEV-1 Klavyeden girilen 5 elemanlý A ve B dizilerini toplayarak C dizisini oluþtura ve yazdýran C program 

int main() {
	setlocale(LC_ALL,"Turkish");
	
	int	i;
	int	A[5];
	int	B[5];
	int	C[5];
	
	for(i=0;i<5;i++){
		printf("A Dizinin %d. indisini giriniz: \n",i);
		scanf("%d",&A[i]);
	}
	printf("\n**********\n\n");
	for(i=0;i<5;i++){
		printf("B Dizinin %d. indisini giriniz: \n",i);
		scanf("%d",&B[i]);
	}
	
	for(i=0;i<5;i++){
		C[i] = A[i] + B[i];
	}
	
	printf("\n\nC Dizisi: \n");
	for(i=0;i<5;i++){
		printf(" %d ",C[i]);
	}
	
	return 0;
}
