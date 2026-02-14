#include <stdio.h>

int main() {
    int m, n;

    // Read number of rows and columns
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    int sum = 0;

    // Input matrix elements
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check if matrix is square
    if(m != n) {
        printf("Primary diagonal not possible");
        return 0;
    }

    // Calculate sum of primary diagonal
    for(int i = 0; i < m; i++) {
        sum += matrix[i][i];
    }

    // Print result
    printf("%d", sum);

    return 0;
}
