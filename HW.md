2:bit .c读取一个两位数的十进制整数n，并打印由n的二进制表示的第7、5、3和1位组成的二进制数的十进制值。位位从LSB开始计数，即LSB是二进制表示的第一个位。

例如，给定n = 75, n的二进制表示形式为1001011。因为第7位、第5位、第3位和第1位分别是1、0、0和1，你的程序应该输出9。如果你找不到n的二进制表示的任何位，你应该假设对应的位是0，因为它确实适用于数字，比如1100等于0001100。输入由单行组成，其中包含两个十进制数字的十进制整数n (9 <n < 100)。你的程序应该将n的二进制表示的奇数位组成的数字打印到标准输出。额外加分要求:你的程序文件应该命名为Bits.c如本节标题所述。不要使用scanf，而是使用getchar。

```c
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

```

字符回圈
```c
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

```