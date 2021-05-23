#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

ogrenciEkle();
ogrenciArama();
raporYazdir();
struct ogrenci{
	int ogrenciNumarasi;
	char isim[50];
	char soyadi[50];
	double vizeNotu;
	double finalNotu;
	double odev1Notu;
	double odev2Notu;
	double donemSonuNotu;
}ogrenciler[100];
main()
{
	int secim;
	printf("            MENU        \n");
	printf("-----------------------------\n");
	printf("1) Ogrenci Ekleme\n");
	printf("2) Ogrenci Arama (Numara ile)\n");
	printf("3) Rapor Yazdir\n");
	printf("\nSecimi secin: ");
	scanf("%d",&secim);
	switch(secim){
		case 1:
		ogrenciEkle();
		printf("Ogrenciler kaydedildi\n");
		main();
		break;
		
		case 2:
		ogrenciArama();
		break;
		
		case 3:
		raporYazdir();
		break;
	}
	}
ogrenciEkle()
{
	FILE *ogrenciListesi;
	ogrenciListesi = fopen("ogrenciListesi.txt", "r");
	
	int i = 0;
	while(!feof(ogrenciListesi))
	{
		fscanf(ogrenciListesi,"%d", &ogrenciler[i].ogrenciNumarasi);
		fscanf(ogrenciListesi,"%s", &ogrenciler[i].isim);
		fscanf(ogrenciListesi,"%s", &ogrenciler[i].soyadi);
		fscanf(ogrenciListesi,"%lf", &ogrenciler[i].vizeNotu);
		fscanf(ogrenciListesi,"%lf", &ogrenciler[i].finalNotu);
		fscanf(ogrenciListesi,"%lf", &ogrenciler[i].odev1Notu);
		fscanf(ogrenciListesi,"%lf", &ogrenciler[i].odev2Notu);
		ogrenciler[i].donemSonuNotu =  (ogrenciler[i].vizeNotu * 25.0 / 100) + (ogrenciler[i].finalNotu * 40.0 / 100) + 
		(ogrenciler[i].odev1Notu * 15.0 / 100) + (ogrenciler[i].odev2Notu * 20.0 / 100); 
		i++;
	}
	fclose(ogrenciListesi);
}
ogrenciArama()
{
	int arananOgrenci;
	bool bulundu = false;
	char anamenu;
	int j = 0;
	
	printf("Ogrenci numarasi giriniz: ");
	scanf("%d",&arananOgrenci);
	
	while(j < 100)
	{
		if(ogrenciler[j].ogrenciNumarasi == arananOgrenci)
		{
			bulundu = true;
			printf("OGRENCI NUMARASI: %d\n", ogrenciler[j].ogrenciNumarasi);
			printf("ISIM: %s\n", ogrenciler[j].isim);
			printf("SOYAD: %s\n", ogrenciler[j].soyadi);
			printf("VIZE NOTU: %lf\n", ogrenciler[j].vizeNotu);
			printf("FINAL NOTU: %lf\n", ogrenciler[j].finalNotu);
			printf("ODEV1 NOTU: %lf\n", ogrenciler[j].odev1Notu);
			printf("ODEV2 NOTU: %lf\n", ogrenciler[j].odev2Notu);
			printf("DONEM SONU NOTU: %lf\n", ogrenciler[j].donemSonuNotu);
			break;
		}
		j++;
	}
	
	if(bulundu == false)
	{
		printf("KAYIT BULUNAMADI, LUTFEN TEKRAR DENEYINIZ\n");
	}
	
	printf("Ana menuye donmek icin 'M/m' tusuna basiniz...");
	scanf("%s",&anamenu);
	
	if(anamenu == 'M' || anamenu == 'm')
	{
		main();
	}
	
}
raporYazdir()
{
	FILE *DersRaporu;
	DersRaporu = fopen("DersRaporu.txt", "w");
	
	int ogrenciSayisi = 0;
	double vizeToplam = 0.0;
	double finalToplam = 0.0;
	double birinciOdevToplam = 0.0;
	double ikinciOdevToplam = 0.0;
	double donemSonuNotToplam = 0.0;

	while(ogrenciler[ogrenciSayisi].ogrenciNumarasi != 0)
	{
		vizeToplam = ogrenciler[ogrenciSayisi].vizeNotu + vizeToplam;
		finalToplam = ogrenciler[ogrenciSayisi].finalNotu + finalToplam;
		birinciOdevToplam = ogrenciler[ogrenciSayisi].odev1Notu + birinciOdevToplam;
		ikinciOdevToplam = ogrenciler[ogrenciSayisi].odev2Notu + ikinciOdevToplam;
		donemSonuNotToplam = ogrenciler[ogrenciSayisi].donemSonuNotu + donemSonuNotToplam;
		ogrenciSayisi++;
	}

	fprintf(DersRaporu,"Toplam Ogrenci Sayisi: %d\n",ogrenciSayisi);
	fprintf(DersRaporu,"Vize Ortalamasi: %lf\n", vizeToplam / ogrenciSayisi);
	fprintf(DersRaporu,"Final Ortalamasi: %lf\n", finalToplam / ogrenciSayisi);
	fprintf(DersRaporu,"1.Odev Ortalamasi: %lf\n", birinciOdevToplam / ogrenciSayisi);
	fprintf(DersRaporu,"2.Odev Ortalamasi: %lf\n", ikinciOdevToplam / ogrenciSayisi);
	fprintf(DersRaporu,"Donem Sonu Ortalamasi %lf\n", donemSonuNotToplam / ogrenciSayisi);
	printf("\nDers raporu yazdirildi, lutfen kontrol ediniz.\n");
	
}
