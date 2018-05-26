#include <stdio.h>

int main() {
    char str[100];
    gets(str);
    for (int i = 0; str[i]; i++) {
        char a = str[i];
        if (a >= 'A' && a <= 'Z') {
            printf("%c", 26 - (a - 'A') + 'A' - 1);
        } else if (a >= 'a' && a <= 'z') {
            printf("%c", 26 - (a - 'a') + 'a' - 1);
        } else {
            printf("%c", a);
        }
    }

    return 0;
}