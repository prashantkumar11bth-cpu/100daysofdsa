#include <stdio.h>

int main() {
    char s[200];
    int len = 0;

    // Read string
    scanf("%s", s);

    // Find length manually
    while (s[len] != '\0') {
        len++;
    }

    int left = 0;
    int right = len - 1;
    int isPalindrome = 1;

    // Two-pointer check
    while (left < right) {
        if (s[left] != s[right]) {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome)
        printf("YES");
    else
        printf("NO");

    return 0;
}
