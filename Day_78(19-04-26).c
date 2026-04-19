#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAXN 1005

typedef struct Edge {
    int to;
    int weight;
    struct Edge* next;
} Edge;

Edge* adj[MAXN];
bool visited[MAXN];

typedef struct {
    int node;
    int weight;
} HeapNode;

HeapNode heap[MAXN * MAXN];
int heapSize = 0;

void push(int node, int weight) {
    heap[++heapSize].node = node;
    heap[heapSize].weight = weight;

    int i = heapSize;
    while(i > 1 && heap[i].weight < heap[i/2].weight) {
        HeapNode temp = heap[i];
        heap[i] = heap[i/2];
        heap[i/2] = temp;
        i /= 2;
    }
}

HeapNode pop() {
    HeapNode top = heap[1];
    heap[1] = heap[heapSize--];

    int i = 1;
    while(1) {
        int left = 2*i;
        int right = 2*i+1;
        int smallest = i;

        if(left <= heapSize && heap[left].weight < heap[smallest].weight)
            smallest = left;

        if(right <= heapSize && heap[right].weight < heap[smallest].weight)
            smallest = right;

        if(smallest != i) {
            HeapNode temp = heap[i];
            heap[i] = heap[smallest];
            heap[smallest] = temp;
            i = smallest;
        } else break;
    }

    return top;
}

void addEdge(int u, int v, int w) {
    Edge* e1 = (Edge*)malloc(sizeof(Edge));
    e1->to = v;
    e1->weight = w;
    e1->next = adj[u];
    adj[u] = e1;

    Edge* e2 = (Edge*)malloc(sizeof(Edge));
    e2->to = u;
    e2->weight = w;
    e2->next = adj[v];
    adj[v] = e2;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        addEdge(u,v,w);
    }

    push(1,0);

    int total = 0;

    while(heapSize > 0){
        HeapNode cur = pop();
        int node = cur.node;
        int weight = cur.weight;

        if(visited[node]) continue;

        visited[node] = true;
        total += weight;

        Edge* temp = adj[node];
        while(temp){
            if(!visited[temp->to]){
                push(temp->to,temp->weight);
            }
            temp = temp->next;
        }
    }

    printf("%d\n",total);
    return 0;
}