#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
struct Node* rotateRight(struct Node* head, int k) {
    if (!head || k == 0)
        return head;

    struct Node* temp = head;
    int length = 1;
    while (temp->next) {
        temp = temp->next;
        length++;
    }
    temp->next = head;
    k = k % length;
    int stepsToNewHead = length - k;
    struct Node* newTail = head;
    for (int i = 1; i < stepsToNewHead; i++)
        newTail = newTail->next;

    struct Node* newHead = newTail->next;
    newTail->next = NULL;  // Break circle
    return newHead;
}
void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}
int main() {
    int n, k, val;
    scanf("%d", &n);
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);

        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    scanf("%d", &k);
    head = rotateRight(head, k);
    printList(head);
    return 0;
}
