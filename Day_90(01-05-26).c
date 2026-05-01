#include <stdio.h>

// Function to check if it is possible to paint with given maxTime
int isPossible(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currSum = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime)
            return 0;

        if (currSum + boards[i] <= maxTime) {
            currSum += boards[i];
        } else {
            painters++;
            currSum = boards[i];

            if (painters > k)
                return 0;
        }
    }
    return 1;
}

// Function to find minimum time
int minTime(int boards[], int n, int k) {
    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        sum += boards[i];
        if (boards[i] > max)
            max = boards[i];
    }

    int low = max;
    int high = sum;
    int result = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(boards, n, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int n, k;

    printf("Enter number of boards and painters: ");
    scanf("%d %d", &n, &k);

    int boards[n];

    printf("Enter board lengths:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    int answer = minTime(boards, n, k);

    printf("Minimum time required = %d\n", answer);

    return 0;
}