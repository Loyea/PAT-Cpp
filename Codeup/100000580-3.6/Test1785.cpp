#include <cstdio>

int main() {
    char a[110] = "";
    char b[110] = "";
    while (scanf("%s %s", a, b) != EOF) {
        printf("%s%s\n", a, b);
    }

    return 0;
}