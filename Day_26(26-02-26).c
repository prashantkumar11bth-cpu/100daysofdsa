#include <stdio.h>
#include <stdlib.h>

// Structure of Doubly Linked List Node
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function to insert node at end
struct Node* insertAtEnd(struct Node *head, int data) {
    struct Node *newNode, *temp;

    // Allocate memory
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    // If list is empty
    if (head == NULL) {
        return newNode;
    }

    // Traverse to last node
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Link new node
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Function to print list in forward direction
void traverseForward(struct Node *head) {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, value;
    struct Node *head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }

    traverseForward(head);

    return 0;
}