#include <stdio.h>
#define MAX 5
int deque[MAX];
int front = -1;
int rear = -1;
void push_front(int x)
{
    if((front == 0 && rear == MAX-1) || (front == rear+1))
    {
        printf("Deque Overflow\n");
        return;
    }
    if(front == -1)
    {
        front = rear = 0;
    }
    else if(front == 0)
    {
        front = MAX - 1;
    }
    else
    {
        front--;
    }
    deque[front] = x;
}
void push_back(int x)
{
    if((front == 0 && rear == MAX-1) || (front == rear+1))
    {
        printf("Deque Overflow\n");
        return;
    }
    if(front == -1)
    {
        front = rear = 0;
    }
    else if(rear == MAX-1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    deque[rear] = x;
}
void pop_front()
{
    if(front == -1)
    {
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted element: %d\n", deque[front]);
    if(front == rear)
    {
        front = rear = -1;
    }
    else if(front == MAX-1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}
void pop_back()
{
    if(front == -1)
    {
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted element: %d\n", deque[rear]);
    if(front == rear)
    {
        front = rear = -1;
    }
    else if(rear == 0)
    {
        rear = MAX-1;
    }
    else
    {
        rear--;
    }
}
void display()
{
    if(front == -1)
    {
        printf("Deque is empty\n");
        return;
    }
    int i = front;
    printf("Deque elements: ");
    while(1)
    {
        printf("%d ", deque[i]);
        if(i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main()
{
    int choice, x;
    while(1)
    {
        printf("\n1.Push Front\n");
        printf("2.Push Back\n");
        printf("3.Pop Front\n");
        printf("4.Pop Back\n");
        printf("5.Display\n");
        printf("6.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&x);
                push_front(x);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d",&x);
                push_back(x);
                break;
            case 3:
                pop_front();
                break;
            case 4:
                pop_back();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
