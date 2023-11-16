#include <stdio.h>

struct Node{
    int x;
    int y;
};

int isvowel(char c) {
    c = tolower(c);
    switch(c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return 1;
        default:
            return 0;
    }
}

int main() {
    struct Node node01 = {0 , 0};
    struct Node node02 = {0 , 0};
    char code[98];
    int index;

    fgets(code, sizeof(code), stdin);  // 从标准输入读取一行字符串

    for (index = 0; code[index] != '\0'; index++) {
        if (code[index] == ' ') {
            node01 = node02;
        } else if (isupper(code[index])) {
            printf("%d %d\n", node01.x, node01.y);
            return 0;
        } else {
            node02 =node01;
            if (isvowel(code[index])) {
                node01.x++;
            } else {
                node01.y++;
            }
        }

    }
    printf("error\n");
    return 0;
}
