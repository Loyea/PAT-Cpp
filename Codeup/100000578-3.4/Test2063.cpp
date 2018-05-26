#include <cstdio>

bool isLeap(int y){
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int month[2][13]= {{0,31,28,31,30,31,30,31,31,30,31,30,31},
                   {0,31,29,31,30,31,30,31,31,30,31,30,31}};

int main() {

    int n;
    scanf("%d", &n);
    while (n--) {
        int y, m, d, s;
        scanf("%d%d%d%d", &y, &m, &d, &s);
        for (int i = 0; i < s; i++) {
            d++;
            int leap = isLeap(y);
            if (d > month[leap][m]) {
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