#include <cstdio>

int main() {

    long long m, a, b;
    while (scanf("%lld", &m), m != 0) {
        scanf("%lld%lld", &a, &b);
        long long sum = a + b;
        int x[1024];
        int n = 0;
        do {
            x[n++] = sum % m;
            sum /= m;
        } while (sum != 0);
        for (int i = n - 1; i >= 0; i--) {
            printf("%d", x[i]);
            if (i == 0) {
                printf("\n");
            }
        }
    }

    return 0;
}