#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* link;
};

int main(void)
{
    node *A;
    A = NULL;

    node *temp = malloc(sizeof(node));
    temp->data = 2;
    temp->link = NULL;

    A = temp;

    node *temp = malloc(sizeof(node));
    temp->data = 4;
    temp->link = NULL;

    node *temp1 = A;
    
    //traversing from head node to the last node
    while(temp1->link != NULL)
    {
        temp1 = temp1->link;
    }

    temp1->link = temp;
}