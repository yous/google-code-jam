#include <stdio.h>
#include <string.h>

int main() {
    char buf[128];
    int T;
    int i;
    char *ch;
    char token;
    int counter;

    scanf("%d%*c", &T);
    for (i = 1; i <= T; i++) {
        fgets(buf, 128, stdin);

        counter = 0;
        buf[strcspn(buf, "\n")] = 0;
        token = buf[0];
        for (ch = buf; *ch != '\0'; ++ch) {
            if (*ch == token) {
                continue;
            }
            token = *ch;
            ++counter;
        }
        if (token == '-') {
            ++counter;
        }
        printf("Case #%d: %d\n", i, counter);
    }

    return 0;
}
