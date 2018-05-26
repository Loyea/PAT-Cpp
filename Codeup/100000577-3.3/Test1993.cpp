#include <cstdio>
#include <cstring>

int main() {
    char str[255];
    while (scanf("%s", str) != EOF) {
        int n1, n2, n3;
        int len = strlen(str);
        n1 = n3 = (len + 2) / 3;
        n2 = len + 2 - n1 - n3;
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (i < n1 - 1) {
                    if (j == 0) {
                        printf("%c", str[i]);
                    } else if (j == n2 - 1) {
                        printf("%c", str[len - 1 - i]);
                    } else {
                        printf(" ");
                    }
                } else {
                    printf("%c", str[i + j]);
                }
                if (j == n2 - 1) {
                    printf("\n");
                }
            }
        }
    }

    return 0;
}