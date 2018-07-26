#include <cstdio>

int main() {
    int a, n;

    int result[1000];
    int length = 0;

    int input[1000];
    int len = 0;
    int temp;
    while (scanf("%d", &temp) != EOF) {
        input[len++] = temp;
    }


    int i = 0;
    while (i < len) {
        a = input[i++];
        n = input[i++];
        if (n > 0) {
            result[length++] = a * n;
            result[length++] = n - 1;
        }
    }

    if (length == 0) {
        printf("0 0");
        return 0;
    }

    for (int i = 0; i < length; i++) {
        printf("%d", result[i]);
        if (i != length - 1) {
            printf(" ");
        }
    }

    return 0;
}