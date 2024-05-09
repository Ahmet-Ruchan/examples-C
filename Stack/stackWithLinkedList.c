#include <stdio.h>
#include <stdlib.h>

struct n
{
    struct n *next;
    int data;
};

typedef struct n node;

static void display(node* root)
{
    if(NULL == root)
    {
        printf("Stack is empty!\n");
    }
    
    while(root != NULL)
    {
        printf("-> %d\n", root -> data);
        root = root -> next;
    }

    return;
}

static int pop(node *root)
{
    int rvalue;

    if (NULL == root)
    {
        printf("Stack is empty!\n");
        return -1;
    }

    if (NULL == root->next)
    {
        rvalue = root->data;
        free(root);

        return rvalue;
    }

    node *iter = root;

    while (iter->next->next != NULL)
    {
        iter = iter->next;
    }

    node *temp = iter->next;
    rvalue = temp->data;
    iter->next = NULL;
    free(temp);

    return rvalue;
}

node *push(node *root, int a)
{
    if (NULL == root)
    {
        root = (node *)malloc(sizeof(node));
        root->data = a;
        root->next = NULL;

        return root;
    }

    node *iter = root;

    while (iter->next != NULL)
    {
        iter = iter->next;
    }

    node *temp = (node *)malloc(sizeof(node));
    temp->data = a;
    temp->next = NULL;
    iter->next = temp;

    return root;
}

int main()
{
    node *s = NULL;

    s = push(s, 10);
    s = push(s, 20);

    display(s);

    printf("pop -> %d\n", pop(s));
    printf("pop -> %d\n", pop(s));

    return 0;
}
