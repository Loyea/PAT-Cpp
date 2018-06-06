#include <cstdio>

int main() {

    int n;
    double m[100010];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &m[i]);
    }

    double result = 0;
    for (int i = 0; i < n; i++) {
        result += (double)(i + 1) * (double)(n - i) * m[i];
    }

    printf("%.2f", result);

    return 0;
}