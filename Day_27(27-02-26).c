#include <stdio.h>
#include <stdlib.h>

/* Structure of Node */
struct Node {
    int data;
    struct Node* next;
};

/* Function to create list */
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int value;

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL)
            head = newNode;
        else
            temp->next = newNode;

        temp = newNode;
    }
    return head;
}

/* Function to find length */
int getLength(struct Node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

/* Function to find intersection */
int findIntersection(struct Node* head1, struct Node* head2) {

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff;

    /* Move pointer of longer list */
    if(len1 > len2) {
        diff = len1 - len2;
        for(int i = 0; i < diff; i++)
            head1 = head1->next;
    }
    else {
        diff = len2 - len1;
        for(int i = 0; i < diff; i++)
            head2 = head2->next;
    }

    /* Traverse together */
    while(head1 != NULL && head2 != NULL) {
        if(head1->data == head2->data)
            return head1->data;

        head1 = head1->next;
        head2 = head2->next;
    }

    return -1;
}

/* Main Function */
int main() {

    int n, m;

    scanf("%d", &n);
    struct Node* list1 = createList(n);

    scanf("%d", &m);
    struct Node* list2 = createList(m);

    int result = findIntersection(list1, list2);

    if(result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}