#include <stdio.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;
int visited[MAX];

void enqueue(int x)
{
    if(rear == MAX - 1)
        return;
    if(front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue()
{
    if(front == -1 || front > rear)
        return -1;
    return queue[front++];
}

int isEmpty()
{
    if(front == -1 || front > rear)
        return 1;
    return 0;
}

void BFS(int adj[MAX][MAX], int n, int s)
{
    enqueue(s);
    visited[s] = 1;

    while(!isEmpty())
    {
        int v = dequeue();
        printf("%d ", v);

        for(int i = 0; i < n; i++)
        {
            if(adj[v][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int n, s;
    int adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &s);

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    printf("BFS Traversal: ");
    BFS(adj, n, s);

    return 0;
}