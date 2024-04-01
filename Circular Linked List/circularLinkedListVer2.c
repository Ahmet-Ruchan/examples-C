#include <stdio.h>
#include <stdlib.h>

#define kb 1024 // 1 KB

struct n
{
    int x;
    struct n *next; // her kutuda bir sonrakini gösteren pointer.
};

typedef struct n node; // n dediğimizde node'ı kast etmiş oluyoruz.

struct MemoryBlock
{
    int startAddr; // Bellek bloğunun başlangıç adresi
    int size;      // Bellek bloğunun boyutu
};

typedef struct MemoryBlock MemoryBlock;

struct LinkedList
{
    node *first; // İlk düğümün adresini tutar
    node *last;  // Son düğümün adresini tutar
    MemoryBlock *memory; // Belleği temsil eden yapı
};

typedef struct LinkedList LinkedList; // LinkedList struct'ını LinkedList olarak yeniden adlandırdık

void getLinkedList(LinkedList *list)
{
    if (list->first == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    node *iter = list->first;
    do 
    {
        printf("%d \n", iter->x);
        iter = iter->next;
    } while (iter != NULL && iter != list->first);

    return;
}

void setOrderedLinkedList(LinkedList *list, int x)
{
    node *newNode = (node *)malloc(sizeof(node));
    
    if (newNode == NULL)
    {
        printf("Memory allocation failed! Unable to add %d to the list.\n", x);
        return;
    }
    newNode->x = x;

    // Liste boşsa veya eklenen eleman ilk elemandan küçükse
    if (list->first == NULL || x < list->first->x)
    {
        newNode->next = list->first;
        list->first = newNode;
        if (list->last == NULL) {
            list->last = newNode;
        }
        return;
    }

    // Listenin içinde uygun konuma yerleştirme işlemi yapılmalı
    node *prev = NULL;
    node *iter = list->first;

    while (iter != NULL && iter->x < x)
    {
        prev = iter;
        iter = iter->next;
    }

    newNode->next = iter;
    prev->next = newNode;
    
    if (iter == NULL)
    { // Yeni eleman listenin sonuna eklendi
        list->last = newNode;
    }

    return;
}

void deleteNode(LinkedList *list, int x)
{
    if (list->first == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    node *prev = NULL;
    node *iter = list->first;

    while (iter != NULL && iter->x != x)
    {
        prev = iter;
        iter = iter->next;
    }

    if (iter == NULL)
    {
        printf("Value %d not found!\n", x);
        return;
    }

    if (prev != NULL)
    {
        prev->next = iter->next;
    } 
    else
    {
        list->first = iter->next;
    }

    if (iter == list->last)
    {
        list->last = prev;
    }

    free(iter);
    printf("Value %d deleted!\n", x);

    return;
}

void bellekIadeEt(LinkedList *list, int startAddr, int size)
{
    // Bellek bloğunu iade etmek için kullanılan adres aralığını yazdır
    printf("%dK-%dK\n", startAddr / kb, (startAddr + size) / kb);

    // Bağlı listenin her düğümünü dolaşarak belleği iade et
    node *current = list->first;
    int freedCount = 0; // İade edilen bellek bloğu sayısını izlemek için bir sayaç

    while (current != NULL)
    {
        if (current->x >= startAddr && current->x < startAddr + size)
        {
            current->x = -1; // Belleği temsil eden değeri güncelle
            freedCount++; // Bellek bloğunun iade edildiğini sayaca ekle
        }
        current = current->next;
    }

    // İade edilen bellek bloğu sayısını kontrol et ve gerekli mesajı gönder
    if (freedCount > 0)
    {
        printf("Memory block from address %d returned successfully! (%d nodes freed)\n", startAddr, freedCount);
    } 
    else
    {
        printf("No memory block found in the specified range (%dK-%dK)\n", startAddr / kb, (startAddr + size) / kb);
    }

    return;
}


int main()
{
    LinkedList list;
    list.first = NULL;
    list.last = NULL;
    list.memory = NULL;

    printf("Adding 400 to the list\n");
    setOrderedLinkedList(&list, 400);

    printf("Adding 64 to the list\n");
    setOrderedLinkedList(&list, 64);

    printf("Adding 512 to the list\n");
    setOrderedLinkedList(&list, 512);

    printf("Adding 16 to the list\n");
    setOrderedLinkedList(&list, 16);

    printf("Adding 42 to the list\n");
    setOrderedLinkedList(&list, 42);

    printf("Printing the list:\n");
    getLinkedList(&list);

    printf("Deleting 64 from the list\n");
    deleteNode(&list, 64);

    printf("Deleting 99 from the list\n");
    deleteNode(&list, 99);

    printf("Printing the list after deletions:\n");
    getLinkedList(&list);

    bellekIadeEt(&list, 900 * kb, 5 * kb);

    return 0;
}
