#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* search(struct Node* root, int key)
{
    if(root == NULL || root->data == key)
        return root;

    if(key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main()
{
    struct Node *root = NULL;
    
    // Example BST
    root = (struct Node*)malloc(sizeof(struct Node));
    root->data = 10;

    root->left = (struct Node*)malloc(sizeof(struct Node));
    root->left->data = 5;

    root->right = (struct Node*)malloc(sizeof(struct Node));
    root->right->data = 20;

    root->left->left = root->left->right = NULL;
    root->right->left = root->right->right = NULL;

    int key = 5;

    struct Node* result = search(root, key);

    if(result != NULL)
        printf("Element found: %d", result->data);
    else
        printf("Element not found");

    return 0;
}