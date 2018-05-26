#include <cstdio>

int month[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};

int main() {

    int n;
    scanf("%d", &n);
    while (n--) {
        int y, m, d;
        scanf("%d %d %d", &y, &m, &d);
        d++;
        if (d > month[m]) {
            if (m != 12) {
                m++;
                d = 1;
            } else {
                y++;
                m = 1;
                d = 1;
            }
        }
        printf("%04d-%02d-%02d\n", y, m, d);
    }

    return 0;
}