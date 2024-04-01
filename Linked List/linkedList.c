#include <stdio.h>
#include <stdlib.h>

struct n
{
    int x;
    struct n *next; //her kutuda bir sonrakini gösteren pointer.
};

typedef struct n node; //n dediğimde node'ı kast etmiş oluyorum.

void getLinkedList(node *r) // r isminde bir node al
{
    while(r != NULL)
    {
        printf("%d \n", r -> x); // r düğümünün içeriğini yaz
        r = r -> next; // düğümü bir sonraki düğüme bağla
    }//while

    printf("\n**********\n");    

}//func

int main()
{
    int i;

    node *root; //ilk kutuyu root'a verdik

    root = (node *)malloc(sizeof(node));
    root -> x = 10;

    root -> next = (node *)malloc(sizeof(node));
    root -> next -> x = 20;

    root -> next -> next = (node *)malloc(sizeof(node));
    root -> next -> next -> x = 30;

    root -> next -> next -> next = NULL;

    node *iter;
    iter = root; //root'un gösterdiği yeri iteratior'da göstersin demek.

    printf("\n**********\n");

    printf("%d\n", iter -> x); //yani root'u yani 10 değerini gösterecek
    printf("%d\n", iter -> next -> x); //yani iter'in next'inin değeri olan 20 değerini gösterecek.

    printf("\n**********\n");    
        
    iter = root;
    int j = 0;
    
    while(iter -> next != NULL) //linked listte sonuna kadar git yani null değeri değilse devam et
    {
        j++;
        printf("%d. eleman: %d \n", j, iter -> x);
        iter = iter -> next; // her adımda iter'i bir sonraki düğüme taşı
    }//while

    printf("\n**********\n");

    int k;
    for(k = 1; k <= 5; k++)
    {
        iter -> next = (node *)malloc(sizeof(node));
        iter = iter -> next;
        iter -> x = k * 2;
        iter -> next = NULL;
    }//for

    getLinkedList(root);

 
} //main 
