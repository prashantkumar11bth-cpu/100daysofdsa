#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    
    temp->data = x;
    temp->next = NULL;

    if(front == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

void dequeue()
{
    if(front == NULL)
    {
        printf("-1\n");
        return;
    }

    struct node *temp = front;
    printf("%d\n", front->data);

    front = front->next;
    free(temp);

    if(front == NULL)
        rear = NULL;
}

int main()
{
    int n, x;
    char op;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf(" %c", &op);

        if(op == 'E')      // Enqueue
        {
            scanf("%d", &x);
            enqueue(x);
        }
        else if(op == 'D') // Dequeue
        {
            dequeue();
        }
    }

    return 0;
}
