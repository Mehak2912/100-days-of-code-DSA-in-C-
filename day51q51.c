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
struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return createNode(val);
    
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    
    return root;
}
struct Node* findLCA(struct Node* root, int p, int q) {
    if (root == NULL)
        return NULL;
    if (p < root->val && q < root->val)
        return findLCA(root->left, p, q);
    if (p > root->val && q > root->val)
        return findLCA(root->right, p, q);
    return root;
}
int main() {
    int n, i, val, p, q;
    struct Node* root = NULL;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    scanf("%d %d", &p, &q);
    struct Node* lca = findLCA(root, p, q);
    if (lca != NULL)
        printf("%d\n", lca->val);
    return 0;
}
