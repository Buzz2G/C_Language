#include <stdio.h>

int main() {
    int n;
    //In c, we can use if(test = 1) to determine text is executed successfully
    if (scanf("%d", &n) == 1) {
            printf("%d\n", n+1);
    } else {
            printf("NaN\n");
    }
    return 0;
}
