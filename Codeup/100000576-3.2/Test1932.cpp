#include <cstdio>

int s[1010] = {0};
int main() {

    int n;
    while (scanf("%d", &n), n) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &s[i]);
        }
        int target, count = 0;
        scanf("%d", &target);
        for (int i = 0; i < n; i++) {
            if (s[i] == target) {
                count++;
            }
        }
        printf("%d\n", count);
    }

    return 0;
}