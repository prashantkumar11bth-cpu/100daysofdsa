#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct Node
{
    int data;
    struct Node *next;
};

// Function to create circular linked list
struct Node* createCLL(int n)
{
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    int value;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &value);

        // Dynamic memory allocation
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        // First node
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

    // Make list circular
    temp->next = head;

    return head;
}

// Function to traverse circular linked list
void traverseCLL(struct Node *head)
{
    if(head == NULL)
        return;

    struct Node *temp = head;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while(temp != head);   // Stop when we reach head again
}

// Main function
int main()
{
    int n;
    scanf("%d", &n);

    struct Node *head = createCLL(n);

    traverseCLL(head);

    return 0;
}