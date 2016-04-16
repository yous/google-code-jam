#include <stdio.h>

int main() {
    int T, N;
    int heights[2500] = {0, };
    int height;
    int i, j;

    scanf("%d%*c", &T);
    scanf("%d%*c", &N);
    for (i = 1; i <= T; i++) {
        for (j = 0; j < (2 * N - 1) * N; j++) {
            scanf("%d%*c", &height);
            if (heights[height - 1]) {
                heights[height - 1]--;
            } else {
                heights[height - 1]++;
            }
        }
        printf("Case #%d:", i);
        for (j = 0; j < 2500; j++) {
            if (heights[j]) {
                printf(" %d", j + 1);
            }
        }
        printf("\n");
    }
    return 0;
}
