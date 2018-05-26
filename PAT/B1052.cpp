#include <cstdio>
#include <cstring>

int main() {
    char a[3][11][17];
    int an = 0, bn = 0, cn = 0;

    for(int i = 0; i < 3; i++) {
        char temp[255];
        gets(temp);
        int len = strlen(temp);
        bool flag = false;
        int count = 0, temp_size = 0;
        for (int j = 0; j < len; j++) {
            char c = temp[j];
            if (c == '[') {
                flag = true;
            } else if (c == ']') {
                flag = false;
                count++;
                temp_size = 0;
            } else {
                if (flag) {
                    a[i][count][temp_size] = c;
                    a[i][count][temp_size + 1] = 0;
                    temp_size++;
                }
            }
        }

        if (i == 0) {
            an = count;
        } else if (i == 1) {
            bn = count;
        } else {
            cn = count;
        }

    }

    int n;
    scanf("%d", &n);
    while(n--){
        int lh, le, m, re, rh;
        scanf("%d%d%d%d%d", &lh, &le, &m, &re, &rh);
        if((lh > 0 && lh <= an) && (rh > 0 && rh <= an) && (le > 0 && le <= bn) && (re > 0 && re <= bn) && (m > 0 && m <= cn)){
            printf("%s(%s%s%s)%s\n", a[0][lh - 1], a[1][le - 1], a[2][m - 1], a[1][re - 1], a[0][rh - 1]);
        } else {
            printf("Are you kidding me? @\\/@\n");
        }
    }

    return 0;
}