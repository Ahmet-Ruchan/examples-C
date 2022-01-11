#include <stdio.h>
#include <stdlib.h>


int main() {
	
	char	c;
	
	printf("Bir karakter giriniz: \n");
	scanf("%c",&c);
	
	int	ic = (int)c;
	
	if(c>=97){
		if((c>122) || (c<97)){
			printf("Girilen karakter alfabede mevcut degildir. \n");
		}
		printf("Girilen karakter alfabede mevcuttur. \n");
	}
	else if(c>=65){
		if((c>90) || (c<65)){
			printf("Girilen karakter alfabede mevcut degildir. \n");
		}
		printf("Girilen karakter alfabede mevcuttur. \n");
	}
	else{
		printf("Girilen karakter alfabede mevcut degildir. \n");
	}
	
	return 0;
}
