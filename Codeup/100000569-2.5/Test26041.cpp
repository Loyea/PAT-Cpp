#include <stdio.h>

int main() {

    int n ;
    scanf("%d", &n);
    int a[10][10] = {};

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (j == 0 || j == i - 1) {
                a[i-1][j] = 1;
                printf("%d", 1);
            } else {
                a[i - 1][j] = a[i - 2][j - 1] + a[i - 2][j];
                printf("%d", a[i - 1][j]);
            }
            if (j != i - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }



    return 0;
}