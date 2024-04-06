#include <stdio.h>
#include <stdlib.h>

struct s
{
    int size;
    int top;
    int *array;
};

typedef struct s stack;

stack * definition()
{
    stack * s = (stack*)malloc(sizeof(stack));
    s->array = (int*)malloc(sizeof(int) * 2);
    s->size = 2;
    s->top = 0;

    return s;
}

int pop(stack * s)
{
    if (s->top < s->size / 4)
    {
        int* array2 = (int*)malloc(sizeof(int) * s->size / 2);
        int j;

        for (j = 0; j < s->top; j++)
        {
            array2[j] = s->array[j];
        }

        free(s->array);
        s->array = array2;
        s->size /= 2;
    }

    return s->array[--s->top];
}

void push(int a, stack * s)
{
    if (s->top >= s->size)
    {
        int* array2 = (int*)malloc(sizeof(int) * s->size * 2);
        int j;

        for (j = 0; j < s->top; j++)
        {
            array2[j] = s->array[j];
        }

        free(s->array);
        s->array = array2;
        s->size *= 2;
    }

    s->array[s->top++] = a;
}

void display(stack * s)
{
    int i;

    if (s->top == 0)
    {
        printf("Stack Is Empty!\n");
    }

    for (i = 0; i < s->top; i++)
    {
        printf("%d\n", s->array[i]);
    }

    printf("Size: %d\n", s->size);
}

int main()
{
    stack* s1 = definition();
    stack* s2 = definition();

    display(s1);

    int i;

    for (i = 1; i < 10; i++)
    {
        push(i * 10, s1);
    }

    display(s1);

    for (i = 1; i < 10; i++)
    {
        push(pop(s1), s2);
    }

    display(s2);

    return 0;
}
