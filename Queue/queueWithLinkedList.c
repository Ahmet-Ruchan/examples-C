#include <stdio.h>
#include <stdlib.h>

struct n{

	int data;
	struct n * next;
};

typedef struct n node;

node * root = NULL;
node * end = NULL;

static void enqueue(int x)
{
	if(NULL == root)
	{
		root = (node *)malloc(sizeof(node));
		root -> data = x;
		root -> next = NULL;
		end = root;
	}
	else
	{
		end -> next = (node *)malloc(sizeof(node));
		end -> next -> data = x;
		end = end -> next;
		end -> next = NULL;
	}

	return;
}

static int dequeue()
{
	int rvalue;

	if(NULL == root)
	{
		printf("Linked list is empty!\n");
		return -1;
	}

	rvalue = root -> data;
	node * temp = root;
	root = root -> next;
	free(temp);

	return rvalue;
}

int main()
{
	int i;

	for(i = 0; i < 20; i++)
	{
		enqueue(i * 10);
	}

	for(i = 0; i < 13; i++)
	{
		printf("Dequeue -> %d\n", dequeue());
	}

	for(i = 0; i < 20; i++)
	{
		enqueue(i * 10);
	}

	for(i = 0; i < 30; i++)
	{
		printf("Dequeue -> %d\n", dequeue());
	}

	return 0;
}
