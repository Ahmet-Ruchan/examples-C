#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // for the const INT_MAX
#include <time.h>
#include <unistd.h>
#define int_max 2147483647

struct node
{
    int start;
    int end;
    struct node * next;
};

static void initMemory(struct node **root)
{
    *root = NULL;
    return;
}

static void display(struct node * root)
{
    while(NULL != root)
    {
        printf("[%dK-%dK] \t", root -> start, root -> end);
        root = root -> next;
    }

    printf("\n");

    return;
}

static void deallocateMemory(struct node **pList, int start, int size)
{
    int end = start + size;

    struct node * temp = *pList; // Listenin başını gösteren bir temp değişkeni oluşturduk
    struct node * prev = NULL; // Bir önceki düğümü gösteren bir prev değişkeni oluşturduk

    // Uygun konumu bulana kadar listeyi dolaşıyor, dolaşırken temp ve prevleri atıyor.
    while(NULL != temp)
    {
        if(temp -> start > start)
        {
            break;
        }
        prev = temp;
        temp = temp -> next;
    }

    // Uygun blok ile newNode arasında çakışma varsa düğümü güncelle
    if(NULL != prev && prev -> end >= start)
    {
        if((NULL != temp) && (prev -> start <= start) && (temp -> start != end) && (prev -> start + size <= prev -> end) && (prev -> end > start)) 
        {
            
        }
        else if(NULL != prev && end > prev -> end)
        {
            prev -> end = end;
        }
    }
    else // Eğer çakışma yoksa, newNode'u araya ya da listenin başına ekle
    {
        struct node * newNode = (struct node *)malloc(sizeof(struct node));

        newNode -> start = start;
        newNode -> end = end;
        newNode -> next = temp;

        if(NULL != prev)
        {
            prev -> next = newNode;
        }
        else
        {
            *pList = newNode;
        }
    }

    // Yeni düğüm son düğüm mü?
    if(NULL == temp)
    {
        struct node * newNode = (struct node *)malloc(sizeof(struct node));

        newNode -> start = start;
        newNode -> end = end;
        newNode -> next = NULL;
    }

    // Kesişen düğümleri birleştirme
    struct node * current = *pList; // Listenin başını current değişkenine ata

    while(NULL != current && NULL != current -> next)
    {
        struct node * nextNode = current -> next;

        if(current -> end == nextNode -> start)
        {
            if(nextNode -> end >= current -> end)
            {
                current -> end = nextNode -> end;
            }

            current -> next = nextNode -> next;
            free(nextNode);
        }
        else
        {
            current = current -> next;
        }
    }

    printf("deallocateMemory(root, %dK, %dK)\n", start, size);
    display(*pList);

    return;
}

static void allocateMemory(struct node **pList, int start, int size)
{
    struct node * temp = *pList; // Listenin başını temp değişkenine atıyoruz
    struct node * prev = NULL;

    while(NULL != temp)
    {
        if(temp -> start == start && temp -> end == start + size)
        {
            // Tam olarak uyan düğüm varsa siler
            struct node * toDelete = temp;

            temp = temp -> next;

            if(NULL != prev)
            {
                prev -> next = temp;
            }
            else
            {
                *pList = temp;
            }

            free(toDelete);
            break;
        }
        else if(temp -> start == start && NULL == prev)
        {
            temp -> start = start + size;
        }
        else if(temp -> start <= start && temp -> end >= start + size)
        {
            struct node * newNode = (struct node *)malloc(sizeof(struct node));

            newNode -> start = start + size;
            newNode -> end = temp -> end;
            newNode -> next = temp -> next;

            if(temp -> start == start)
            {
                prev -> next = newNode;
            }
            else
            {
                temp -> end = start;
                temp -> next = newNode;
            }

            if(newNode -> start == newNode -> end)
            {
                temp -> next = newNode -> next;
                free(newNode);
            }
        }

        prev = temp;
        temp = temp -> next;
    }

    printf("allocateMemory(root, %dK, %dK)\n", start, size);
    display(*pList);

    return; 
}

