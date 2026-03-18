#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Queue Node
struct QueueNode {
    struct TreeNode* treeNode;
    struct QueueNode* next;
};

// Queue
struct Queue {
    struct QueueNode *front, *rear;
};

// Create Queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue
void enqueue(struct Queue* q, struct TreeNode* node) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->treeNode = node;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Dequeue
struct TreeNode* dequeue(struct Queue* q) {
    if (q->front == NULL) return NULL;

    struct QueueNode* temp = q->front;
    struct TreeNode* node = temp->treeNode;

    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return node;
}

// Check empty
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Level Order Traversal
void levelOrder(struct TreeNode* root) {
    if (root == NULL) return;

    struct Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        int size = 0;

        // Count current level size
        struct QueueNode* temp = q->front;
        while (temp) {
            size++;
            temp = temp->next;
        }

        // Process one level
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = dequeue(q);
            printf("%d ", node->val);

            if (node->left)
                enqueue(q, node->left);
            if (node->right)
                enqueue(q, node->right);
        }
        printf("\n"); // new level
    }
}