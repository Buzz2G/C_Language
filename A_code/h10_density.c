#include <stdio.h>

int main() {
    int col;
    int row = 0;
    int c = 0;
    int count = 0;

    scanf("%d", &col);

    for (int i = 0; i < 1 + col; i++) {
        while (1) {
            char in = getchar();
            if (in == '\n' || in == EOF) {
                break;
            }
            if (in != ' ') {
                c++;
            }
            count++;
        }

        if (count > row) {
            row = count;
        }
        count = 0;
    }

    printf("%.2f", (double)c * 100 / (col * row));

    return 0;
}
