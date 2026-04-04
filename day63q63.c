#include <stdio.h>
#include <stdbool.h>
#define MAX 100
void dfs(int node, int adj[MAX][MAX], bool visited[], int n) {
    visited[node] = true;
    printf("%d ", node);

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i, adj, visited, n);
        }
    }
}
int main() {
    int n, s;
    int adj[MAX][MAX];
    bool visited[MAX] = {false};
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter starting vertex: ");
    scanf("%d", &s);
    printf("DFS Traversal: ");
    dfs(s, adj, visited, n);
    return 0;
}
