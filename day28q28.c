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

// Create circular linked list
struct Node* createCircularList(int n) {
    if (n <= 0) return NULL;

    int x;
    struct Node *head = NULL, *temp = NULL, *last = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        temp = createNode(x);

        if (head == NULL) {
            head = temp;
            last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
    }

    // Make it circular
    last->next = head;

    return head;
}

// Traverse circular linked list
void traverseCircularList(struct Node* head) {
    if (head == NULL)
        return;

    struct Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int n;
    struct Node* head = NULL;

    scanf("%d", &n);

    head = createCircularList(n);

    traverseCircularList(head);

    return 0;
}
