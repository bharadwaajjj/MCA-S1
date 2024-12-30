#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
int adj[20][20], n, vertex, visited[20], mst[20][20], cost = 0;
// defining edge
struct Edge
{
    int u;
    int v;
    int cost;
};
void prims(int start);
void main()
{

    printf("\nEnter the number of nodes:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    printf("\nEnter the adjacency matrix:");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("\nA[%d][%d]:", i, j);
            scanf("%d", &adj[i][j]);
        }
    }
    // Reading the arbiraty vertex from which the mst should start
    printf("\nEnter the starting vertex:");
    scanf("%d", &vertex);
    prims(vertex);
    printf("\nMST Nodes and Edges\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mst[i][j] != 0)
            {
                printf("\n%d-%d->Cost=%d", i, j, mst[i][j]);
            }
        }
    }
    printf("\nMinimum cost=%d",cost);
}
void prims(int start)
{
    int visitedVertexCount = 0;
    struct Edge *minEdge = (struct Edge *)malloc(sizeof(struct Edge));
    minEdge->cost = INT_MAX;
    // marking as visited
    visited[start] = 1;
    visitedVertexCount++;
    while (visitedVertexCount < n) // algoirthm should terminate when all vertices are added
    {
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 1)
            {

                for (int j = 0; j < n; j++)
                {
                    // finding the minimum edge between 2 vertices (i,j) such that i is visited, j is not visited
                    if (adj[i][j] != 0 && visited[j] == 0 && adj[i][j] < minEdge->cost)
                    {
                        minEdge->u = i;
                        minEdge->v = j;
                        minEdge->cost = adj[i][j];
                    }
                }
            }
        }
        visited[minEdge->v] = 1;
        cost += minEdge->cost;
        visitedVertexCount++;
        mst[minEdge->u][minEdge->v] = minEdge->cost;
        minEdge->cost = INT_MAX;
    }
}