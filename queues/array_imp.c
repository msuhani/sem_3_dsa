#include <stdio.h>

#define MAXLEN 100
typedef struct
{
    int element[MAXLEN];
    int front, rear;
} queue;
queue init() // initializing;
{
    queue Q;
    Q.front = Q.rear = -1;
    return Q;
}
int size(queue Q)
{
    return (Q.rear - Q.front + 1);
}
isEmpty(queue Q) { 
    return ((Q.front == -1) || (Q.front > Q.rear)); 
}
int isFull(queue Q)
{
    return (Q.rear == MAXLEN - 1);
}
int front(queue Q)
{
    if (isEmpty(Q))
        printf("Empty queue\n");
    else
        return Q.element[Q.front];
}
queue enqueue(queue Q, int x)
{
    if (isFull(Q))
        printf("OVERFLOW\n");
    else if (isEmpty(Q))
    {
        Q.front = Q.rear = 0;
        Q.element[Q.rear] = x;
    }
    else
    {
        ++Q.rear;
        Q.element[Q.rear] = x;
    }
    return Q;
}
queue dequeue(queue Q)
{
    if (isEmpty(Q))
        printf("UNDERFLOW\n");
    else
        Q.front++;
    return Q;
}
void print(queue Q)
{
    int i;
    for (i = Q.front; i <= Q.rear; i++)
        printf("%d ", Q.element[i]);
}
int main()
{
    queue Q;
    Q = init();
    Q = enqueue(Q, 5);
    Q = enqueue(Q, 3);
    Q = dequeue(Q);
    Q = enqueue(Q, 7);
    Q = dequeue(Q);
    printf("Current queue : ");
    print(Q);
    printf(" with front = %d.\n", front(Q));
    Q = enqueue(Q, 9);
    Q = enqueue(Q, 3);
    Q = enqueue(Q, 1);
    printf("Current queue : ");
    print(Q);
    printf(" with front = %d.\n", front(Q));
    printf("Size is %d.", size(Q));
    return 0;
}