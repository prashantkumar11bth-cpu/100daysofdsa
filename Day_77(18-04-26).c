#include <stdio.h>

int visited[1000];
int adj[1000][1000];
int n, m;

void dfs(int node)
{
    visited[node] = 1;

    for(int i = 1; i <= n; i++)
    {
        if(adj[node][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{
    int u, v;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected graph
    }

    dfs(1);

    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == 0)
        {
            printf("NOT CONNECTED");
            return 0;
        }
    }

    printf("CONNECTED");

    return 0;
}