static void allocateMemoryOnlySize(struct node **pList, int size)
{
    struct node *temp = *pList;
    struct node *bestFitNode = NULL;
    struct node *prev = NULL;
    int minDiff = int_max;
    int tempSize;

    if(NULL == temp)
    {
        printf("Linked List Is Empty! \n");
        return;
    }

    while (NULL != temp)
    {
        tempSize = temp->end - temp->start;

        if (tempSize >= size && (NULL == bestFitNode || tempSize < minDiff))
        {
            bestFitNode = temp;
            minDiff = tempSize;
        }

        if(NULL == temp -> next)
        {
          break;
        }
        
        if(minDiff == size)
        {
          temp = temp -> next;
        }
        else
        {
          prev = temp;
          temp = temp -> next;
        } 
    }

    // En uygun uyumlu düğüm bulundu
    if(minDiff == size)
    {
        if(NULL != prev)
        {
            prev -> next = bestFitNode -> next;
            if(*pList == prev)
            {
              prev = NULL;
            }
        }
        else
        {
            *pList = bestFitNode -> next;
        }
        free(bestFitNode);
    }
    else
    {
        bestFitNode -> start = bestFitNode -> start + size;
    }

    printf("allocateMemoryOnlySize(root, %dK)\n", size);
    display(*pList);

    return;
}

