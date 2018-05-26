#include <cstdio>

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < 2 * n - 1 - i; j++) {
                int temp = i % 2;
                if (j < i) {
                    printf(" ");
                } else {
                    if (j % 2 == temp) {
                        printf("*");
                    } else {
                        printf(" ");
                    }
                }
            }
            printf("\n");
        }
        for (int i = (n-1); i >= 0; i--) {
            for (int j = 0; j < 2 * n - 1 - i; j++) {
                int temp = i % 2;
                if (j < i) {
                    printf(" ");
                } else {
                    if (j % 2 == temp) {
                        printf("*");
                    } else {
                        printf(" ");
                    }
                }
            }
            printf("\n");
        }
    }

    return 0;
}