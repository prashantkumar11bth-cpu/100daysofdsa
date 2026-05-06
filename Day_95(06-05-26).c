#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float val;
    struct Node* next;
} Node;

Node* insertSorted(Node* head, float value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = NULL;

    if (head == NULL || head->val >= value) {
        newNode->next = head;
        return newNode;
    }

    Node* curr = head;
    while (curr->next != NULL && curr->next->val < value)
        curr = curr->next;

    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

void bucketSort(float arr[], int n) {
    Node** buckets = (Node**)malloc(n * sizeof(Node*));

    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    for (int i = 0; i < n; i++) {
        int index = (int)(arr[i] * n);
        buckets[index] = insertSorted(buckets[index], arr[i]);
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        Node* curr = buckets[i];
        while (curr != NULL) {
            arr[k++] = curr->val;
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }

    free(buckets);
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    bucketSort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%.6f ", arr[i]);

    return 0;
}