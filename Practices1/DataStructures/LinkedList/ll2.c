//inserting a node at the beginning

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} node;

node* head;

void insert(int x);
void Print();

int main(void)
{
    head = NULL; //head pointing to NULL //empty list

    int n, x, i;

    printf("Qty: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &x);
        insert(x);
        Print();
    }
}

void insert(int x)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->next = head; //when the list is empty, head is already pointing to NULL (from line 14)
    head = temp; //pointing head to temp address
}

void Print()
{
    node* temp = head; //pointer temp points to the head
    printf("List is: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
