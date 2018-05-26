#include <cstdio>
#include <cstring>

int calc(char a[], char b[]){
    int sum = 0;
    for (int i = 0; i < strlen(a); i++) {
        for (int j = 0; j < strlen(b); j++) {
            int x = a[i] - '0';
            int y = b[j] - '0';
            sum += x * y;
        }
    }
    return sum;
}

int main() {

    char a[15], b[15];
    while (scanf("%s %s", a, b) != EOF) {
        printf("%d\n", calc(a, b));
    }

    return 0;
}