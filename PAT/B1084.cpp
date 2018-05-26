#include <cstdio>
#include <cstring>

const int maxn = 1000000;

int main() {
    char d[maxn] = "";
    int n;
    scanf("%s%d", d, &n);

    for (int i = 0; i < n - 1; i++) {
        char temp[maxn] = "";
        int num = 0;
        int len = strlen(d);
        char current_c = 0;
        int crt_char_count = 0;
        for (int j = 0; j < len; j++) {
            if (d[j] != current_c) {
                current_c = d[j];
                if (crt_char_count != 0) {
                    temp[num++] = crt_char_count + '0';
                }
                temp[num++] = current_c;
                crt_char_count = 1;
            } else {
                crt_char_count++;
            }
            if (j == len - 1) {
                temp[num++] = crt_char_count + '0';
            }
        }
        strcpy(d, temp);
    }

    puts(d);

    return 0;
}