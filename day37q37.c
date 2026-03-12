#include <stdio.h>
#include <string.h>
#define MAX 100
int pq[MAX];
int size = 0;
void insert(int x)
{
    if(size < MAX)
    {
        pq[size] = x;
        size++;
    }
}
void deletePQ()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }
    int minIndex = 0;
    for(int i = 1; i < size; i++)
    {
        if(pq[i] < pq[minIndex])
        {
            minIndex = i;
        }
    }
    printf("%d\n", pq[minIndex]);
    for(int i = minIndex; i < size - 1; i++)
    {
        pq[i] = pq[i + 1];
    }
    size--;
}
void peek()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }
    int min = pq[0];
    for(int i = 1; i < size; i++)
    {
        if(pq[i] < min)
        {
            min = pq[i];
        }
    }
    printf("%d\n", min);
}
int main()
{
    int N;
    scanf("%d", &N);
    char op[10];
    int x;
    for(int i = 0; i < N; i++)
    {
        scanf("%s", op);
        if(strcmp(op, "insert") == 0)
        {
            scanf("%d", &x);
            insert(x);
        }
        else if(strcmp(op, "delete") == 0)
        {
            deletePQ();
        }
        else if(strcmp(op, "peek") == 0)
        {
            peek();
        }
    }
    return 0;
}
