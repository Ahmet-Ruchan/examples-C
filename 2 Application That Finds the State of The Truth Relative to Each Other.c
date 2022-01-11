#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

// Üst kısımda yer alanlar aşağıda kullanacağımız kodların yer aldığı kütüphaneler.

int main() {
setlocale(LC_ALL,"Turkish");     // Yandaki kod Türkçe dil desteğini eklemek için.

float A1,B1,C1;
float A2,B2,C2;

printf("1. Denklemin katsaylarını giriniz A1,B1,C1 : \n");
scanf(" %f %f %f", &A1 , &B1 , &C1);

printf("2. Denklemin katsayılarını giriniz A2, B2, C2 : \n");
scanf(" %f %f %f", &A2 , &B2 , &C2);

double egim = ((A1*B2)-(A2*B1)) / ((A1*A2)+(B1*B2));

double X0 = ((B1*C2)-(B2*C1))/((A1*B2)-(A2*B1));
double Y0 = ((C1*A2)-(C2*A1))/((A1*B2)-(A2*B1));

double C2C1 = (C2-C1);
double A1B1 = (A1*A1)+(B1*B1);

if((A1*A2)+(B1*B2) == 0){
	printf("Dik kesişen doğrulardır \n");
	printf("Aralarındaki açı alpha = %2.2f \n", atan(egim)*180/3.1415);
	printf("Kesişim noktaları: x=%1.1f  y=%1.1f  \n",  X0 , Y0 );
}
else if((A1/A2)==(B1/B2) && (B1/B2)==(C1/C2) && (A1/A2)==(C1/C2)){
	printf("Çakışık doğrulardır \n");
}
else if((A1/A2)==(B1/B2) && (B1/B2)!=(C1/C2) && (A1/A2)!=(C1/C2)){
	printf("Paralel doğrulardır \n");
	printf("Aralarındaki uzaklık d= %1.2f \n", fabs(C2C1)/(sqrt(A1B1)));
}	 
else if((A1/A2) != (B1/B2)){
	printf("alpha açısı ile kesişen doğrulardır \n");
	printf("Aralarındaki açı alpha = %2.2f \n", atan(egim)*180/3.1415);
	printf("Kesişim noktaları: x=%1.1f  y=%1.1f  \n",  X0 , Y0 );
}
else{
	printf("Bilinmeyen değer, işlem yapılamıyor.");
}
