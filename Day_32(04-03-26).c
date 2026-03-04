#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = x;
}

void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

int main()
{
    int n, m, x;

    // number of elements to push
    scanf("%d", &n);

    // pushing elements
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        push(x);
    }

    // number of pops
    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        pop();
    }

    // print remaining stack from top to bottom
    while(top != -1)
    {
        printf("%d ", stack[top]);
        top--;
    }

    return 0;
}