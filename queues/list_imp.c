#include <stdio.h>
struct node
{
    int data;
    struct node *next, *prev;
} *front, *rear;
void init()//initializing;
{
    front = rear = NULL;
}
void enqueue(int num)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    if (front == NULL)
    {
        temp->prev = temp;
        temp->next = temp;
        front = rear = temp;
    }
    else
    {
        temp->prev = rear;
        rear->next = temp;
        temp->next = front;
        front->prev = temp;
        rear = temp;
    }
}
void dequeue()
{
    if (front == NULL)
        printf("\nQueue is empty.\n");
    else
    {
        struct node *temp = front;
        if (front == rear)
            front = rear = NULL;
        else
        {
            rear->next = front->next;
            front = front->next;
            front->prev = rear;
        }
        free(temp);
    }
}
void print()
{
    printf("\nfront --> ");
    if (front != NULL)
    {
        struct node *temp = front;
        while (temp != rear)
        {
            printf("%d --> ", temp->data);
            temp = temp->next;
        }
        printf("%d --> ", temp->data);
    }
    printf("rear\n");
}
int main()
{
    init();
    enqueue(5);
    enqueue(3);
    dequeue();
    enqueue(7);
    dequeue();
    printf("Current queue : ");
    print();
    enqueue(9);
    enqueue(3);
    enqueue(1);
    printf("Current queue : ");
    print();
    return 0;
}