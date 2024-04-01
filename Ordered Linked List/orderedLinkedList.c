#include <stdio.h>
#include <stdlib.h>

struct n {
    int x;
    struct n *next; // her kutuda bir sonrakini gösteren pointer.
};

typedef struct n node; // n dediğimde node'ı kast etmiş oluyorum.

void getLinkedList(node *r) // r isminde bir node al
{
    while(r != NULL) 
    {
        printf("%d \n", r -> x); // r düğümünün içeriğini yaz
        r = r -> next; // düğümü bir sonraki düğüme bağla
    }

    return;
} //func getLinkedList

void setLinkedList(node *r, int x) 
{
    while(r -> next != NULL) // r'nin next'i NULL değerine eşit olana kadar git yani son düğüme kadar git
    {
        r = r -> next; // liste içinde ilerle
    }

    r -> next = (node *)malloc(sizeof(node)); // gittiğin yerin next'ine bir düğüm oluştur
    r -> next -> x = x; // oluşturduğun düğümün datasına fonksiyona girilen x değerini koy
    r -> next -> next = NULL; // en son oluşturduğun düğümün next'ine NULL koy yani liste sonu yap, son düğüm yap

    return;
} //func setLinkedList

node *setOrderedLinkedList(node *r, int x) 
{
    if(r == NULL) // listenin boş olma durumu
    {
        r = (node *)malloc(sizeof(node));
        r -> next = NULL;
        r -> x = x;
        return r; // yeni root döndür
    }

    if(r -> x > x) // varolan düğümün ilk değeri, gelen değerden büyükse
    {   
        node *temp = (node *)malloc(sizeof(node)); // geçici düğüm oluşturdum
        temp -> x = x; // geçici değere atama yaptık 
        temp -> next = r; // bu değer, listedeki değerden küçük olduğu için en başa gelmesi gerekiyor. Bu yüzden temp'in next'ini root yapıyoruz
        return temp; // temp artık root
    }

    node *iter = r; // r'ın elemanı olacak şekilde bir iter tanımladık

    while(iter -> next != NULL && iter -> next -> x < x) // eklenecek değer ilk değerden büyük son değerden küçükse bir aralık bularak ona göre yerleştirmeye çalışacağız.
    {
        iter = iter -> next;
    }

    node *temp = (node *)malloc(sizeof(node));
    temp -> next = iter -> next;
    iter -> next = temp;
    temp -> x = x;

    return r;
} // func setOrderedLinkedList

node * deleteNode(node * r, int x)
{
    node * temp;
    node * iter = r;

    if(r -> x == x)
    {
        temp = r;
        r = r -> next;
        free(temp);

        return r;
    }

    while(iter -> next != NULL && iter -> next -> x != x)
    {
        iter = iter -> next;
    } //while

    if(iter -> next == NULL)
    {
        printf("failed: %d not found\n",x);
        return r; // x bulunamadı.
    }

    temp = iter -> next;
    iter -> next = temp -> next;
    free(temp);

    return r;
}//func. deleteNode

int main() 
{
    node *root; // ilk kutuyu root'a verdik
    root = NULL;  

    root = setOrderedLinkedList(root, 400);
    root = setOrderedLinkedList(root, 64);
    root = setOrderedLinkedList(root, 512);
    root = setOrderedLinkedList(root, 16);
    root = setOrderedLinkedList(root, 42);
    
    getLinkedList(root);

    root = deleteNode(root, 64);
    root = deleteNode(root, 999);
    root = deleteNode(root, 16);

    getLinkedList(root);

    return 0;
} //main
