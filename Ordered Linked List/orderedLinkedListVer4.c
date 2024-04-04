#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For the constant INT_MAX

struct node
{
    int start;
    int end;
    struct node *next;
};

struct node *root = NULL;

void insert(int start, int end)
{
    // Allocate memory for a new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->start = start;
    newNode->end = end;
    newNode->next = NULL;

    // Insert the new node into the list
    if (root == NULL || start < root->start)
    {
        newNode->next = root;
        root = newNode;
    }
    else
    {
        struct node *current = root;
        while (current->next != NULL && current->next->start < start)
        {
            current = current->next;
        }
        if (current->end + 1 == start)
        {
            current->end = end;
        }
        else
        {
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    return;
}

void display(struct node *root)
{
    // Display the nodes in the list
    struct node *temp = root;
    while (temp != NULL)
    {
        printf("%dK-%dK\t", temp->start, temp->end);
        temp = temp->next;
    }
    printf("\n");
    return;
}

void deallocateMemory(struct node **pList, int start, int size)
{
    // Deallocate memory based on start and size parameters
    int end = start + size;
    struct node *temp = *pList;
    struct node *prev = NULL;

    // Allocate memory for a new node with start and end parameters
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->start = start;
    newNode->end = end;
    newNode->next = NULL;

    // Traverse through memory blocks to find the appropriate position for the new node
    while (temp != NULL)
    {
        if (temp->start > start)
        {
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    // If the previous block's end address matches the start address of the new node, update the previous block's end address
    if (prev != NULL && prev->end + 1 >= start)
    {
        prev->end = end > prev->end ? end : prev->end;
        free(newNode);
    }
    else
    {
        // Insert the new node at the appropriate position
        newNode->next = temp;
        if (prev != NULL)
        {
            prev->next = newNode;
        }
        else
        {
            *pList = newNode;
        }
    }

    // Merge adjacent memory blocks
    struct node *current = *pList;
    while (current != NULL && current->next != NULL)
    {
        struct node *nextNode = current->next;
        if (current->end + 1 > nextNode->start)
        {
            current->end = nextNode->end > current->end ? nextNode->end : current->end;
            current->next = nextNode->next;
            free(nextNode);
        }
        else
        {
            current = current->next;
        }
    }

    display(*pList);

    return;
}

void allocateMemory(struct node **pList, int start, int size)
{
    struct node *temp = *pList;
    struct node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->start >= start && temp->end <= start + size)
        {
            // Delete the current node
            struct node *toDelete = temp;
            temp = temp->next;
            if (prev != NULL)
            {
                prev->next = temp;
            }
            else
            {
                *pList = temp;
            }
            free(toDelete);
        }
        else if (temp->start <= start && temp->end >= start + size)
        {
            // Split the current node into two nodes
            struct node *newNode = (struct node *)malloc(sizeof(struct node));
            newNode->start = start + size;
            newNode->end = temp->end;
            newNode->next = temp->next;
            temp->end = start;
            temp->next = newNode;
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    // Remove all nodes where end-start difference is 0 except the newly inserted node
    struct node *current = *pList;
    struct node *prevToDelete = NULL;
    while (current != NULL)
    {
        if (current->end - current->start == 0 && current != temp) // Skip the newly inserted node
        {
            if (prevToDelete != NULL)
            {
                prevToDelete->next = current->next;
            }
            else
            {
                *pList = current->next;
            }
            struct node *toDelete = current;
            current = current->next;
            free(toDelete);
        }
        else
        {
            prevToDelete = current;
            current = current->next;
        }
    }

    display(*pList);

    return;
}

void allocateMemoryOnlySize(struct node **pList, int size)
{
    // Allocate memory for a specific size without specifying a starting point
    struct node *temp = *pList;
    struct node *bestFitNode = NULL;
    struct node *prev = NULL;
    int minDiff = INT_MAX; // Minimum difference between block size and required size

    // Find the best fit block for the required size
    while (temp != NULL)
    {
        int diff = temp->end - temp->start + 1 - size;
        if (diff >= 0 && diff < minDiff)
        {
            // If the current block is large enough and closer to the required size
            minDiff = diff;
            bestFitNode = temp;
        }
        prev = temp;
        temp = temp->next;
    }

    // If a suitable block is found
    if (bestFitNode != NULL)
    {
        // If the block size matches the required size exactly, delete the block
        if (minDiff == 0)
        {
            if (prev != NULL)
            {
                prev->next = bestFitNode->next;
            }
            else
            {
                *pList = bestFitNode->next;
            }
            free(bestFitNode);
        }
        else
        {
            // Adjust the start of the best fit block to allocate the required size
            bestFitNode->start += size;

            // If the block is completely filled, remove it from the list
            if (bestFitNode->start > bestFitNode->end)
            {
                if (prev != NULL)
                {
                    prev->next = bestFitNode->next;
                }
                else
                {
                    *pList = bestFitNode->next;
                }
                free(bestFitNode);
            }
        }
    }
    else
    {
        // No block of the specified size found
        printf("No block of size %dK found to allocate.\n", size);
    }

    // Remove all nodes where end-start difference is 0
    struct node *current = *pList;
    struct node *prevToDelete = NULL;
    while (current != NULL)
    {
        if (current->end - current->start == 0)
        {
            if (prevToDelete != NULL)
            {
                prevToDelete->next = current->next;
            }
            else
            {
                *pList = current->next;
            }
            struct node *toDelete = current;
            current = current->next;
            free(toDelete);
        }
        else
        {
            prevToDelete = current;
            current = current->next;
        }
    }

    // Display the updated list
    display(*pList);

    return;
}

int main()
{

    printf("\n");
    printf("Deallocate 900K-905K:\n");
    deallocateMemory(&root, 900, 5);
    printf("\n");
    printf("Deallocate 26K-29K:\n");
    deallocateMemory(&root, 26, 3);
    printf("\n");
    printf("Allocate 26K-29K:\n");
    allocateMemory(&root, 26, 3);
    printf("\n");
    printf("Deallocate 3K-4K:\n");
    deallocateMemory(&root, 3, 1); 
    printf("\n");
    printf("Deallocate 17K-18K:\n");
    deallocateMemory(&root, 17, 1);
    printf("\n");
    printf("Deallocate 920K-930K:\n"); 
    deallocateMemory(&root, 920, 10);
    printf("\n");
    printf("Deallocate 16K-17K:\n"); 
    deallocateMemory(&root, 16, 1);
    printf("\n");
    printf("Deallocate 9K-10K:\n"); 
    deallocateMemory(&root, 9, 1);
    printf("\n");
    printf("Deallocate 8K-9K:\n"); 
    deallocateMemory(&root, 8, 1);
    printf("\n");
    printf("Deallocate 19K-20K:\n"); 
    deallocateMemory(&root, 19, 1);
    printf("\n");
    printf("Deallocate 18K-19K:\n"); 
    deallocateMemory(&root, 18, 1);
    printf("\n");
    printf("Deallocate 24K-26K:\n"); 
    deallocateMemory(&root, 24, 2);
    printf("\n");
    printf("Deallocate 1K-3K:\n"); 
    deallocateMemory(&root, 1, 2);
    printf("\n");
    printf("Deallocate 29K-30K:\n"); 
    deallocateMemory(&root, 29, 1);
    printf("\n");
    printf("Allocate 2K-3K:\n");
    allocateMemory(&root, 2, 1);
    printf("\n");
    printf("Allocate 24K-26K:\n");
    allocateMemory(&root, 24, 2);
    printf("\n");
    printf("Allocate 18K-19K:\n");
    allocateMemory(&root, 18, 1);
    printf("\n");
    printf("Allocate 19K-20K:\n");
    allocateMemory(&root, 19, 1);
    printf("\n");
    printf("Allocate 8K-9K:\n");
    allocateMemory(&root, 8, 1);
    printf("\n");
    printf("Allocate 9K-10K:\n");
    allocateMemory(&root, 9, 1);
    printf("\n");
    printf("Allocate 16K-17K:\n");
    allocateMemory(&root, 16, 1);
    printf("\n");
    printf("Allocate 17K-18K:\n");
    allocateMemory(&root, 17, 1);
    printf("\n");
    printf("Deallocate 28K-29K:\n"); 
    deallocateMemory(&root, 28, 1);
    printf("\n");
    printf("Deallocate 17K-18K:\n"); 
    deallocateMemory(&root, 17, 1);
    printf("\n");
    printf("Deallocate 16K-17K:\n"); 
    deallocateMemory(&root, 16, 1);
    printf("\n");
    printf("Deallocate 899K-900K:\n"); 
    deallocateMemory(&root, 899, 1);
    printf("\n");
    printf("Deallocate 27K-28K:\n"); 
    deallocateMemory(&root, 27, 1);
    printf("\n");
    printf("Deallocate 18K-27K:\n"); 
    deallocateMemory(&root, 18, 9);
    printf("\n");
    printf("Allocate 15K-20K:\n");
    allocateMemory(&root, 15, 5);
    printf("\n"); 
    printf("Deallocate 30K-80K:\n"); 
    deallocateMemory(&root, 30, 50);
    printf("\n");  
    printf("Deallocate 17K-18K:\n"); 
    deallocateMemory(&root, 17, 1);
    printf("\n");  
    printf("Allocate 19K-21K:\n");
    allocateMemory(&root, 19, 2);
    printf("\n");
    printf("Allocate Only Size 1K:\n");
    allocateMemoryOnlySize(&root, 1);
    printf("\n");
    printf("Deallocate 90K-107K:\n"); 
    deallocateMemory(&root, 90, 17);
    printf("\n");
    printf("Deallocate 18K-20K:\n"); 
    deallocateMemory(&root, 18, 2);
    printf("\n");
    printf("Allocate Only Size 6K:\n");
    allocateMemoryOnlySize(&root, 6);
    printf("\n");
    printf("Deallocate 180K-200K:\n"); 
    deallocateMemory(&root, 180, 20);
    printf("\n");
    printf("Deallocate 250K-270K:\n"); 
    deallocateMemory(&root, 250, 20);
    printf("\n");
    printf("Deallocate 300K-320K:\n"); 
    deallocateMemory(&root, 300, 20);
    printf("\n");
    printf("Allocate 29K-32K:\n");
    allocateMemory(&root, 29, 3);
    printf("\n");
    printf("Allocate Only Size 8K:\n");
    allocateMemoryOnlySize(&root, 8);
    printf("\n");
    printf("Allocate 303K-320K:\n");
    allocateMemory(&root, 303, 17);
    printf("\n");
    printf("Allocate Only Size 2K:\n");
    allocateMemoryOnlySize(&root, 2); //zsh: segmentation fault
    printf("\n");
    
    return 0;
}
