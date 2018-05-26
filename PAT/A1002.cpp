#include <cstdio>

int main() {
    double sum[1010] = {0};

    int n = 2;
    while (n--) {
        int m;
        scanf("%d", &m);
        while (m--) {
            int exp;
            double coe;
            scanf("%d %lf", &exp, &coe);
            sum[exp] = sum[exp] + coe;
        }
    }

    int count = 0;
    for (int i = 0; i < 1010; i++) {
        if (sum[i] != 0) {
            count++;
        }
    }

    printf("%d", count);
    for (int i = 1009; i >= 0; i--) {
        if (sum[i] != 0) {
            printf(" %d %.1f", i, sum[i]);
        }
    }

    return 0;
}