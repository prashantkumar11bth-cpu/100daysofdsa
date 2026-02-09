#include <stdio.h>

int main() {
    char str[1000];
    scanf("%s", str);

    int len = 0;

    // find length manually
    while (str[len] != '\0') {
        len++;
    }

    int left = 0;
    int right = len - 1;

    // reverse using two-pointer swap
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++;
        right--;
    }

    printf("%s", str);
    return 0;
}
