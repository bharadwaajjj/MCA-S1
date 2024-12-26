#include<stdio.h>
#include<stdlib.h>

int adj[20][20], stack[20], top = -1, n, i, j, start, visited[20];

void dfs(int start);

int main()
{
    printf("\nEnter number of nodes: ");
    scanf("%d", &n);

    // Initialize visited array to 0
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Reading graph from adjacency matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("\nA[%d][%d]: ", i, j);
            scanf("%d", &adj[i][j]);
        }
    }

    printf("\nEnter starting Node: ");
    scanf("%d", &start);

    // Validate starting node
    if (start < 0 || start >= n) {
        printf("Invalid starting node!\n");
        return 1;
    }

    printf("\nDFS Visited Order:\n");
    dfs(start);

    return 0;
}

void dfs(int node)
{
    // Visiting the node
    visited[node] = 1;
    printf("%d ", node);

    for (i = 0; i < n; i++) {
        if (adj[node][i] == 1 && visited[i] != 1) {
            dfs(i);
        }
    }
}

/*-------Using Stack for DFS--------*/
/*
void dfs_iterative(int start)
{
    top = -1; // Initialize stack top
    stack[++top] = start; // Push starting node onto stack

    while (top != -1) { // While stack is not empty
        int node = stack[top--]; // Pop a node

        if (!visited[node]) {
            visited[node] = 1; // Mark the node as visited
            printf("%d ", node);

            // Push all unvisited neighbors onto the stack
            for (i = n - 1; i >= 0; i--) {
                if (adj[node][i] == 1 && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
}
*/