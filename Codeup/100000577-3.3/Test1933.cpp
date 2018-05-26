#include <cstdio>

int main() {

    int n;
    while (scanf("%d", &n) != EOF) {
        int m = n + (n - 1) * 2;
        int s = n;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j < m - s) {
                    printf(" ");
                } else {
                    printf("*");
                }
            }
            s += 2;
            printf("\n");
        }
    }


    return 0;
}