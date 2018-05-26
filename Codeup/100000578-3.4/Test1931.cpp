#include <cstdio>

bool isLeap(int y){
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int month[2][13]= {{0,31,28,31,30,31,30,31,31,30,31,30,31},
                   {0,31,29,31,30,31,30,31,31,30,31,30,31}};

int main() {
    int y, n;
    while (scanf("%d%d", &y, &n) != EOF) {
        int m = 1, d = 1;
        for (int i = 0; i < n - 1; i++) {
            int isleap = isLeap(y);
            d++;
            if (d > month[isleap][m]) {
                if (m != 12) {
                    m++;
                    d = 1;
                } else {
                    y++;
                    m = 1;
                    d = 1;
                }
            }
        }
        printf("%04d-%02d-%02d\n", y, m, d);
    }

    return 0;
}