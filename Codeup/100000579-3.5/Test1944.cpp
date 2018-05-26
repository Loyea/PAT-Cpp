#include <cstdio>

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int a[255];
        int num = 0;
        do {
            a[num++] = n % 8;
            n /= 8;
        } while (n != 0);

        for (int i = num - 1; i >= 0; i--) {
            printf("%d", a[i]);
            if (i == 0) {
                printf("\n");
            }
        }

    }

    return 0;
}