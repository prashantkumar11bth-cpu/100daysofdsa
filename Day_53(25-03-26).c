#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Queue Node
struct QNode
{
    struct Node *node;
    int hd;
};

// Create new tree node
struct Node* createNode(int data)
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Vertical Order Traversal
void verticalTraversal(struct Node* root)
{
    if(root == NULL) return;

    struct QNode queue[100];
    int front = 0, rear = 0;

    int map[200][100];   // storing nodes
    int count[200] = {0};
    int offset = 100;

    queue[rear++] = (struct QNode){root,0};

    while(front < rear)
    {
        struct QNode temp = queue[front++];
        struct Node* node = temp.node;
        int hd = temp.hd + offset;

        map[hd][count[hd]++] = node->data;

        if(node->left)
            queue[rear++] = (struct QNode){node->left, temp.hd - 1};

        if(node->right)
            queue[rear++] = (struct QNode){node->right, temp.hd + 1};
    }

    for(int i=0;i<200;i++)
    {
        if(count[i] > 0)
        {
            for(int j=0;j<count[i];j++)
                printf("%d ", map[i][j]);
            printf("\n");
        }
    }
}

int main()
{
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    verticalTraversal(root);

    return 0;
}