#include <cstdio>

int main() {

    int m, n, a, b, x;
    scanf("%d%d%d%d%d", &m, &n, &a, &b, &x);
    while (m--) {
        int l = n;
        while (l--) {
            int temp;
            scanf("%d", &temp);
            if (temp >=a && temp <= b) {
                printf("%03d", x);
            } else {
                printf("%03d", temp);
            }
            if (l == 0) {
                printf("\n");
            } else {
                printf(" ");
            }
        }
    }

    return 0;
}