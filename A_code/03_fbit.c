#include <stdio.h>
#include <math.h>

void floatToBinaryFraction(double f, int n) {
    int i;
    printf("0.");

    for (i = 0; i < n; i++) {
        f *= 2;
        if (f >= 1.0) {
            printf("1");
            f -= 1.0;
        } else {
            printf("0");
        }
    }

    printf("\n");
}

int main() {
    int n;
    double f;

    // Input
    scanf("%d", &n);
    scanf("%lf", &f);

    // Check if the input is valid
    if (0.0 < f && f < 1.0 && n > 0) {
        floatToBinaryFraction(f, n);
    } else {
        printf("Invalid input. Please make sure 0 < f < 1 and n > 0.\n");
    }

    return 0;
}
