#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Create Linked List
struct Node* createList(int n)
{
    struct Node *head = NULL, *temp = NULL, *newNode;
    int value;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Rotate Right by k places
struct Node* rotateRight(struct Node* head, int k)
{
    if(head == NULL || head->next == NULL || k == 0)
        return head;

    struct Node *temp = head;
    int n = 1;

    // Find length and last node
    while(temp->next != NULL)
    {
        temp = temp->next;
        n++;
    }

    // Make circular list
    temp->next = head;

    k = k % n;        // handle k > n
    int steps = n - k;

    struct Node *newTail = head;

    // Move to (n-k)th node
    for(int i = 1; i < steps; i++)
        newTail = newTail->next;

    struct Node *newHead = newTail->next;

    // Break circular link
    newTail->next = NULL;

    return newHead;
}

// Display list
void display(struct Node *head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

// Main function
int main()
{
    int n, k;

    scanf("%d", &n);

    struct Node *head = createList(n);

    scanf("%d", &k);

    head = rotateRight(head, k);

    display(head);

    return 0;
}