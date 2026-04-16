#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void topologicalSort(int graph[MAX][MAX], int n) {
    int indegree[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    // Step 1: Calculate in-degree
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Step 2: Push all nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Step 3: BFS
    int count = 0;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1) {
                indegree[i]--;

                if (indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    // Step 4: Cycle check
    if (count != n) {
        printf("\nGraph has a cycle, topological sort not possible\n");
    }
}

int main() {
    int n = 6;

    int graph[MAX][MAX] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };

    printf("Topological Order: ");
    topologicalSort(graph, n);

    return 0;
}