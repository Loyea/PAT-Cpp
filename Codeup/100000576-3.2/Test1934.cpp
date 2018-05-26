#include <cstdio>
#include <cstring>

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int ns[200];
        memset(ns, -1, sizeof(ns));
        int index = -1;
        int target, temp;
        for (int i = 0; i < n; i++) {
            scanf("%d", &temp);
            ns[i] = temp;
        }
        scanf("%d", &target);
        for (int i = 0; i < n; i++) {
            if (ns[i] == target) {
                index = i;
                break;
            }
        }
        printf("%d\n", index);
    }

    return 0;
}