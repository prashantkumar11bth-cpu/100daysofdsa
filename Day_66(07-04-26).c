#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int V;
int graph[MAX][MAX];
int visited[MAX];
int recStack[MAX];

int dfs(int node)
{
    visited[node] = 1;
    recStack[node] = 1;

    for(int i = 0; i < V; i++)
    {
        if(graph[node][i])
        {
            if(!visited[i] && dfs(i))
                return 1;
            else if(recStack[i])
                return 1;
        }
    }

    recStack[node] = 0;
    return 0;
}

int detectCycle()
{
    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            if(dfs(i))
                return 1;
        }
    }
    return 0;
}

int main()
{
    int E,u,v;

    printf("Enter vertices and edges: ");
    scanf("%d %d",&V,&E);

    for(int i=0;i<E;i++)
    {
        scanf("%d %d",&u,&v);
        graph[u][v] = 1;
    }

    if(detectCycle())
        printf("YES");
    else
        printf("NO");

    return 0;
}