#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int rank[20], parent[20], adj[20][20], mst[20][20], n, numEdges = 0;
int cost;
// Defining edge structure to get minimum edge repeatedly
// Each edge is described using it's vertices and the weight
struct Edge
{
    int u;
    int v;
    int cost;
};
void setUnion(int u, int v);
int find(int node);
struct Edge *getMinEdge();
void main()
{

    printf("\nEnter the total number of nodes:");
    scanf("%d", &n);
    // Reading the graph from adjacency matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("\nA[%d][%d]:", i, j);
            scanf("%d", &adj[i][j]);
            mst[i][j] = 0;
        }
    }
    // defining parent and rank matrix for disjoint set representation
    for (int i = 0; i < n; i++)
    {
        // parent of each vertex is that vertex itself
        parent[i] = i;
        // rank is initially 0 since each node has no child
        rank[i] = 0;
    }
    while (numEdges < n - 1) // MST will have exactly n-1 edges
    {

        struct Edge *minEdge;
        minEdge = getMinEdge();
        int u = minEdge->u;
        int v = minEdge->v;
        if (find(u) != find(v))
        // u and v are vertices that are not connected yet
        {
            // connecting u and v and adding to MST
            setUnion(u, v);
            mst[u][v] = minEdge->cost;
            numEdges++;
        }
    }
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
}
struct Edge *getMinEdge()
{
    // returns the next available edge with minimum weight
    struct Edge *edge = malloc(sizeof(struct Edge));
    int minWeight = INT_MAX, min1, min2, nodes[2], cost;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] != 0 && adj[i][j] < minWeight)
            // if there is an edge between 2 vertices and it's weight is less
            // than minweight
            {
                minWeight = adj[i][j];
                edge->u = i;
                edge->v = j;
                edge->cost = adj[i][j];
            }
        }
    }
    adj[edge->u][edge->v] = INT_MAX;
    return edge;
}
int find(int node)
{
    // disjoint set find
    if (parent[node] == node)
    {
        return node;
    }
    else
    {
        return find(parent[node]);
    }
}
void setUnion(int u, int v)
{
    // disjoint set union
    if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else
    {
        // if u and v have same rank, make v as the child of u and
        // increment the rank of u by 1
        parent[v] = u;
        rank[u] += 1;
    }
}