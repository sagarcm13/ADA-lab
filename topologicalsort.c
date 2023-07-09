#include <stdio.h>
#define size 100
int visited[size];
int graph[size][size];
int n;
int stack[size];
int top = -1;

void initialize() {
    int i, j;
    for (i = 0; i < size; i++) {
        visited[i] = 0;
        for (j = 0; j < size; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int src, int dest) {
    graph[src][dest] = 1;
}

void DFS(int vertex) {
    int i;
    visited[vertex] = 1;    
    for (i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }    
    stack[++top] = vertex;
}

void topologicalSort() {
    int i;
    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            DFS(i);
        }
    }
    printf("Topological order: ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}
void main() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    initialize();
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    topologicalSort();
}
