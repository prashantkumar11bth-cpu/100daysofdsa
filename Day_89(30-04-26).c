#include <stdio.h>

// Function to check if allocation is possible
int isPossible(int arr[], int n, int m, int maxPages) {
    int studentCount = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (currentSum + arr[i] <= maxPages) {
            currentSum += arr[i];
        } else {
            studentCount++;
            currentSum = arr[i];

            if (studentCount > m)
                return 0; // Not possible
        }
    }
    return 1; // Possible
}

// Function to allocate books
int allocateBooks(int arr[], int n, int m) {
    if (m > n) return -1;

    int max = arr[0], sum = 0;

    // Find max and sum
    for (int i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        sum += arr[i];
    }

    int low = max, high = sum, ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1; // try smaller value
        } else {
            low = mid + 1; // increase limit
        }
    }

    return ans;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", allocateBooks(arr, n, m));

    return 0;
}