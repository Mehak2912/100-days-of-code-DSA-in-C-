#include <stdio.h>
#include <limits.h>
#define MAX 100
typedef struct {
    int node;
    int dist;
} HeapNode;
HeapNode heap[MAX];
int size = 0;
void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}
void heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent].dist > heap[index].dist) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else break;
    }
}
void heapifyDown(int index) {
    int left, right, smallest;
    while (1) {
        left = 2 * index + 1;
        right = 2 * index + 2;
        smallest = index;
        if (left < size && heap[left].dist < heap[smallest].dist)
            smallest = left;
        if (right < size && heap[right].dist < heap[smallest].dist)
            smallest = right;
        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else break;
    }
}
void push(int node, int dist) {
    heap[size].node = node;
    heap[size].dist = dist;
    heapifyUp(size);
    size++;
}
HeapNode pop() {
    HeapNode root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return root;
}
int isEmpty() {
    return size == 0;
}
void dijkstra(int V, int adj[MAX][MAX], int src) {
    int dist[MAX];
    int visited[MAX] = {0};
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    push(src, 0);
    while (!isEmpty()) {
        HeapNode top = pop();
        int u = top.node;
        if (visited[u]) continue;
        visited[u] = 1;
        for (int v = 0; v < V; v++) {
            if (adj[u][v] != 0 && !visited[v]) {
                int newDist = dist[u] + adj[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    push(v, newDist);
                }
            }
        }
    }
    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < V; i++) {
        printf("Node %d -> %d\n", i, dist[i]);
    }
}
int main() {
    int V = 5;
    int adj[MAX][MAX] = {0};
    adj[0][1] = 2;
    adj[0][2] = 4;
    adj[1][2] = 1;
    adj[1][3] = 7;
    adj[2][4] = 3;
    adj[3][4] = 1;
    int src = 0;
    dijkstra(V, adj, src);
    return 0;
}
