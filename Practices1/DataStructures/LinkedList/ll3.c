//inserting a node at the nth position

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} node;

node* head;

void insert(int data, int n); //argv for data = value to insert, argv for n = position to insert
void Delete(int n); //position to delete
void DeleteData(int data);
void Print();

int main(void)
{
    int n, da;
    
    head = NULL; //head pointing to NULL //empty list
    insert(2, 1);
    insert(5, 2);
    insert(4, 1);
    insert(6, 2);
    insert(7, 3);
    Print();
    
    /*printf("Which position to delete? ");
    scanf("%d", &n);
    Delete(n);
    Print();*/
    
    printf("Which data to delete? ");
    scanf("%d", &da);
    DeleteData(da);
    Print();
}

void insert(int data, int n)
{
    node* temp1 = (node*)malloc(sizeof(node));
    temp1->data = data;
    temp1->next = NULL;
    if(n == 1)
    {
        temp1->next = head;
        head = temp1; //head will point to temp1(the newly created data)
        return;
    }
    node* temp2 = head; //storing the address that head is pointing to(pointing to the node that head is pointing at)
    for(int i = 1; i < n - 1; i++)
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void Print()
{
    node* temp = head; //pointer temp points to what the head is pointing at 
                        // stores the address of node that the head is pointing at
    printf("List is: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Delete(int n)
{
    node* temp1 = head;
    if(n == 1)
    {
        head = temp1->next;
        free(temp1);
    }
    for(int i = 1; i < n - 1; i++)
    temp1 = temp1->next;
    
    node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}

void DeleteData(int data)
{
    int cnt = 0;
    node* temp1 = head;
    node* temp0 = head;
    while(temp1->data != data)
    {
        temp1 = temp1->next;
        cnt++;
    }
    for(int i = 0; i < cnt - 1; i++)
    temp0 = temp0->next;
    
    node* temp2 = temp0->next;
    temp0->next = temp2->next;
    free(temp2);
}
