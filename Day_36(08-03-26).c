#include <stdio.h>

int main() {
    int n, m;

    scanf("%d", &n);

    int q[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }

    scanf("%d", &m);

    int front = 0;
    int rear = n - 1;

    for(int i = 0; i < m; i++) {

        int temp = q[front];           // dequeue
        front = (front + 1) % n;

        rear = (rear + 1) % n;         // enqueue again
        q[rear] = temp;
    }

    int i = front;

    while(1) {
        printf("%d ", q[i]);

        if(i == rear)
            break;

        i = (i + 1) % n;
    }

    return 0;
}