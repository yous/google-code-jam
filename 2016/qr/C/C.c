#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#define PRIME_COUNT 1000

int primes[PRIME_COUNT] = {2, };

void gen_primes() {
    int n;
    int i, j;
    int is_prime;
    double n_sqrt;

    n = 3;
    i = 1;
    while (i < PRIME_COUNT) {
        n_sqrt = sqrt(n);
        is_prime = 1;
        for (j = 0; j < i; ++j) {
            if (primes[i] > n_sqrt) {
                break;
            }
            if (n % primes[j] == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            primes[i] = n;
            ++i;
        }
        ++n;
    }
}

int *bin_divmod(uint32_t bits, int base, int div) {
    int *divmod = (int *) malloc(sizeof(int) * 2);
    int i;

    divmod[0] = divmod[1] = 0;
    for (i = 31; i >= 0; --i) {
        divmod[1] = divmod[1] * base + ((bits >> i) & 0x1);
        divmod[0] = divmod[0] * base + divmod[1] / div;
        divmod[1] %= div;
    }
    return divmod;
}

int prime_factor(uint32_t bits, int base) {
    int *divmod;
    int i;
    for (i = 0; i < PRIME_COUNT; ++i) {
        divmod = bin_divmod(bits, base, primes[i]);
        if (divmod[1] == 0) {
            free(divmod);
            return primes[i];
        }
        free(divmod);
    }
    return -1;
}

void print_bits(uint32_t bits) {
    int printing = 0;
    int i;
    for (i = 31; i >= 0; --i) {
        if (!printing) {
            if (((bits >> i) & 0x1) == 1) {
                printing = 1;
            }
        }
        if (printing) {
            printf("%d", (bits >> i) & 0x1);
        }
    }
}

int main() {
    int T, N, J;
    int i, base;
    uint32_t bits;
    int factor[9];
    int is_prime;

    gen_primes();

    scanf("%d", &T);
    for (i = 1; i <= T; ++i) {
        scanf("%d %d", &N, &J);

        bits = (1 << (N - 1)) + 1;
        printf("Case #%d:\n", i);
        while (J) {
            is_prime = 0;
            for (base = 2; base <= 10; ++base) {
                factor[base - 2] = prime_factor(bits, base);
                if (factor[base - 2] == -1) {
                    is_prime = 1;
                    break;
                }
            }
            if (!is_prime) {
                print_bits(bits);
                for (base = 2; base < 10; ++base) {
                    printf(" %d", factor[base - 2]);
                }
                printf(" %d\n", factor[10 - 2]);
                --J;
            }
            bits += 2;
        }
    }
    return 0;
}
