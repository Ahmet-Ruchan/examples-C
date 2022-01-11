#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

char *SIFIR = "SIFIR";
char *BIR = "BIR";
char *IKI = "IKI";
char *UC = "UC";
char *DORT = "DORT";
char *BES = "BES";
char *ALTI = "ALTI";
char *YEDI = "YEDI";
char *SEKIZ = "SEKIZ";
char *DOKUZ = "DOKUZ";

mesajIlkSonKontrol(char *pointer, char sifreliMesaj);
veriKontrolVeHarfGetirCagir(char *pointer, char sifreliMesaj);
char harfGetir(int ilkRakam, int ikinciRakam);

int main() {
	char sifreliMesaj[100];
	printf("Sifrelenmis mesaji girin\n"); 
	gets(sifreliMesaj);
	char *pointer = sifreliMesaj;
	mesajIlkSonKontrol(pointer, sifreliMesaj);
	}


mesajIlkSonKontrol(char *pointer,  char sifreliMesaj){
	int *pointer2 = pointer;
	if(isdigit(*pointer) == 1){
		while(*pointer != '\0'){
		pointer++;
		}
		if(isdigit(*(pointer - 1)) == 1){
		veriKontrolVeHarfGetirCagir(pointer2, sifreliMesaj);
		}else{
		printf("mesaj baslangici veya sonu sayi degil");
		}
	
	}
	else{
		printf("mesaj baslangici veya sonu sayi degil");
	}
}

veriKontrolVeHarfGetirCagir(char *pointer, char sifreliMesaj){
	int i = 0;
	int sayi1;
	int sayi2;
	bool hata = true;
	while(*(pointer + i) != '\0'){
		int j;
		if( i % 3 == 0){
			sayi1 = *(pointer + i) - 48;
		}else if(i % 3 == 1){
			sayi2 = *(pointer + i) - 48;
		}else if(i % 3 == 2){
			if(*(pointer + i) != '-'){
				printf("ilk hata %d. indekste\n",i);
				hata = false;
				break;
			}
			printf("%c",harfGetir(sayi1, sayi2 - 1));
		}
		i++;	
	}
	if(hata == true){
		printf("%c",harfGetir(sayi1, sayi2 - 1));
	}
}
char harfGetir(int ilkRakam, int ikinciRakam){
	if(ilkRakam == 0){
		return *(SIFIR + ikinciRakam);
	}else if(ilkRakam == 1){
		return *(BIR + ikinciRakam);
	}
	else if(ilkRakam == 2){
		return *(IKI + ikinciRakam);
	}
	else if(ilkRakam == 3){
		return *(UC + ikinciRakam);
	}
	else if(ilkRakam == 4){
		return *(DORT + ikinciRakam);
	}
	else if(ilkRakam == 5){
		return *(BES + ikinciRakam);
	}
	else if(ilkRakam == 6){
		return *(ALTI + ikinciRakam);
	}
	else if(ilkRakam == 7){
		return *(YEDI + ikinciRakam);
	}
	else if(ilkRakam == 8){
		return *(SEKIZ + ikinciRakam);
	}
	else if(ilkRakam == 9){
		return *(DOKUZ + ikinciRakam);
	}
}

