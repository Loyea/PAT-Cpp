#include <cstdio>

int a[110];
int main() {

    int n, m;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            int temp, x = n;
            scanf("%d", &temp);
            for (int i = 0; i < n; i++) {
                if (a[i] == temp) {
                    x = j;
                    break;
                }
            }
            if (x < n) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }

    }

    return 0;
}