#include <stdio.h>

#define MAX 10

int deque[MAX];
int front = -1;
int rear = -1;

void push_front(int val)
{
    if(front == 0)
        printf("Overflow\n");

    else if(front == -1)
    {
        front = rear = 0;
        deque[front] = val;
    }

    else
    {
        front--;
        deque[front] = val;
    }
}

void push_back(int val)
{
    if(rear == MAX-1)
        printf("Overflow\n");

    else if(front == -1)
    {
        front = rear = 0;
        deque[rear] = val;
    }

    else
    {
        rear++;
        deque[rear] = val;
    }
}

void pop_front()
{
    if(front == -1)
        printf("Underflow\n");

    else
    {
        printf("Deleted: %d\n", deque[front]);
        front++;

        if(front > rear)
            front = rear = -1;
    }
}

void pop_back()
{
    if(rear == -1)
        printf("Underflow\n");

    else
    {
        printf("Deleted: %d\n", deque[rear]);
        rear--;

        if(front > rear)
            front = rear = -1;
    }
}

void display()
{
    if(front == -1)
        printf("Deque is empty\n");

    else
    {
        for(int i = front; i <= rear; i++)
            printf("%d ", deque[i]);
        printf("\n");
    }
}

int main()
{
    push_back(10);
    push_back(20);
    push_front(5);

    display();

    pop_front();
    pop_back();

    display();

    return 0;
}