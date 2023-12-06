#include <stdio.h>
#include <string.h>

#define SWAPCHAR(a, b) do { char temp = (a); (a) = (b); (b) = temp; } while(0)

#define MAX 256

char* revstr(char *s) {
    int len = strlen(s);
    int top = 0, end = len - 1;

    while (top < end) {
        SWAPCHAR(s[top], s[end]);

        top++;
        end--;
    }

    return s;
}

int main() {
    char line[MAX];
    char word[MAX];
    int count = 0;

    // Use fgets to read
    fgets(line, MAX, stdin);

    // Read words
    for (int i = 0; line[i] != '\0'; i++) {
        // 字符串拼接
        if ((line[i] >= 'a' && line[i] <= 'z') ||
            (line[i] >= 'A' && line[i] <= 'Z') ||
            (line[i] >= '0' && line[i] <= '9')
            ) {
            word[count] = line[i];
            count++;
            word[count] = '\0';
        }

        if (line[i + 1] == ' ' || line[i + 1] == '\0') {
            // 反转字符串并打印
            // 使用 revstr 函数反转字符串
            revstr(word);
            printf("%s ", word);
            word[0] = '\0';
            count = 0;
        }
    }

    return 0;
}
