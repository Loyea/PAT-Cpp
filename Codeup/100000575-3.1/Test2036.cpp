#include <cstdio>

int main() {

    int a;
    while (scanf("%d", &a) != EOF) {
        int even = 0, odd = 0;
        while (a--) {
            int temp;
            scanf("%d", &temp);
            if (temp % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        if (even > odd) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }

    return 0;
}