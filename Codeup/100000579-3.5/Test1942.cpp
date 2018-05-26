#include <cstdio>
#include <cstring>

int parse(char c){
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 10;
    }
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 10;
    }
}

char convert(int n){
    if (n >= 0 && n <= 9) {
        return '0' + n;
    }
    if (n > 9) {
        return n - 10 + 'A';
    }
}

int main() {

    int a, b;
    char n[255];
    while (scanf("%d%s%d", &a, n, &b) != EOF) {
        long long nIn10 = 0;
        int len = strlen(n);
        int p = 1;
        for (int i = len - 1; i >= 0; i--) {
            nIn10 += parse(n[i]) * p;
            p *= a;
        }

        char result[255];
        int num = 0;
        do {
            result[num++] = convert(nIn10 % b);
            nIn10 /= b;
        } while (nIn10 != 0);
        for (int i = num - 1; i >= 0; i--) {
            printf("%c", result[i]);
            if (i == 0) {
                printf("\n");
            }
        }
    }


    return 0;
}