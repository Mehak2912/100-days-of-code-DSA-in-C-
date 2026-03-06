#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* top = NULL;
void push(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}
int pop() {
    if(top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}
int main() {
    char postfix[100];
    int i = 0;
    printf("Enter postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);
    while(postfix[i] != '\0') {
        if(isdigit(postfix[i])) {
            push(postfix[i] - '0');
        }
        else if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/') {
            int val1 = pop();
            int val2 = pop();
            int result;
            switch(postfix[i]) {
                case '+': result = val2 + val1; break;
                case '-': result = val2 - val1; break;
                case '*': result = val2 * val1; break;
                case '/': result = val2 / val1; break;
            }
            push(result);
        }
        i++;
    }
    printf("Result = %d", pop());
    return 0;
}
