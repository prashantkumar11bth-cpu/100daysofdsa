#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0, count = 0;

    // Since constraints are unknown, assuming sum range small.
    // For large constraints, use unordered_map in C++.
    int freq[10001] = {0};   // Adjust size if needed
    int offset = 5000;       // To handle negative sums

    freq[offset] = 1;  // sum = 0 initially

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(freq[sum + offset] > 0) {
            count += freq[sum + offset];
        }

        freq[sum + offset]++;
    }

    printf("%d", count);

    return 0;
}