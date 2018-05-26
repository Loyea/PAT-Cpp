#include <cstring>
#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    int index, acount, bcount, ccount;
    bool p, t;
    for (int i = 0; i < n; i++) {
        char temp[101];
        scanf("%s", temp);
        int len = strlen(temp);
        index = acount = bcount = ccount = 0;
        p = t = false;

        for (int j = 0; j < len; j++) {
            char c = temp[j];

            if (c == 'P') {
                if (!p) {
                    p = true;
                } else {
                    printf("NO\n");
                    break;
                }
            } else if (c == 'A') {
                if (!p && !t) {
                    acount++;
                } else if (p && !t) {
                    bcount++;
                } else {
                    ccount++;
                }
            } else if (c == 'T') {
                if (!t) {
                    t = true;
                } else {
                    printf("NO\n");
                    break;
                }
            } else {
                printf("NO\n");
                break;
            }

            if ((j == len - 1)) {
                if (p && t && (ccount - acount * bcount == 0) && bcount > 0) {
                    printf("YES\n");
                } else {
                    printf("NO\n");
                }
            }
        }

    }
    return 0;
}