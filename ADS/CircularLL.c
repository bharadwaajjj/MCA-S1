#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node *head = NULL;
Node *temp,*newnode,*current;

void insertbeg();
void insertend();
void insertmid();
void display();
void deletebeg();
void deleteend();
void deletemid();

int main()
{
    int ch;
    while(1)
    {
        printf("\nEnter your Choice\n1)Insert at beginning\n2)Insert at end\n3)Insert at Specific Position\n4)Display\n5)Delete from beginning\n6)Delete from End\n7)Delete from specific position\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insertbeg();
                break;
            case 2:
                insertend();
                break;
            case 3:
                insertmid();
                break;
            case 4:
                display();
                break;
            case 5:
                deletebeg();
                break;
            case 6:
                deleteend();
                break;
            case 7:
                deletemid();
                break;
            default:
                printf("\nWrong Choice !!");
                return 0;
        }
    }
    return 0;
}

void insertbeg()
{
    int item;
    printf("\nEnter the element :");
    scanf("%d",&item);
    newnode = (Node *)malloc(sizeof(Node));
    newnode->data = item;
    newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else{
        newnode->next = head;
        temp = head;
        while(temp->next != head)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        head=newnode;
    }
}

void insertend()
{
    int item;
    printf("Enter the data : ");
    scanf("%d",&item);
    newnode = (Node *)malloc(sizeof(Node));
    newnode->data = item;
    newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
        newnode->next=head;
    }
    else{
        temp = head;
        while(temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next=head;
    }
}

void insertmid()
{
    int pos,item,i=1;
    printf("Enter the position you want to insert Element :");
    scanf("%d",&pos);
    if(pos == 1)
    {
        insertbeg();
    }
    else{
        temp = head;
        while(i<pos-1)
        {
            temp=temp->next;
            if(temp->next == head)
            {
                printf("\nIndex out of range , So inserting at end of the list !!");
                insertend();
                return;
            }
            i++;
        }
        printf("Enter the element :");
        scanf("%d",&item);
        newnode = (Node *)malloc(sizeof(Node));
        newnode->data = item;
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void display()
{
    if(head == NULL)
    {
        printf("Empty List!!!");
    }
    else{
        temp = head;
        printf("\nElements in Linked list are :\t");
        while(temp->next!=head)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}

void deletebeg()
{
    temp = head;
    if(head == NULL){
        printf("No Elements to delete !!");
    }
    else if(temp->next == head){
        head = NULL;
    }
    else{
        temp = head;
        while(temp->next != head)
        {
            temp=temp->next;
        }
        temp->next = temp->next->next;
        head = temp->next;
    }
}

void deleteend()
{
    temp = head;
    if(head == NULL)
    {
        printf("No Elemnts to delete !!");
    }
    else if(temp->next == head){
        head = NULL;
    }
    else{
        while(temp->next->next != head)
        {
            temp=temp->next;
        }
        temp->next = temp->next->next;
    }
}

void deletemid()
{
    int pos,i=1;
    printf("Enter the postion from which you want to delete element :");
    scanf("%d",&pos);
    if(pos == 1)
    {
        deletebeg();
    }
    else{
        temp = head;
        while(i<pos-1)
        {
            temp=temp->next;
            if(temp->next == head)
            {
                printf("\nIndex out of range , so deleting last element !!");
                deleteend();
                return;
            }
        }
        temp->next=temp->next->next;
    }
}