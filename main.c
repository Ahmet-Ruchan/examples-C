#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>



//YARIÞ ÖDEVÝ

main() {
setlocale(LC_ALL,"Turkish");
srand(time(NULL));

int sayi;
int doganSLXPuan=0;
int ferrariPuan=0;
int baslangic=0,bosluk;
int baslangicF=0;



while((doganSLXPuan<=100) || (ferrariPuan<=100)){
		sayi = rand() % 10+1;
		printf("Gelen sayý: %d \n", sayi);	
		sleep(1);
		system("CLS");
					
	
	if(sayi<=5 ){
	    	doganSLXPuan +=3 ;
	    	if(sayi == 5){
	    		ferrariPuan-=12;
	    		if(ferrariPuan < 0){
	    			ferrariPuan=0;
				}
			}
			else if((sayi == 3)|| (sayi == 4)){
				ferrariPuan +=9;
			}	
			}
		if ((sayi== 6)|| (sayi == 7)){
			doganSLXPuan-=6;
			if(doganSLXPuan < 0){
	    		doganSLXPuan=0;
			}
		}
		if((sayi<=8) && (sayi>=6)){
			ferrariPuan+=1;
		}
		if((sayi>=8) && (sayi<=10)){
			doganSLXPuan+=1;
		}
		if((sayi>=9) && (sayi<=10)){
			ferrariPuan-=2;
			if(ferrariPuan < 0){
	    		ferrariPuan=0;
			}
		}

		printf("DoðanSLX: %d \n",doganSLXPuan);
		printf("Ferrari: %d \n\n ",ferrariPuan);
		
		
		
		if(sayi<=5){
			baslangic+=3;
		}
		else if((sayi== 6)|| (sayi == 7)){
				baslangic-=6;
				if(baslangic<0){
					baslangic=0;
				}		
		}
		else if((sayi>=8) && (sayi<=10)){
				baslangic+=1;
		}
				
		bosluk = 0;
		while(bosluk < baslangic){
			printf(" ");
			
			bosluk++;
		}printf("X \n");
		
		
		
		if(sayi == 5){
			baslangicF-=12;
			if(baslangicF<0){
					baslangicF=0;
				}		
		}
		else if((sayi == 3)|| (sayi == 4)){
			baslangicF+=9;
		}
		else if((sayi<=8) && (sayi>=6)){
			baslangicF+=1;
		}
		else if((sayi>=9) && (sayi<=10)){
			baslangicF-=2;
			if(baslangicF<0){
					baslangicF=0;
				}		
		}
		
		bosluk = 0;
		while(bosluk < baslangicF){
			printf(" ");
			
			bosluk++;
		}printf("F \n\n");
	
	
	if((doganSLXPuan>=100) || (ferrariPuan>=100)){
		if(ferrariPuan>=100){
			printf("Ferrari KAZANDI!");
		}
		else{
			printf("DoðanSLX KAZANDI!");
		}
		break;
		
		
	}
	
	}
}
	
	


















































































































	

	
	
	
	
	









	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

