#include <stdio.h>

int zeroCount = 0, oneCount = 0;

void counter(int x) {
    int a = x / 2;
    int b = x % 2;
    if (a == 0) {
    } else {
        counter(a);
    }
    if (b) {
        oneCount++;
    } else {
        zeroCount++;
    }
}

int main(){

    int sum = 0;

    while (1) {
        char c = getchar();
        if (c == '\n') {
            break;
        }

        if (c >= 'a' && c <= 'z') {
            sum += c - 'a' + 1;
        }

        if (c >= 'A' && c <= 'Z') {
            sum += c - 'A' + 1;
        }

    }

    if (!sum) {
        printf("0 0");
        return 0;
    }

    counter(sum);

    printf("%d %d", zeroCount, oneCount);

    return 0;
}