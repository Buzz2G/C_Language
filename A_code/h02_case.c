#include <stdio.h>

int main() {
    char c;
    scanf("%c", &c);

    if (c >= 'A' && c <= 'Z') {
        // If the character is an uppercase letter
        if (c == 'Z') {
            // Handle the special case for 'Z'
            printf("A\n");
        } else {
            // Print the next uppercase character
            printf("%c\n", c + 1);
        }
    } else if (c >= 'a' && c <= 'z') {
        // If the character is a lowercase letter
        if (c == 'a') {
            // Handle the special case for 'a'
            printf("z\n");
        } else {
            // Print the previous lowercase character
            printf("%c\n", c - 1);
        }
    } else {
        // If it's not a letter, just print the character itself
        printf("%c\n", c);
    }

    return 0;
}
