#include <cstdio>

int main() {
    int n, m[100010];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &m[i]);
    }

    int last_floor = 0, result = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            last_floor = 0;
        } else {
            last_floor = m[i - 1];
        }

        int temp = m[i] - last_floor;

        if (temp > 0) {
            result += temp * 6 + 5;
        } else if (temp < 0) {
            result += -1 * temp * 4 + 5;
        } else {
            result += 5;
        }

    }

    printf("%d", result);


    return 0;
}