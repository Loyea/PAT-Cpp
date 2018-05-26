#include <stdio.h>

int main() {

    int a;
    scanf("%d", &a);
    while (a--) {
        int b, sum = 0;
        scanf("%d", &b);
        while (b--) {
            int temp;
            scanf("%d", &temp);
            sum += temp;
        }
        printf("%d\n", sum);
    }

    return 0;
}