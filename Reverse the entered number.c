#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//5. SORU

int	tersCevir(int	x){
	int	i;
	int	ters;
	
	printf("\nTersi: ");
	for(i=0;x>0;i++){
		ters = x % 10;
		printf("%d",ters);
		x = x / 10;
	}	
}

int main() {
	setlocale(LC_ALL,"Turkish");
	
	int	sayi;
	
	printf("Ters çevrilecek deðeri giriniz: \n");
	scanf("%d",&sayi);
	printf("\nGirilen deðer: %d",sayi);
	
	tersCevir(sayi);
	
	return 0;
}
