#include <stdio.h>
#include <stdlib.h>

struct node
{
	int start;
	int end;
	struct node * next;
};

struct node * root = NULL;

void insert(int start, int end)
{
	struct node * newNode = (struct node *)malloc(sizeof(struct node));
	newNode -> start = start;
	newNode -> end = end;
	newNode -> next = NULL;

	if(root == NULL || start < root -> start)
	{
		newNode -> next = root;
		root = newNode;
	}//if
	else
	{
		struct node * current = root;

		while(current -> next != NULL && current -> next -> start < start)
		{
			current = current -> next;
		}//while

		if(current -> end + 1 == start)
		{
			current -> end = end;
		}//if
		else
		{
			newNode -> next = current -> next;
			current -> next = newNode;
		}//else
	}//else

	return;
}//insert func.

void display(struct node * root)
{
	struct node * temp = root;

	while(temp != NULL)
	{
		printf("%dK-%dK\t", temp -> start, temp -> end);
		temp = temp ->next;
	}

	printf("\n");

	return;
}//func. display

void allocateMemory(struct node ** pList, int start, int size)
{
    int end = start + size;
    struct node * temp = *pList;

    while(temp != NULL)
    {
        if((temp -> start <= start && temp -> end >= end) || (temp -> start >= start && temp -> end <= end) || (temp -> start <= start && temp -> end >= start) || (temp -> start <= end && temp -> end >= end))
        {
            printf("Warning: Memory block %dK-%dK overlaps with an existing allocation!\n", start, end);
            return;
        }

        temp = temp -> next;
    }

    temp = *pList;
    struct node * prev = NULL;

    while(temp != NULL)
    {
        if(temp -> start > start)
        {
            break;
        }

        prev = temp;
        temp = temp -> next;
    }

    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode -> start = start;
    newNode -> end = end;
    newNode -> next = NULL;

    if(prev != NULL)
    {
        prev -> next = newNode;
    }
    else
    {
        *pList = newNode;
    }

    newNode -> next = temp;
	display(*pList);

    return;

}//func. allocateMemory

void deallocateMemory(struct node ** pList, int start, int size)
{
	struct node * temp = *pList;
	struct node * prev = NULL;

	while(temp != NULL)
	{
		if(temp -> start <= start && temp -> end >= start + size)
		{
			if(temp -> start == start && temp -> end == start + size)
			{
				if(prev != NULL)
				{
					prev -> next = temp -> next;
				}//if
				else
				{
					*pList = temp -> next;
				}

				free(temp);
				display(*pList);

				return;
			}//if
			else if(temp -> start == start)
			{
				temp -> start += size;
			}//else if
			else if(temp -> end == start + size)
			{
				temp -> end -= size;
				display(*pList);

				return;
			}//else if
			else
			{
				struct node * newNode = (struct node *)malloc(sizeof(struct node));
				newNode -> start = start + size;
				newNode -> end = temp -> end;
				newNode -> next = temp -> next;
				temp -> end = start - 1;
				temp -> next = newNode;

				display(*pList);

				return;
			}//else
		}//if

		prev = temp;
		temp = temp -> next;
	}

	printf("Warning: Memory block %dK-%dK is not found!\n", start, start + size);

	return;
}//func. deallocateMemory

int main()
{
	printf("\n");
	printf("Allocate 900K-905K:\n");
    allocateMemory(&root, 900, 5);
    printf("\n");
    printf("Allocate 26K-29K:\n");
    allocateMemory(&root, 26, 3);
    printf("\n");
    printf("Deallocate 26K-29K:\n");
    deallocateMemory(&root, 26, 3);
    printf("\n");
    printf("Allocate 3K-4K:\n");
    allocateMemory(&root, 3, 1); //3K-4K
    printf("\n");
    printf("Allocate 17K-18K:\n");
    allocateMemory(&root, 17, 1);
    printf("\n");
    printf("Allocate 920K-930K:\n"); //920K-930K
    allocateMemory(&root, 920, 10);
    printf("\n");
    printf("Allocate 300K-320K:\n"); //300K-320K
    allocateMemory(&root, 300, 20);
    printf("\n");
    printf("Deallocate 17K-18K:\n");
    deallocateMemory(&root, 17, 1);
    printf("\n");
    printf("Deallocate 17K-18K:\n");
    deallocateMemory(&root, 17, 1); //Warning: Memory block 17K-18K is not found!
    printf("\n");
    printf("Allocate 500K-507K:\n");
    allocateMemory(&root, 500, 7); //500K-507K
    printf("\n");
    printf("Allocate 500K-507K:\n"); //Warning: Memory block 500K-507K overlaps with an existing allocation!
    allocateMemory(&root, 500, 7);
    printf("\n");
    printf("Allocate 310K-315K:\n"); //Warning: Memory block 310K-315K overlaps with an existing allocation!
    allocateMemory(&root, 310, 5);
    printf("\n");
    printf("Allocate 4K-7K:\n"); //Warning: Memory block 4K-7K overlaps with an existing allocation!
    allocateMemory(&root, 4, 3);
    printf("\n");
    printf("Allocate 6K-9K:\n");
    allocateMemory(&root, 6, 3); //6K-9K
    printf("\n");
    printf("Allocate 5K-6K:\n");
    allocateMemory(&root, 5, 1); //Warning: Memory block 5K-6K overlaps with an existing allocation!
    printf("\n");
    printf("Deallocate 920K-925K\n");
    deallocateMemory(&root, 920, 5); //Warning: Memory block 920K-925K is not found!
    printf("\n");
    printf("Allocate 503K-510K:\n");
    allocateMemory(&root, 503, 7);
    printf("\n");
    printf("Allocate 490K-505K:\n"); 
    allocateMemory(&root, 490, 15); //Warning: Memory block 490K-505K overlaps with an existing allocation!
    printf("\n");
    
    return 0;
}

