#include <cstdio>

int main() {
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d);

    int x[255];

    int sum = a + b;
    int num = 0;
    do {
        x[num++] = sum % d;
        sum /= d;
    } while (sum != 0);

    for (int i = num - 1; i >= 0; i--) {
        printf("%d", x[i]);
    }

    return 0;
}