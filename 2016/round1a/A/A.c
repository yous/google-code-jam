#include <stdio.h>

int main() {
    int T;
    char S[1024];
    char buf[2048];
    int i, j;
    int start, end;

    scanf("%d%*c", &T);
    for (i = 1; i <= T; i++) {
        scanf("%s", S);

        start = end = 1024;
        buf[start] = S[0];
        for (j = 1; S[j] != '\0'; j++) {
            if (buf[start] > S[j]) {
                end++;
                buf[end] = S[j];
            } else if (buf[start] <= S[j]) {
                start--;
                buf[start] = S[j];
            }
        }
        buf[end + 1] = '\0';
        printf("Case #%d: %s\n", i, buf + start);
    }
    return 0;
}
