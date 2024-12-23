// Importing Header Files
#include <stdio.h>
#include <stdlib.h>

// Initializing a Node for the LL
typedef struct Node
{
    int data;
    struct Node *Next;
} node;

// Declaring Queue Variables
node *front = NULL, *rear = NULL, *temp, *new;
int max, size; // Max Queue size and Present Queue Count

int ISFULL()
{
    int c = max;

    // Traversing Queue and Decrementing max to 0
    for (temp = front; temp != NULL; temp = temp->Next)
    {
        c--;
    }

    // If max reaches 0, Queue is Empty
    if (c == 0)
        return 1;
    else
        return 0;
}

int ISEMPTY()
{
    // If Front and rear is NUll; Queue is Empty
    return (front == NULL && rear == NULL) ? 1 : 0;
}

void EnQueue()
{
    // Condition for Full Queue
    if (ISFULL() == 1)
        printf("The Queue is Full!");

    else
    {
        // Memory Allocation and User input
        new = (node *)malloc(sizeof(node));
        printf("Enter your Queue data : ");
        scanf("%d", &new->data);
        new->Next = NULL;

        // Condition for Empty Queue
        if (ISEMPTY() == 1)
        {
            front = new;
            rear = new;
        }
        else
        {

            // Linkedlist Insert from bottom
            rear->Next = new;
            rear = new;
        }
        size++;
    }
}

void DeQueue()
{
    // Condition for Empty Queue
    if (ISEMPTY() == 1)
        printf("The Queue is Empty!");

    else
    {
        //Linkedlist Delete from top
        if (front == rear)
        {
            temp = front;
            front = NULL;
            rear = NULL;
        }

        else
        {
            temp = front;
            front = temp->Next;
        }
        size--;
        free(temp);
    }
}

void display()
{
    //Linkedlist traversal
    if (front == NULL)
    {
        printf("\n!!There are no nodes to display!!\n");
    }
    else
    {
        rear = front;
        while (rear != NULL)
        {
            printf("%d ", rear->data);
            rear = rear->Next;
        }
    }
}

void main()
{
    int choice;
    printf("Input MAX of YOur Queue : ");
    scanf("%d", &max);
    while (1)
    {
        printf("\nPlease Choose an Option\n0. Exit\n1. ENqueue\n2. DEqueue\n3. Display\t");
        scanf("%d", &choice);

        if (choice == 0)
        {
            break;
        }

        switch (choice)
        {
        case 1:
            EnQueue();
            break;
        case 2:
            DeQueue();
            break;
        case 3:
            display();
            break;
        default:
            printf("Instruction Unclear!");
            break;
        }
    }
}