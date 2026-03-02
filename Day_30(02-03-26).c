#include<stdio.h>
#include<stdlib.h>

/* Structure for Polynomial Node */
struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};

/* Function to create polynomial */
struct Node* createPolynomial(int n)
{
    struct Node *head = NULL, *temp = NULL, *newNode;
    int c, e;

    for(int i = 0; i < n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &c, &e);

        newNode->coeff = c;
        newNode->exp = e;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

/* Function to display polynomial */
void displayPolynomial(struct Node *head)
{
    struct Node *temp = head;

    while(temp != NULL)
    {
        if(temp->exp == 0)
            printf("%d", temp->coeff);
        else if(temp->exp == 1)
            printf("%dx", temp->coeff);
        else
            printf("%dx^%d", temp->coeff, temp->exp);

        if(temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
}

/* Main Function */
int main()
{
    int n;
    struct Node *poly;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    poly = createPolynomial(n);

    printf("\nPolynomial:\n");
    displayPolynomial(poly);

    return 0;
}
