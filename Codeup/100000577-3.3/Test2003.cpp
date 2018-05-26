#include <cstdio>

int main() {

    int n;
    scanf("%d", &n);
    while (n--) {
        int h;
        scanf("%d", &h);
        int h2 = h + (h - 1) * 2;
        for (int i = 0; i < h; i++) {
            int star, blank;
            star = h + 2 * i;
            blank = h2 - star;
            int temp = blank / 2;
            for (int j = 0; j < h2; j++) {
                if (j < temp || h2 - j <= temp) {
                    printf(" ");
                } else {
                    printf("*");
                }
            }
            printf("\n");
        }
    }

    return 0;
}