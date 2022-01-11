#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <locale.h>

//ÖDEV-2

int main() {
	setlocale(LC_ALL,"Turkish");
	
	int	A[] = {51,12,18,33,19,20,37};
	int	i;
	int	eleman;
	int	min;
	int	max;
	
	eleman = sizeof(A) / sizeof(int);
	
	max = A[0];
	min = A[0];
	
	printf("int	A[] = {51,12,18,33,19,20,37} \n\n");
	
	for(i=0;i<eleman;i++){
		if(A[i]>max){
			max = A[i];
		}
		else if(A[i]<min){
			min = A[i];
		}
	}
	
	printf("Dizide ki en büyük deðer: %d \n",max);
	printf("Dizide ki en küçük deðer: %d \n",min);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
