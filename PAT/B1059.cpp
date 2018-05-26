#include <cstdio>

bool isPrime(int n) {
    if (n == 2) {   //2 is a special prime number.
        return true;
    }
    if (n % 2 == 0 || n < 2) {
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
    int id[10010] = {0};
    int checkedSize = 0;
    int checkedId[10010] = {0};

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &id[i]);
    }

    int k;
    scanf("%d", &k);
    while (k--) {
        int temp;
        scanf("%d", &temp);
        bool checked = false;
        for (int i = 0; i < checkedSize; i++) {
            if (checkedId[i] == temp) {
                checked = true;
                break;
            }
        }
        if (checked) {
            printf("%04d: Checked\n", temp);
        } else {
            bool found = false;
            int index = 0;
            for (int i = 0; i < n; i++) {
                if (id[i] == temp) {
                    found = true;
                    index = i;
                    break;
                }
            }
            if (found) {
                checkedId[checkedSize++] = temp;
                if (index + 1 == 1) {
                    printf("%04d: Mystery Award\n", temp);
                } else {
                    if (isPrime(index + 1)) {
                        printf("%04d: Minion\n", temp);
                    } else {
                        printf("%04d: Chocolate\n", temp);
                    }
                }
            } else {
                printf("%04d: Are you kidding?\n", temp);
            }
        }
    }

    return 0;
}