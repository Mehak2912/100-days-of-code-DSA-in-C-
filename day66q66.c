#include <stdio.h>
#include <stdbool.h>
#define MAX 100
bool dfs(int node, int V, int adj[MAX][MAX], bool visited[], bool recStack[]) {
    visited[node] = true;
    recStack[node] = true;
    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, V, adj, visited, recStack))
                    return true;
            }
            else if (recStack[i]) {
                return true;
            }
        }
    }
    recStack[node] = false;
    return false;
}
char* isCyclic(int V, int adj[MAX][MAX]) {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, V, adj, visited, recStack))
                return "YES";
        }
    }
    return "NO";
}
int main() {
    int V = 4;
    int adj[MAX][MAX] = {0};
    adj[0][1] = 1;
    adj[1][2] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;  // cycle
    printf("%s\n", isCyclic(V, adj));
    return 0;
}
