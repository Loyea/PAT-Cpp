#include <cstdio>
#include <cstring>

int main() {

    char str[110] = " ";
    while (gets(str + 1)) {
        int len = strlen(str);
        for (int i = 1; i < len; i++) {
            char c1 = str[i - 1];
            char c2 = str[i];
            if ((c1 == ' ' || c1 == '\t' || c1 == '\r' || c1 == '\n') && c2 >= 'a' && c2 <= 'z') {
                str[i] = c2 - 'a' + 'A';
            }
        }
        puts(str + 1);
    }


    return 0;
}