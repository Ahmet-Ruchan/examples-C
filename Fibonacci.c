#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

unsigned long long int fibonacci(unsigned int n);


 main() {
setlocale(LC_ALL,"Turkish");
	
unsigned long long int result; //fibonacci deðeri, sonucu
unsigned int number; // kullanýcý tarafýndan girilen sayý

printf("Bir tam sayý giriniz: \n");
scanf("%u",&number);

result = fibonacci(number);

printf("Fibonacci(%u) = %11u \n",number, result); //ilk %u=number, ikinci %11u=result
	
}

//fibonacci fonksiyonunu özyinelemeli olarak tanýmlayacaðýz

unsigned long long int fibonacci(unsigned int n){
	
	if(0 == n || 1 == n){
		return n;
	}
	else{
		return fibonacci(n-1) + fibonacci(n-2);
	}
}









