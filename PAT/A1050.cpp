#include <cstdio>
#include <cstring>

int main() {
    char a[10010], b[10010];
    bool flag[256] = {false};
    gets(a);
    gets(b);

    int len_b = strlen(b);
    for (int i = 0; i < len_b; i++) {
        int index = b[i];
        flag[index] = true;
    }

    int len_a = strlen(a);
    for (int i = 0; i < len_a; i++) {
        int index = a[i];
        if (!flag[index]) {
            printf("%c", a[i]);
        }
    }

    return 0;
}