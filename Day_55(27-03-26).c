#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void rightView(struct TreeNode* root) {
    if (root == NULL) return;

    struct TreeNode* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int size = rear - front;

        for (int i = 1; i <= size; i++) {
            struct TreeNode* temp = queue[front++];

            if (i == size) {
                printf("%d ", temp->data);
            }

            if (temp->left)
                queue[rear++] = temp->left;

            if (temp->right)
                queue[rear++] = temp->right;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    struct TreeNode* nodes[n];

    for(int i=0;i<n;i++){
        if(arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = newNode(arr[i]);
    }

    for(int i=0;i<n;i++){
        if(nodes[i] != NULL){
            int left = 2*i+1;
            int right = 2*i+2;

            if(left<n)
                nodes[i]->left = nodes[left];
            if(right<n)
                nodes[i]->right = nodes[right];
        }
    }

    rightView(nodes[0]);

    return 0;
}