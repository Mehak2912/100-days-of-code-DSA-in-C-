#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};
struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}
void printPolynomial(struct Node* head) {
    while (head != NULL) {
        if (head->exp > 1)
            printf("%dx^%d", head->coeff, head->exp);
        else if (head->exp == 1)
            printf("%dx", head->coeff);
        else
            printf("%d", head->coeff);
        if (head->next != NULL)
            printf(" + ");
        head = head->next;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        int c, e;
        scanf("%d %d", &c, &e);
        struct Node* newNode = createNode(c, e);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    printPolynomial(head);
    return 0;
}