static void runTest()
{
    struct node *root;
    initMemory(&root);

    printf("\n");
    deallocateMemory(&root, 900, 5);
    printf("\n");

    deallocateMemory(&root, 26, 3);
    printf("\n");

    allocateMemory(&root, 26, 3);
    printf("\n");

    deallocateMemory(&root, 3, 1);
    printf("\n");

    deallocateMemory(&root, 17, 1);
    printf("\n");

    deallocateMemory(&root, 920, 10);
    printf("\n");

    deallocateMemory(&root, 16, 1);
    printf("\n");

    deallocateMemory(&root, 9, 1);
    printf("\n");

    deallocateMemory(&root, 8, 1);
    printf("\n");

    deallocateMemory(&root, 19, 1);
    printf("\n");

    deallocateMemory(&root, 18, 1);
    printf("\n");

    deallocateMemory(&root, 24, 2);
    printf("\n");

    deallocateMemory(&root, 1, 2);
    printf("\n");

    deallocateMemory(&root, 29, 1);
    printf("\n");

    allocateMemory(&root, 2, 1);
    printf("\n");

    allocateMemory(&root, 24, 2);
    printf("\n");

    allocateMemory(&root, 18, 1);
    printf("\n");

    allocateMemory(&root, 19, 1);
    printf("\n");

    allocateMemory(&root, 8, 1);
    printf("\n");

    allocateMemory(&root, 9, 1);
    printf("\n");

    allocateMemory(&root, 16, 1);
    printf("\n");

    allocateMemory(&root, 17, 1);
    printf("\n");

    deallocateMemory(&root, 28, 1);
    printf("\n");

    deallocateMemory(&root, 17, 1);
    printf("\n");

    deallocateMemory(&root, 16, 1);
    printf("\n");

    deallocateMemory(&root, 899, 1);
    printf("\n");

    deallocateMemory(&root, 27, 1);
    printf("\n");

    deallocateMemory(&root, 18, 9);
    printf("\n");

    allocateMemory(&root, 15, 5);
    printf("\n");

    deallocateMemory(&root, 30, 50);
    printf("\n");

    deallocateMemory(&root, 17, 1);
    printf("\n");

    allocateMemory(&root, 19, 2);
    printf("\n");

    allocateMemoryOnlySize(&root, 1);
    printf("\n");

    deallocateMemory(&root, 90, 17);
    printf("\n");

    deallocateMemory(&root, 18, 2);
    printf("\n");

    allocateMemoryOnlySize(&root, 6);
    printf("\n");

    deallocateMemory(&root, 180, 20);
    printf("\n");

    deallocateMemory(&root, 250, 20);
    printf("\n");

    deallocateMemory(&root, 300, 20);
    printf("\n");

    allocateMemory(&root, 29, 3);
    printf("\n");

    allocateMemoryOnlySize(&root, 8);
    printf("\n");

    allocateMemory(&root, 303, 17);
    printf("\n");

    allocateMemoryOnlySize(&root, 2);
    printf("\n");

    allocateMemory(&root, 92, 15);
    printf("\n");

    deallocateMemory(&root, 303, 20);
    printf("\n");

    allocateMemoryOnlySize(&root, 1);
    printf("\n");

    deallocateMemory(&root, 92, 20);
    printf("\n");

    allocateMemoryOnlySize(&root, 25);
    printf("\n");

    allocateMemoryOnlySize(&root, 15);
    printf("\n");

    allocateMemoryOnlySize(&root, 22);
    printf("\n");

    allocateMemoryOnlySize(&root, 22);
    printf("\n");

    allocateMemoryOnlySize(&root, 22);
    printf("\n");

    deallocateMemory(&root, 25, 7);
    printf("\n");

    allocateMemory(&root, 195, 5);
    printf("\n");

    allocateMemoryOnlySize(&root, 1);
    printf("\n");

    allocateMemoryOnlySize(&root, 1);
    printf("\n");

    deallocateMemory(&root, 300, 20);
    printf("\n");

    allocateMemoryOnlySize(&root, 7);
    printf("\n");

    allocateMemoryOnlySize(&root, 20);
    printf("\n");

    allocateMemoryOnlySize(&root, 20);
    printf("\n");

    allocateMemoryOnlySize(&root, 6);
    printf("\n");

    allocateMemoryOnlySize(&root, 2);
    printf("\n");

    allocateMemoryOnlySize(&root, 2);
    printf("\n");

    deallocateMemory(&root, 400, 40);
    printf("\n");

    deallocateMemory(&root, 40, 40);
    printf("\n");

    deallocateMemory(&root, 100, 40);
    printf("\n");

    allocateMemory(&root, 100, 5);
    printf("\n");

    allocateMemory(&root, 430, 10);
    printf("\n");

    allocateMemory(&root, 70, 10);
    printf("\n");

    deallocateMemory(&root, 430, 40);
    printf("\n");

    deallocateMemory(&root, 70, 20);
    printf("\n");

    deallocateMemory(&root, 950, 40);
    printf("\n");

    allocateMemory(&root, 420, 5);
    printf("\n");

    allocateMemory(&root, 950, 5);
    printf("\n");

    deallocateMemory(&root, 95, 5);
    printf("\n");

    deallocateMemory(&root, 330, 40);
    printf("\n");

    deallocateMemory(&root, 480, 40);
    printf("\n");

    deallocateMemory(&root, 90, 4);
    printf("\n");

    deallocateMemory(&root, 140, 40);
    printf("\n");

    deallocateMemory(&root, 990, 40);
    printf("\n");

    deallocateMemory(&root, 94, 1);
    printf("\n");

    deallocateMemory(&root, 370, 30);
    printf("\n");

    deallocateMemory(&root, 520, 435);
    printf("\n");

    allocateMemory(&root, 40, 10);
    printf("\n");

    allocateMemory(&root, 322, 10);
    printf("\n");

    allocateMemory(&root, 480, 10);
    printf("\n");

    allocateMemory(&root, 490, 540);
    printf("\n");

    allocateMemory(&root, 50, 50);
    printf("\n");

    allocateMemory(&root, 110, 20);
    printf("\n");

    allocateMemory(&root, 330, 10);
    printf("\n");

    allocateMemory(&root, 350, 10);
    printf("\n");

    allocateMemory(&root, 430, 10);
    printf("\n");

    return;
}

void randomTest()
{
    int operation;
    int start;
    int size;
    struct node *root;

    srand(time(NULL));
    initMemory(&root);
    
    while(1)
    {
        operation = rand() % 3;

        switch (operation)
        {
        case 0: //deallocateMemory
            start = rand() % 1000 + 1;
            size = rand() % 100 + 1;
            deallocateMemory(&root, start, size);
            sleep(1);
            break;
        
        case 1: //allocateMemory
            start = rand() % 1000 + 1;
            size = rand() % 100 + 1;
            allocateMemory(&root, start, size);
            sleep(1);
            break;
        
        case 2: //allocateMemoryOnlySize
            size = rand() % 100 + 1;
            allocateMemoryOnlySize(&root, size);
            sleep(1);
            break;
        
        default:
            break;
        }
    }
}

int main()
{

    runTest(); 
    //randomTest(); //Sonsuz döngü olduğu için yorum satırında. 

    return 0;
}
