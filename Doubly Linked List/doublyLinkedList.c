#include <stdio.h>
#include <stdlib.h>

struct n {
    int x;
    struct n *next; // pointer to the next node in each box.
    struct n * prev;
};

typedef struct n node; // When I say n, I mean node.

void getLinkedList(node *r) // take a node named r
{
    while(r != NULL) 
    {
        printf("%d \n", r -> x); // write the content of node r
        r = r -> next; // connect the node to the next node
    }

    return;
} //func getLinkedList

node *setOrderedLinkedList(node *r, int x) 
{
    if(r == NULL) // case of empty list
    {
        r = (node *)malloc(sizeof(node));
        r -> next = NULL;
        r -> prev = NULL;
        r -> x = x;
        return r; // return the new root
    }

    if(r -> x > x) // if the first value of the existing node is greater than the incoming value
    {   
        node *temp = (node *)malloc(sizeof(node)); // create a temporary node
        temp -> x = x; // assign to temporary value 
        temp -> next = r; // since this value is smaller than the existing value, it should be at the beginning. So we make the next of temp the root
        r -> prev = temp; //
        return temp; // temp is now the root
    }

    node *iter = r; // define an iterator with the element of r

    while(iter -> next != NULL && iter -> next -> x < x) // if the value to be added is greater than the first value and smaller than the last value, we will try to place it according to a range.
    {
        iter = iter -> next;
    }

    node *temp = (node *)malloc(sizeof(node));
    temp -> next = iter -> next;
    iter -> next = temp;
    temp -> prev = iter;
    
    if(temp -> next != NULL) // if the element to be added is not the last element
    {
        temp -> next -> prev = temp;
    }

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
        return r; // x not found.
    }

    temp = iter -> next;
    iter -> next = temp -> next;
    free(temp);

    if(iter -> next != NULL) // if the value to be deleted is not the last value
    {
        iter -> next -> prev = iter;
    }

    return r;
}//func. deleteNode

int main() 
{
    node *root; // gave the first box to root
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
    root = deleteNode(root, 512);

    getLinkedList(root);

    return 0;
} //main
