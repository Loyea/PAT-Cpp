#include <cstdio>
#include <cstring>
#include <cmath>

int parseStrToInt(char a[]){
    int x = 0, position = 0;
    for (int i = strlen(a) - 1; i >= 0; i--) {
        if (a[i] == ',') {
            continue;
        }
        if (a[i] >= '0' && a[i] <= '9') {
            int current = a[i] - '0';
            x = x + current * pow(10, position);
            position++;
        }
        if (a[i] == '-') {
            x = -x;
        }
    }
    return x;
}

int main() {

    char a[15], b[15];
    while (scanf("%s %s", a, b) != EOF) {
        printf("%d\n", parseStrToInt(a)+parseStrToInt(b));
    }
    return 0;
}