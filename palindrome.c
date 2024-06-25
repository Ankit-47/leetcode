#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    // Negative numbers are not palindromes
    if (x < 0) {
        return false;
    }
    
    // Special case: single digit numbers are palindromes
    if (x >= 0 && x < 10) {
        return true;
    }

    // Calculate the divisor to extract the most significant digit
    int divisor = 1;
    while (x / divisor >= 10) {
        divisor *= 10;
    }

    while (x != 0) {
        int leading = x / divisor;
        int trailing = x % 10;

        // If leading and trailing digits do not match, it's not a palindrome
        if (leading != trailing) {
            return false;
        }

        // Remove the leading and trailing digits and adjust divisor
        x = (x % divisor) / 10;
        divisor /= 100;  // Two digits removed
    }

    return true;
}

int main() {
    int num = 121;

    if (isPalindrome(num)) {
        printf("%d is a palindrome.\n", num);
    } else {
        printf("%d is not a palindrome.\n", num);
    }

    return 0;
}
