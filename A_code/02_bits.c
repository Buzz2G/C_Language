#include <stdio.h>

int main() {
    // Read the decimal integer from the input
    int n = 0;
    int ch;

    // Read each character using getchar and convert to integer
    while ((ch = getchar()) != '\n') {
        n = n * 10 + (ch - '0');
    }

    // Calculate the binary value of the specified bits
    /*
    We can use '<<' or '>>' to shifts the binary representation of 1
    For example
    int seventh = (n & (1 << 2)) >> 2;

    '(1 << 2)'
    This results in 100 in binary, which corresponds to the 3rd bit (from the right) in a binary representation.
    And'&' is means (1111 & 100) this result is 0100
    '100 >> 2'
    It use the 3rd bit to shift to 1st, so the result is 1
    */
    int seventh = (n & (1 << 6)) >> 6;
    int fifth = (n & (1 << 4)) >> 4;
    int third = (n & (1 << 2)) >> 2;
    int first = (n & 1);

    // Calculate the decimal value using the specified bits
    int result = (seventh << 3) | (fifth << 2) | (third << 1) | first;

    // Print the result
    printf("%d\n", result);

    return 0;
}
