#include <stdio.h>
#include <stdlib.h>

int * array = NULL;
int * array2 = NULL;
int rare = 0; //sıra
int head = 0; //sırabaşı
int size = 2;

static void fixQueue()
{
	int i;

	if(0 == head)
	{
		return;
	}

	for(i = 0; i < size; i++)
	{
		array[i] = array[i + head];
	}
	rare -= head;
	head = 0;
}

static void display()
{
	int i;

	fixQueue();

	for(i = 0; i <= size; i++)
	{
		printf("Queue[%d] -> %d\n", i, array[i]);
	}

	return;
}

static int dequeue()
{
	int i;

	if(rare == head)
	{
		printf("Queue is empty!\n");
		return -1;
	}

	if(rare - head <= size / 4)
	{
		array2 = (int *)malloc(sizeof(int) * size / 2);

		for(i = 0; i < rare - head; i++)
		{
			array2[i] = array[head + i];
		}
		rare -= head;
		head = 0;
		free(array);
		size /= 2;
		array = array2;
	}

	return array[head++];
}

static void enqueue(int a)
{
	int i;

	if(NULL == array)
	{
		array = (int *)malloc(sizeof(int) * size);
	}

	if(rare >= size)
	{
		size *= 2;
		array2 = (int *)malloc(sizeof(int) * size);

		for(i = 0; i < (size / 2); i++)
		{
			array2[i] = array[i];
		}
		free(array);
		array = array2;
	}
	array[rare++] = a;
}

int main()
{
	int i;

	for(i = 0; i < 20; i++)
	{
		enqueue(i * 10);
	}

	display();

	for(i = 0; i < 13; i++)
	{
		printf("Dequeue -> %d\n", dequeue());
	}

	display();

	for(i = 0; i < 20; i++)
	{
		enqueue(i * 10);
	}

	display();

	for(i = 0; i < 30; i++)
	{
		printf("Dequeue -> %d\n", dequeue());
	}

	display();

	return 0;
}