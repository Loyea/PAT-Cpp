#include <cstdio>

long long a[1000010], b[1000010], temp[2000020];

int main() {
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
    }

    int sum = n + m;

    int target_index = (sum - 1) / 2;


    int i = 0, j = 0, index = 0;
    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            temp[index++] = a[i++];
        } else {
            temp[index++] = b[j++];
        }

    }

    while (i < n) {
        temp[index++] = a[i++];
    }

    while (j < m) {
        temp[index++] = b[j++];
    }

    printf("%lld", temp[target_index]);


    return 0;
}