#include<stdio.h>
#include<stdlib.h>

void insatbeg();
void insatend();
void insatpos();
void display();
void delete();
                                    /* creating node structure*/ 
typedef struct node{                /* typedef used to refer 'struct node' as 'node' */ 
    int data;                                                               /* | */ 
    struct node* next;                                                      /* | */ 
}node;            /* <--------------------------------------------------------- */ 

node* head = NULL;
node *current;

void main(){
    int is_running=1, ch;
    while(is_running){
        printf("\n\n1.Insert at beginning\n2.Insert at end\n3.Insert at position\n4.Delete\n5.Display\n6.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            insatbeg();                             /* insert at begining*/ 
            break;
        case 2:
            insatend();                            /* insert at end */ 
            break;
        case 3:
            insatpos();                            /* insert to specified position */ 
            break;
        case 4:
            delete();                                /* deleting a node */ 
            break;
        case 5:
            display();                                 /* display all the nodes   */ 
            break;
        case 6:
            is_running = 0;
            break;
        default:
            printf("\nWrong Choice :(\n");
            break;
        }
    }
}

void insatbeg(){
    node* newnode;
    newnode = (node*)malloc(sizeof(node));
    int data;
    printf("\nEnter the data to be added: ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = NULL;
    if(head==NULL){
        head = newnode;
    }
    else{
        newnode->next = head;
        head = newnode;
    }
}

void insatend(){
    node* newnode;
    newnode = (node*)malloc(sizeof(node));
    int data;
    printf("\nEnter the data to be added: ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = NULL;
    if(head==NULL){
        head = newnode;
    }
    else{
        current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newnode;
    }
}

void insatpos(){
    node* newnode;
    newnode = (node*)malloc(sizeof(node));
    int data, pos;
    printf("\nEnter the data to be added: ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = NULL;
    printf("\nEnter the position to insert the data: ");
    scanf("%d", &pos);
    if(head==NULL){
        head = newnode;
    }
    else if(pos == 1){                             /* if entering in position of head */ 
        newnode->next = head;
        head = newnode;
    }
    else{
        current = head;
        for(int i=2; i<pos; i++){                    /* i = 2 since current = head and next node is second position  */ 
            if(current->next == NULL){                     /* i<pos => 2<2 so current still at head and next node is 2nd */ 
                break;
            }
            current = current->next;
        }
        if(current->next == NULL){
            current->next = newnode;
        }
        else{
            newnode->next = current->next;
            current->next = newnode;
        }
    }
}

void display(){
    if(head == NULL){
        printf("\n!!There are no nodes to display!!\n");
    }
    else{
        current = head;
        while(current!=NULL){
            printf("%d ", current->data);
            current = current->next;
        }
    }
}

void delete(){
    if(head == NULL){
        printf("\n!!There are no nodes to delete!!\n");
    }
    else{
        int pos;
        current = head;
        printf("\nEnter the position: ");
        scanf("%d", &pos);
        if(pos == 1){
            head = head->next;
            free(current);
        }
        else{
            for(int i=2; i<pos; i++){
                if(current->next == NULL){
                    break;
                }
                current = current->next;
            }
            if(current->next == NULL){
                printf("\n!!There was no node to delete at the position!!\n");
            }
            else{
                node *temp;                          /* temp used to free unused space */ 
                temp = current->next;
                current->next = current->next->next;
                free(temp);
            }
            
        }
    }
}