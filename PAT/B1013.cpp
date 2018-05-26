#include <stdio.h>

bool isPrime(int n) {
    if (n == 2) {
        return true;    //2 is a special prime num.
    }
    if (n % 2 == 0 || n < 2) {  // 1 is not a prime num.
        return false;
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {

    int start, des;
    int index = 0;

    scanf("%d %d", &start, &des);

    for (int i = 1; true; i++) {
        if (isPrime(i)) {
            index++;
            if (index >= start && index <= des) {
                printf("%d", i);
                if (index != des) {
                    if ((index - start + 1) % 10 == 0) {
                        printf("\n");
                    } else {
                        printf(" ");
                    }
                } else {
                    return 0;
                }

            }
        }
    }
}