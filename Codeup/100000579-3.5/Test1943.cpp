#include <cstdio>
#include <cstring>

void largeDivide(char dividend[], char quotient[], int* reminder){
    int len = strlen(dividend);
    int stay = 0;
    int num = 0;
    for (int i = 0; i < len; i++) {
        int currentDigit = dividend[i] - '0';
        int q = (stay * 10 + currentDigit) / 2;
        if (q == 0) {
            if (len == 1) {
                quotient[num++] = q + '0';
            } else {
                if (num != 0) {
                    quotient[num++] = q + '0';
                }
            }
        } else {
            quotient[num++] = q + '0';
        }

        stay = (stay * 10 + currentDigit) % 2;
    }
    *reminder = stay;
}

int main() {
    char n[1024];
    while (scanf("%s", n) != EOF) {
        int reminder;
        char result[1024];
        int num = 0;
        do {
            char quotient[1024] = "";
            largeDivide(n, quotient, &reminder);
            result[num++] = reminder + '0';
            strcpy(n, quotient);
        } while (strcmp("0", n));

        for (int i = num - 1; i >= 0; i--) {
            printf("%c", result[i]);
            if (i == 0) {
                printf("\n");
            }
        }

    }

    return 0;
}