#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int isMirror(struct Node* t1, struct Node* t2){
    if(t1 == NULL && t2 == NULL)
        return 1;

    if(t1 == NULL || t2 == NULL)
        return 0;

    if(t1->data != t2->data)
        return 0;

    return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

int main(){
    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    if(arr[0] == -1){
        printf("NO");
        return 0;
    }

    struct Node* nodes[n];

    for(int i=0;i<n;i++){
        if(arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    for(int i=0;i<n;i++){
        if(nodes[i] != NULL){
            int left = 2*i + 1;
            int right = 2*i + 2;

            if(left < n)
                nodes[i]->left = nodes[left];

            if(right < n)
                nodes[i]->right = nodes[right];
        }
    }

    struct Node* root = nodes[0];

    if(isMirror(root->left, root->right))
        printf("YES");
    else
        printf("NO");

    return 0;
}