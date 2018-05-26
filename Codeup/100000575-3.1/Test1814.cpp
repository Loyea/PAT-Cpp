#include <stdio.h>
#include <cstring>

int max[10001];

int main() {
    int l, n, start, end;
    while (scanf("%d%d", &l, &n), l || n) {
        memset(max, -1, sizeof(max));
        while (n--) {
            scanf("%d%d", &start, &end);
            for (int i = start; i <= end; i++) {
                max[i] = 0;
            }
        }
        int sum = 0;
        for (int i = 0; i <= l; i++) {
            if (max[i]) {
                sum++;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}