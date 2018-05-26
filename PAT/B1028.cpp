#include <cstdio>
#include <cstring>

int date_cmp(int y1, int m1, int d1, int y2, int m2, int d2) {
    if (y1 != y2) {
        return y1 - y2;
    } else {
        if (m1 != m2) {
            return m1 - m2;
        } else {
            return d1 - d2;
        }
    }
}

int main() {

    int n;
    scanf("%d", &n);

    char names[100010][6];

    char name[6];
    int y, m, d;
    char maxname[6], minname[6];
    int maxy, maxm, maxd;
    int miny, minm, mind;
    int count = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s %d/%d/%d", name, &y, &m, &d);
        if (date_cmp(y, m, d, 1814, 9, 6) >= 0 && date_cmp(y, m, d, 2014, 9, 6) <= 0) {
            count++;
            if (i == 0) {
                maxy = miny = y;
                maxm = minm = m;
                maxd = mind = d;
                strcpy(maxname, name);
                strcpy(minname, name);
            }

            if (date_cmp(y, m, d, maxy, maxm, maxd) < 0) {
                maxy = y;
                maxm = m;
                maxd = d;
                strcpy(maxname, name);
            }

            if (date_cmp(y, m, d, miny, minm, mind) > 0) {
                miny = y;
                minm = m;
                mind = d;
                strcpy(minname, name);
            }
        }
    }

    if (count != 0) {
        printf("%d %s %s", count, maxname, minname);
    } else {
        printf("0");
    }

    return 0;
}