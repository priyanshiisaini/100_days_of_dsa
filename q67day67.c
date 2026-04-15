#include <stdio.h>
#include <stdlib.h>

void dfs(int node, int V, int adj[V][V], int visited[], int stack[], int *top) {
    visited[node] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i, V, adj, visited, stack, top);
        }
    }

    stack[(*top)++] = node;  // push after visiting all neighbors
}

void topoSort(int V, int adj[V][V]) {
    int visited[V];
    int stack[V];
    int top = 0;

    // initialize visited
    for (int i = 0; i < V; i++)
        visited[i] = 0;

    // call DFS for all nodes
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, V, adj, visited, stack, &top);
        }
    }

    // print in reverse order
    printf("Topological Order: ");
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main() {
    int V = 6;

    int adj[6][6] = {
        {0, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };

    topoSort(V, adj);

    return 0;
}