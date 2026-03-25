#include <stdio.h>
#include <stdlib.h>
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;
    struct Node* root = createNode(arr[0]);
    struct Node* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    while (i < n) {
        struct Node* current = queue[front++];
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }
    return root;
}
struct Node* findLCA(struct Node* root, int p, int q) {
    if (root == NULL)
        return NULL;
    if (root->val == p || root->val == q)
        return root;
    struct Node* left = findLCA(root->left, p, q);
    struct Node* right = findLCA(root->right, p, q);
    if (left != NULL && right != NULL)
        return root;
    return (left != NULL) ? left : right;
}
int main() {
    int n, i;
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int p, q;
    scanf("%d %d", &p, &q);
    struct Node* root = buildTree(arr, n);
    struct Node* lca = findLCA(root, p, q);
    if (lca != NULL)
        printf("%d\n", lca->val);
    return 0;
}
