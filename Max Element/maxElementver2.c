#include <stdio.h>
#include <stdlib.h>

/*
Bu pointer yapısı, işlevin en büyük değeri hesapladıktan sonra bu değeri çağıran kod içindeki bir değişkene aktarılmasını sağlar. Normalde bir fonksiyon çağrısından sonra, işlev içindeki yerel değişiklikler yalnızca işlevin kendi kapsamında kalır ve çağıran kod tarafından erişilemez.

Ancak, bir işlev çağrısı sırasında işaretçi kullanarak bir değişkenin adresini iletmek, işlevin çağırıldığı kapsamın dışındaki bir değişkenin değerini güncellemesine olanak tanır. Bu, işlevin çağırıldığı kapsamda yerel bir değişkenin değerinin dışında bir yere bilgi aktarılmasını sağlar.

Yani, findMax fonksiyonunu çağıran kodda, fonksiyonun hesapladığı en büyük değeri almak için bir değişkenin adresini fonksiyona iletebiliriz. Fonksiyon bu adresi kullanarak, hesaplanan en büyük değeri çağıran koddaki değişkenin bellek adresine atar. Bu sayede, hesaplanan değere çağıran kodun erişimi sağlanmış olur.
*/

static void findMax(int array[], int size, int *max_value)
{
    int en_buyuk = array[0]; 
    int i;

    for(i = 0; i < size; i++)
    { 
        if(array[i] > en_buyuk)
        {
            en_buyuk = array[i];
        }
    }

    *max_value = en_buyuk;
    return;
}

static void runTest()
{
    int sayilar_1[] = {22, 33, 14, 55, 100};
    int sayilar_2[] = {242, 3, 145, 565, 100, 34, 27}; 
    int sayilar_3[] = {1, 456, 31, 350, 10, 8}; 

    int boyut_1 = sizeof(sayilar_1) / sizeof(sayilar_1[0]);
    int max_1;

    int boyut_2 = sizeof(sayilar_2) / sizeof(sayilar_2[0]);
    int max_2;

    int boyut_3 = sizeof(sayilar_3) / sizeof(sayilar_3[0]);
    int max_3;

    findMax(sayilar_1, boyut_1, &max_1);
    printf("1. Dizinin en buyuk elemani: %d\n", max_1);

    findMax(sayilar_2, boyut_2, &max_2);
    printf("2. Dizinin en buyuk elemani: %d\n", max_2);

    findMax(sayilar_3, boyut_3, &max_3);
    printf("3. Dizinin en buyuk elemani: %d\n", max_3);

    return;
}

int main()
{

    system("CLS");
    runTest();
    
    return 0;
}
