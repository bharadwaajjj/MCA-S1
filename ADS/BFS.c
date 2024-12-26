#include<stdio.h>

int n , adj[20][20] , start , i ,j ,visited[20] ,queue[20],front=-1, rear=-1;

void bfs(int start);
void enqueue(int node);
int dequeue();

int main()
{
    printf("\nEnter the number of nodes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("A[%d][%d]:",i,j);
            scanf("%d",&adj[i][j]);
        }
    }

    printf("Enter the starting node :");
    scanf("%d",&start);

    if(start < 0 || start > n-1)
    {
        printf("\nInvalid Starting Node !!");
    }
    else
    {
        printf("\nBFS Visited Order :\n");
        bfs(start);
    }

    return 0;
}

void bfs(int start)
{
    enqueue(start);
    visited[start]=1;
    printf("%d\t",start);
    while(front!=-1 && rear!=-1)
    {
        int node = dequeue();
        for(i=0;i<n;i++)
        {
            if(adj[node][i]==1 && visited[i]!=1)
            {
                visited[i]=1;
                printf("%d\t",i);
                enqueue(i);
            }
        }
    }
}

void enqueue(int node)
{
    if(front ==-1 && rear ==-1)
    {
        rear=0;
        front=0;

    }
    else{
        rear++;
    }
    queue[rear]=node;
}

int dequeue()
{
    int node = queue[front];
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else{
        front++;
    }
    return node;
}