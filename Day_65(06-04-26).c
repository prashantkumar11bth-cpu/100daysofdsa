#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];
int adj[MAX][MAX];
int n;

int dfs(int v, int parent)
{
    visited[v] = 1;

    for(int i = 0; i < n; i++)
    {
        if(adj[v][i])
        {
            if(!visited[i])
            {
                if(dfs(i, v))
                    return 1;
            }
            else if(i != parent)
            {
                return 1; // cycle detected
            }
        }
    }
    return 0;
}

int hasCycle()
{
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            if(dfs(i, -1))
                return 1;
        }
    }
    return 0;
}

int main()
{
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for(int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    if(hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}