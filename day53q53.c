#include <stdio.h>
#include <stdlib.h>
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};
struct QNode {
    struct Node* node;
    int hd;
};
struct Node* createNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = createNode(arr[0]);
    struct Node* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    while (i < n) {
        struct Node* curr = queue[front++];
        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}
struct Pair {
    int hd;
    int val;
};
int cmp(const void* a, const void* b) {
    struct Pair* p1 = (struct Pair*)a;
    struct Pair* p2 = (struct Pair*)b;
    if (p1->hd == p2->hd)
        return 0;
    return p1->hd - p2->hd;
}
void verticalOrder(struct Node* root, int n) {
    if (root == NULL) return;
    struct QNode queue[n];
    int front = 0, rear = 0;
    struct Pair result[n];
    int k = 0;
    queue[rear++] = (struct QNode){root, 0};
    while (front < rear) {
        struct QNode temp = queue[front++];
        struct Node* node = temp.node;
        int hd = temp.hd;
        result[k++] = (struct Pair){hd, node->val};
        if (node->left)
            queue[rear++] = (struct QNode){node->left, hd - 1};
        if (node->right)
            queue[rear++] = (struct QNode){node->right, hd + 1};
    }
    qsort(result, k, sizeof(struct Pair), cmp);
    int prev_hd = result[0].hd;
    for (int i = 0; i < k; i++) {
        if (result[i].hd != prev_hd) {
            printf("\n");
            prev_hd = result[i].hd;
        }
        printf("%d ", result[i].val);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, n);
    verticalOrder(root, n);
    return 0;
}
