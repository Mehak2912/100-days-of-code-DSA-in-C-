#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Find intersection node using two pointer technique
struct Node* getIntersectionNode(struct Node* headA, struct Node* headB) {
    if (!headA || !headB)
        return NULL;

    struct Node* p1 = headA;
    struct Node* p2 = headB;

    while (p1 != p2) {
        p1 = (p1 == NULL) ? headB : p1->next;
        p2 = (p2 == NULL) ? headA : p2->next;
    }

    return p1;
}

int main() {
    int n, m, i, x;
    struct Node *head1 = NULL, *head2 = NULL;

    // First list
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        head1 = insertEnd(head1, x);
    }

    // Second list
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &x);
        head2 = insertEnd(head2, x);
    }

    if (head1 && head1->next && head2) {
        struct Node* temp = head2;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = head1->next;  
    }

    struct Node* intersection = getIntersectionNode(head1, head2);

    if (intersection)
        printf("%d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}
