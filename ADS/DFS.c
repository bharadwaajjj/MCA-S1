#include<stdio.h>
#include<stdlib.h>

void dfs(int node);

int visited[20],i,adj[20][20],j,n,start;
int vertex[20];

int main(){
    printf("Enter the number of nodes :");
    scanf("%d",&n);
    for (i=0; i<n; i++) {
        printf("Enter the vertices: ");
        scanf("%d", &vertex[i]);
    }
    int flag, weight;
    for(i=0;i<n;i++){
        for(j=i;j<n;j++)
        {
            adj[i][j] = 0;
            adj[j][i] = 0;
            printf("Do you want edges between vertice %d & %d \n1. Yes 2. No \n", vertex[i], vertex[j]);
            scanf("%d", &flag);
            if (flag==1) {
                printf("Enter the weight/cost: ");
                scanf("%d", &weight);
                adj[i][j] = weight;
                adj[j][i] = weight;
            }
        }
    }


    printf("The adjacency matrix: \n");
    for(i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }
    printf("Enter the node to start BFS with :");
    scanf("%d",&start);
    for (i=0; i<n; i++) {
        if (start == vertex[i]) {
            dfs(i);
            break;
        }
    }
    return 0;
}

void dfs(int node)
{
    int j;
    visited[node] = 1;
    printf("%d\t",vertex[node]);
    for(j=0;j<n;j++)
    {
        if(adj[node][j] == 1 && visited[j] == 0)
        {
            dfs(j);
        }
    }
}