#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int queue[MAX], front = -1, rear = -1;
void enqueue(int x) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}
int dequeue() {
    if (front == -1)
        return -1;
    int x = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return x;
}
int isEmpty() {
    return front == -1;
}
void topologicalSort(int V, int adj[MAX][MAX]) {
    int in_degree[MAX] = {0};
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1)
                in_degree[j]++;
        }
    }
    for (int i = 0; i < V; i++) {
        if (in_degree[i] == 0)
            enqueue(i);
    }
    int count = 0;
    int topo[MAX];
    while (!isEmpty()) {
        int node = dequeue();
        topo[count++] = node;
        for (int j = 0; j < V; j++) {
            if (adj[node][j] == 1) {
                in_degree[j]--;
                if (in_degree[j] == 0)
                    enqueue(j);
            }
        }
    }
    if (count != V) {
        printf("Cycle detected! No topological ordering.\n");
        return;
    }
    printf("Topological Order: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", topo[i]);
    }
    printf("\n");
}
int main() {
    int V = 6;
    int adj[MAX][MAX] = {0};
    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;
    topologicalSort(V, adj);
    return 0;
}
