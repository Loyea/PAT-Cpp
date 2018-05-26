#include <cstdio>

int calc(int n, int b, int result[]) {
    int num = 0;
    do {
        result[num++] = n % b;
        n = n / b;
    } while (n != 0);
    return num;
}

int main() {
    int n, b;
    scanf("%d%d", &n, &b);

    int result[10000];

    int num = calc(n, b, result);

    bool flag = true;
    for (int i = 0; i < num / 2; i++) {
        if (result[i] != result[num - 1 - i]) {
            flag = false;
        }
    }

    if (flag) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    for (int i = num - 1; i >= 0; i--) {
        printf("%d", result[i]);
        if (i != 0) {
            printf(" ");
        }
    }

    return 0;
}