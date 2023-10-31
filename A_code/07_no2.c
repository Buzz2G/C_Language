#include <stdio.h>

int main() {
    int size;
    int no1 = 0;
    int no2 = 0;

    scanf("%d", &size);

    if (size >= 2) {
        scanf("%d", &no1);

        scanf("%d", &no2);

        if (no2 > no1) {
            int temp = no1;
            no1 = no2;
            no2 = temp;
        }

        for (int i = 0; i < size - 2; i++) {
            int temp;
            scanf("%d", &temp);

            if (temp > no1) {
                no2 = no1;
                no1 = temp;
            } else if (temp > no2) {
                no2 = temp;
            }
        }

        printf("%d\n", no2);
    } else {
        printf("Input size must be at least 2.\n");
    }

    return 0;
}
