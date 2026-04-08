#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int v)
{
    stack[++top] = v;
}

void DFS(int v, int visited[], int graph[MAX][MAX], int V)
{
    visited[v] = 1;

    for(int i = 0; i < V; i++)
    {
        if(graph[v][i] == 1 && !visited[i])
        {
            DFS(i, visited, graph, V);
        }
    }

    push(v);  // push after visiting all neighbours
}

void topologicalSort(int graph[MAX][MAX], int V)
{
    int visited[MAX] = {0};

    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            DFS(i, visited, graph, V);
        }
    }

    printf("Topological Order:\n");

    while(top != -1)
    {
        printf("%d ", stack[top--]);
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