#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void zigzag(struct node* root)
{
    if(root == NULL)
        return;

    struct node* s1[100];
    struct node* s2[100];

    int top1 = -1, top2 = -1;

    s1[++top1] = root;

    while(top1 != -1 || top2 != -1)
    {
        while(top1 != -1)
        {
            struct node* temp = s1[top1--];
            printf("%d ", temp->data);

            if(temp->left)
                s2[++top2] = temp->left;

            if(temp->right)
                s2[++top2] = temp->right;
        }

        while(top2 != -1)
        {
            struct node* temp = s2[top2--];
            printf("%d ", temp->data);

            if(temp->right)
                s1[++top1] = temp->right;

            if(temp->left)
                s1[++top1] = temp->left;
        }
    }
}

int main()
{
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    zigzag(root);

    return 0;
}