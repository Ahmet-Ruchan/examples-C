#include<stdio.h>
#include <math.h>

int main()
{
	int x,y,z;
	
	printf("1. kenari giriniz: \n");
	scanf("%d",&x);
	printf("2. kenari giriniz:\n");
	scanf("%d",&y);
	printf("3. kenari giriniz:\n");
	scanf("%d",&z);
	
	if (x+y>z && x+z>y && y+z>x){
		printf("Bu bir Ucgendir");
	}
	else{
		printf("Bu bir Ucgen degildir");
	}	
			
return 0;
}
