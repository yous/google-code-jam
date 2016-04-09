#include <stdio.h>

void mask_digits(int number, int *mask) {
    while (number) {
        *mask |= 1 << (number % 10);
        number /= 10;
    }
}

int main() {
    int T;
    int N;
    int i;
    int number;
    int mask;

    scanf("%d", &T);
    for (i = 1; i <= T; i++) {
        scanf("%d", &N);
        if (N == 0) {
            printf("Case #%d: INSOMNIA\n", i);
            continue;
        }
        number = N;
        mask = 0;
        mask_digits(number, &mask);
        while (mask != 0x3ff) {
            number += N;
            mask_digits(number, &mask);
        }
        printf("Case #%d: %d\n", i, number);
    }
    return 0;
}
