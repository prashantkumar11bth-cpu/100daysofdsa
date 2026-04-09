#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x)
{
    if(front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue()
{
    return queue[front++];
}

int isEmpty()
{
    if(front > rear)
        return 1;
    return 0;
}

void topologicalSort(int graph[MAX][MAX], int V)
{
    int indegree[MAX] = {0};

    // Calculate indegree
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            if(graph[i][j] == 1)
                indegree[j]++;
        }
    }

    // Insert vertices with indegree 0 into queue
    for(int i = 0; i < V; i++)
    {
        if(indegree[i] == 0)
            enqueue(i);
    }

    printf("Topological Order:\n");

    while(!isEmpty())
    {
        int u = dequeue();
        printf("%d ", u);

        for(int v = 0; v < V; v++)
        {
            if(graph[u][v] == 1)
            {
                indegree[v]--;
                if(indegree[v] == 0)
                    enqueue(v);
            }
        }
    }
}

int main()
{
    int V, E;
    int graph[MAX][MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (u v):\n");
    for(int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    topologicalSort(graph, V);

    return 0;
}