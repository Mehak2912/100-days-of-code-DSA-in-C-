#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX], top = -1;
int visited[MAX];
void push(int node) {
    stack[++top] = node;
}
void dfs(int node, int V, int adj[MAX][MAX]) {
    visited[node] = 1;
    for (int i = 0; i < V; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i, V, adj);
        }
    }
    push(node);
}
void topoSort(int V, int adj[MAX][MAX]) {
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, V, adj);
        }
    }
    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}
int main() {
    int V = 6;
    int adj[MAX][MAX] = {0};
    adj[5][0] = 1;
    adj[5][2] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;
    topoSort(V, adj);
    return 0;
}
