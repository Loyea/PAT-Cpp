#include <stdio.h>

int main() {

    int a;
    while (scanf("%d", &a), a) {
        int sum = 0;
        while (a--) {
            int temp;
            scanf("%d", &temp);
            sum += temp;
        }
        printf("%d\n", sum);
    }

    return 0;
}